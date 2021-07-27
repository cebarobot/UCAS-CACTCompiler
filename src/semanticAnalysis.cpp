#include "semanticAnalysis.h"
#include <iostream>

SemanticAnalysis::SemanticAnalysis(BlockInfo * globalBlock, IRGenerator * newIRGen)
: globalBlock(globalBlock), currentBlock(globalBlock), currentSymbol(nullptr), 
    currentFunc(nullptr), currentDataType(DataType::VOID),
    irGen(newIRGen) {}

void SemanticAnalysis::enterCompUnit(CACTParser::CompUnitContext * ctx) {
    // add build-in functions
    FuncSymbolInfo * printBoolFunc = globalBlock->addNewFunc("print_bool", DataType::VOID);
    printBoolFunc->addParamVar("value", DataType::BOOL);
    printBoolFunc->calcParamNum();
    FuncSymbolInfo * printIntFunc = globalBlock->addNewFunc("print_int", DataType::VOID);
    printIntFunc->addParamVar("value", DataType::INT);
    printIntFunc->calcParamNum();
    FuncSymbolInfo * printFloatFunc = globalBlock->addNewFunc("print_float", DataType::VOID);
    printFloatFunc->addParamVar("value", DataType::FLOAT);
    printFloatFunc->calcParamNum();
    FuncSymbolInfo * printDoubleFunc = globalBlock->addNewFunc("print_double", DataType::VOID);
    printDoubleFunc->addParamVar("value", DataType::DOUBLE);
    printDoubleFunc->calcParamNum();

    FuncSymbolInfo * getBoolFunc = globalBlock->addNewFunc("get_bool", DataType::BOOL);
    getBoolFunc->calcParamNum();
    FuncSymbolInfo * getIntFunc = globalBlock->addNewFunc("get_int", DataType::INT);
    getIntFunc->calcParamNum();
    FuncSymbolInfo * getFloatFunc = globalBlock->addNewFunc("get_float", DataType::FLOAT);
    getFloatFunc->calcParamNum();
    FuncSymbolInfo * getDoubleFunc = globalBlock->addNewFunc("get_double", DataType::DOUBLE);
    getDoubleFunc->calcParamNum();
}

void SemanticAnalysis::exitCompUnit(CACTParser::CompUnitContext * ctx) {
    // check there is a "main" function
    FuncSymbolInfo * mainSymbolInfo = globalBlock->lookUpFunc("main");
    if (mainSymbolInfo == nullptr || mainSymbolInfo->getSymbolType() != SymbolType::FUNC) {
        throw std::runtime_error("cannot find main function.");
        return;
    }
    if (mainSymbolInfo->getparamNum() > 0) {
        throw std::runtime_error("main function should not have parameters.");
        return;
    }
}

void SemanticAnalysis::enterBType(CACTParser::BTypeContext * ctx) {
    // nothing to do 
}
void SemanticAnalysis::exitBType(CACTParser::BTypeContext * ctx) {
    std::string dataTypeText = ctx->getText();
    if (dataTypeText == "bool") {
        ctx->bDataType = DataType::BOOL;
    } else if (dataTypeText == "int") {
        ctx->bDataType = DataType::INT;
    } else if (dataTypeText == "float") {
        ctx->bDataType = DataType::FLOAT;
    } else if (dataTypeText == "double") {
        ctx->bDataType = DataType::DOUBLE;
    } else {
        throw std::runtime_error(std::string("unknown type: ") + dataTypeText);
        return;
    }
    currentDataType = ctx->bDataType;
}

void SemanticAnalysis::enterDecl(CACTParser::DeclContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitDecl(CACTParser::DeclContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterConstDecl(CACTParser::ConstDeclContext * ctx) {
    // nothing to do 
}
void SemanticAnalysis::exitConstDecl(CACTParser::ConstDeclContext * ctx) {
    // nothing to do 
}

void SemanticAnalysis::enterConstDefBasic(CACTParser::ConstDefBasicContext * ctx) {
    std::string name = ctx->Ident()->getText();
    
    IRVariable * irVar = irGen->newVar(name, currentDataType);
    ctx->thisSymbolInfo = currentBlock->addNewConst(name, currentDataType, irVar);

}
void SemanticAnalysis::exitConstDefBasic(CACTParser::ConstDefBasicContext * ctx) {
    ctx->thisSymbolInfo->checkValue();

}

void SemanticAnalysis::enterConstDefArray(CACTParser::ConstDefArrayContext * ctx) {
    std::string name = ctx->Ident()->getText();
    size_t arraySize = std::stoi(ctx->IntConst()->getText());

    IRVariable * irVar = irGen->newArray(name, currentDataType, arraySize);
    ctx->thisSymbolInfo = currentBlock->addNewConstArray(name, currentDataType, arraySize, irVar);
}
void SemanticAnalysis::exitConstDefArray(CACTParser::ConstDefArrayContext * ctx) {
    ctx->thisSymbolInfo->checkValue();

}

void SemanticAnalysis::enterVarDecl(CACTParser::VarDeclContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitVarDecl(CACTParser::VarDeclContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterVarDef(CACTParser::VarDefContext * ctx) {
    // check whether it is array & add new symbol
    if (ctx->IntConst() != nullptr) { // array
        size_t arraySize = std::stoi(ctx->IntConst()->getText());

        

        ctx->thisSymbolInfo = currentBlock->addNewVarArray(ctx->Ident()->getText(), currentDataType, arraySize);

        

    } else { // basic
        ctx->thisSymbolInfo = currentBlock->addNewVar(ctx->Ident()->getText(), currentDataType);
    }
    if (ctx->constInitVal() != nullptr) {
        ctx->constInitVal()->thisSymbolInfo = ctx->thisSymbolInfo;
    }
}
void SemanticAnalysis::exitVarDef(CACTParser::VarDefContext * ctx) {
    ctx->thisSymbolInfo->checkValue();
}

void SemanticAnalysis::enterConstInitValBasic(CACTParser::ConstInitValBasicContext * ctx) {
    SymbolType thisSymbolType = ctx->thisSymbolInfo->getSymbolType();
    if (thisSymbolType != SymbolType::CONST && thisSymbolType != SymbolType::VAR) {
        throw std::runtime_error("cannot initialize an array with single value.");
        return ;
    }
}
void SemanticAnalysis::exitConstInitValBasic(CACTParser::ConstInitValBasicContext * ctx) {
    ctx->thisSymbolInfo->addValue(ctx->constExp()->dataType, ctx->constExp()->getText());
}

void SemanticAnalysis::enterConstInitValArray(CACTParser::ConstInitValArrayContext * ctx) {
    SymbolType thisSymbolType = ctx->thisSymbolInfo->getSymbolType();
    if (thisSymbolType != SymbolType::CONST_ARRAY && thisSymbolType != SymbolType::VAR_ARRAY) {
        throw std::runtime_error("cannot initialize a variable with an array.");
        return ;
    }
}
void SemanticAnalysis::exitConstInitValArray(CACTParser::ConstInitValArrayContext * ctx) {
    for (const auto & oneConstExp : ctx->constExp()) {
        ctx->thisSymbolInfo->addValue(oneConstExp->dataType, oneConstExp->getText());
    }
}

void SemanticAnalysis::enterFuncDef(CACTParser::FuncDefContext * ctx) {
    std::string returnTypeText = ctx->funcType()->getText();
    DataType returnType;
    if (returnTypeText == "bool") {
        returnType = DataType::BOOL;
    } else if (returnTypeText == "int") {
        returnType = DataType::INT;
    } else if (returnTypeText == "float") {
        returnType = DataType::FLOAT;
    } else if (returnTypeText == "double") {
        returnType = DataType::DOUBLE;
    } else if (returnTypeText == "void") {
        returnType = DataType::VOID;
    } else {
        throw std::runtime_error(std::string("unknown function return value type: ") + returnTypeText);
        return;
    }

    ctx->thisFuncInfo = currentBlock->addNewFunc(ctx->Ident()->getText(), returnType);
    if (ctx->funcFParams() != nullptr) {
        ctx->funcFParams()->thisFuncInfo = ctx->thisFuncInfo;
    }
    ctx->block()->thisFuncInfo = ctx->thisFuncInfo;
    currentFunc = ctx->thisFuncInfo;

    irGen->enterFunc(ctx->Ident()->getText());
}
void SemanticAnalysis::exitFuncDef(CACTParser::FuncDefContext * ctx) {
    ctx->thisFuncInfo->calcParamNum();
    currentFunc = nullptr;

    irGen->exitFunc();
}

void SemanticAnalysis::enterFuncType(CACTParser::FuncTypeContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitFuncType(CACTParser::FuncTypeContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterFuncFParams(CACTParser::FuncFParamsContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitFuncFParams(CACTParser::FuncFParamsContext * ctx) {
    for (const auto & oneParam : ctx->funcFParam()) {
        if (oneParam->ArraySymbol() != nullptr) {
            ctx->thisFuncInfo->addParamArray(oneParam->Ident()->getText(), oneParam->bDataType);
            // TODO: add to ir variable
        } else {
            ctx->thisFuncInfo->addParamVar(oneParam->Ident()->getText(), oneParam->bDataType);
            // TODO: add to ir variable
        }
    }
}

void SemanticAnalysis::enterFuncFParam(CACTParser::FuncFParamContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitFuncFParam(CACTParser::FuncFParamContext * ctx) {
    ctx->bDataType = ctx->bType()->bDataType;
}

void SemanticAnalysis::enterBlock(CACTParser::BlockContext * ctx) {
    if (ctx->thisFuncInfo != nullptr) {
        currentBlock = currentBlock->addNewBlock(ctx->thisFuncInfo);
    } else {
        currentBlock = currentBlock->addNewBlock();
    }
}
void SemanticAnalysis::exitBlock(CACTParser::BlockContext * ctx) {
    currentBlock = currentBlock->getParentBlock();

    // TODO: insert a goto next code
}

void SemanticAnalysis::enterBlockItem(CACTParser::BlockItemContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitBlockItem(CACTParser::BlockItemContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterStmtAssign(CACTParser::StmtAssignContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitStmtAssign(CACTParser::StmtAssignContext * ctx) {
    if (!ctx->lVal()->isVar) {
        throw std::runtime_error(std::string("cannot assign to a constant: ") + ctx->lVal()->getText());
        return;
    }

    if (ctx->lVal()->dataType != ctx->exp()->dataType) {
        throw std::runtime_error(
            std::string("cannot assign ") + ToString(ctx->lVal()->dataType) + 
            std::string(" to ") + ToString(ctx->exp()->dataType)
        );
        return;
    }

    if (ctx->lVal()->isArray) {
        if (!ctx->exp()->isArray) {
            throw std::runtime_error(
                std::string("cannot assign a basic variable (") + ctx->lVal()->getText() + 
                std::string(") to an array (") + ctx->exp()->getText() + std::string(")")
            );
            return;
        } else if (ctx->lVal()->arraySize != ctx->exp()->arraySize) {
            throw std::runtime_error("cannot assign an array to another array with different size");
            return;
        }
    } else {
        if (ctx->exp()->isArray) {
            throw std::runtime_error("cannnot assign an array to a basic variable");
            return;
        }
    }
}

void SemanticAnalysis::enterStmtExp(CACTParser::StmtExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitStmtExp(CACTParser::StmtExpContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterStmtBlock(CACTParser::StmtBlockContext * ctx) {
    ctx->block()->thisFuncInfo = nullptr;
}
void SemanticAnalysis::exitStmtBlock(CACTParser::StmtBlockContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterStmtCtrlIf(CACTParser::StmtCtrlIfContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitStmtCtrlIf(CACTParser::StmtCtrlIfContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterStmtCtrlWhile(CACTParser::StmtCtrlWhileContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitStmtCtrlWhile(CACTParser::StmtCtrlWhileContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterStmtCtrlBreak(CACTParser::StmtCtrlBreakContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitStmtCtrlBreak(CACTParser::StmtCtrlBreakContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterStmtCtrlContinue(CACTParser::StmtCtrlContinueContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitStmtCtrlContinue(CACTParser::StmtCtrlContinueContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterStmtReturn(CACTParser::StmtReturnContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitStmtReturn(CACTParser::StmtReturnContext * ctx) {
    if (currentFunc == nullptr) {
        throw std::runtime_error("cannot return here.");
        return;
    }

    if (ctx->exp() != nullptr) {
        if (currentFunc->getDataType() != ctx->exp()->dataType) {
            throw std::runtime_error("return data type not match");
            return;
        }
    } else {
        if (currentFunc->getDataType() != DataType::VOID) {
            throw std::runtime_error("this function needs an unvoid return value");
            return;
        }
    }
}

void SemanticAnalysis::enterExpAddExp(CACTParser::ExpAddExpContext * ctx) {
    // nothing to do
    // std::cerr << "@@@@@@@@@@@22" << std::endl;
}
void SemanticAnalysis::exitExpAddExp(CACTParser::ExpAddExpContext * ctx) {
    ctx->isArray = ctx->addExp()->isArray;
    ctx->arraySize = ctx->addExp()->arraySize;
    ctx->dataType = ctx->addExp()->dataType;

    ctx->result = ctx->addExp()->result;

    // std::cerr << int(ctx->dataType) << std::endl;
    // std::cerr << ctx->getText() << std::endl;
    // std::cerr << "++++" << ctx << std::endl;
}

void SemanticAnalysis::enterExpBoolConst(CACTParser::ExpBoolConstContext * ctx) {
    // nothing to do
    // std::cerr << "!!!!!!!!!11" << std::endl;
}

void SemanticAnalysis::exitExpBoolConst(CACTParser::ExpBoolConstContext * ctx) {
    ctx->isArray = false;
    ctx->dataType = DataType::BOOL;
    // std::cerr << int(ctx->dataType) << std::endl;
    // std::cerr << ctx->getText() << std::endl;
    // std::cerr << "++++" << ctx << std::endl;
}

void SemanticAnalysis::enterCond(CACTParser::CondContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitCond(CACTParser::CondContext * ctx) {
    if (ctx->lOrExp()->isArray) {
        throw std::runtime_error("an array cannot be a condition");
        return;
    }

    if (ctx->lOrExp()->dataType != DataType::BOOL) {
        throw std::runtime_error("the datatype of condition should be bool");
        return;
    }
}

void SemanticAnalysis::enterPrimaryExpExp(CACTParser::PrimaryExpExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitPrimaryExpExp(CACTParser::PrimaryExpExpContext * ctx) {
    ctx->isArray = ctx->exp()->isArray;
    ctx->arraySize = ctx->exp()->arraySize;
    ctx->dataType = ctx->exp()->dataType;
}

void SemanticAnalysis::enterPrimaryExpLVal(CACTParser::PrimaryExpLValContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitPrimaryExpLVal(CACTParser::PrimaryExpLValContext * ctx) {
    ctx->isArray = ctx->lVal()->isArray;
    ctx->arraySize = ctx->lVal()->arraySize;
    ctx->dataType = ctx->lVal()->dataType;
}

void SemanticAnalysis::enterPrimaryNumber(CACTParser::PrimaryNumberContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitPrimaryNumber(CACTParser::PrimaryNumberContext * ctx) {
    ctx->isArray = false;
    ctx->dataType = ctx->number()->dataType;
}

void SemanticAnalysis::enterUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * ctx) {
    ctx->isArray = ctx->primaryExp()->isArray;
    ctx->arraySize = ctx->primaryExp()->arraySize;
    ctx->dataType = ctx->primaryExp()->dataType;
}

void SemanticAnalysis::enterUnaryExpFunc(CACTParser::UnaryExpFuncContext * ctx) {
    FuncSymbolInfo * thisFunc = globalBlock->lookUpFunc(ctx->Ident()->getText());
    if (thisFunc == nullptr) {
        throw std::runtime_error(
            std::string("cannot find function ") + ctx->Ident()->getText()
        );
        return;
    }
    ctx->thisFunc = thisFunc;
    if (ctx->funcRParams() != nullptr) {
        ctx->funcRParams()->thisFunc = thisFunc;
    }
}
void SemanticAnalysis::exitUnaryExpFunc(CACTParser::UnaryExpFuncContext * ctx) {
    FuncSymbolInfo * thisFunc = ctx->thisFunc;
    ctx->isArray = false;
    ctx->dataType = thisFunc->getDataType();
    
    if (ctx->funcRParams() == nullptr && thisFunc->getparamNum() > 0) {
        throw std::runtime_error(
            std::string("too many or too few parameters for function ") +
            thisFunc->getName()
        );
        return;
    }
}

void SemanticAnalysis::enterUnaryExpUnaryOp(CACTParser::UnaryExpUnaryOpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitUnaryExpUnaryOp(CACTParser::UnaryExpUnaryOpContext * ctx) {
    std::string unaryOp = ctx->unaryOp()->getText();
    if (unaryOp == "+" || unaryOp == "-") {
        if (ctx->unaryExp()->dataType == DataType::BOOL || ctx->unaryExp()->dataType == DataType::VOID) {
            throw std::runtime_error(
                std::string("cannot use unary operator ") + unaryOp + 
                std::string(" on ") + ToString(ctx->unaryExp()->dataType) + std::string(" value")
            );
            return;
        } else {
            ctx->isArray = ctx->unaryExp()->isArray;
            ctx->arraySize = ctx->unaryExp()->arraySize;
            ctx->dataType = ctx->unaryExp()->dataType;
        }
    } else if (unaryOp == "!") {
        if (ctx->unaryExp()->dataType != DataType::BOOL) {
            throw std::runtime_error(
                std::string("cannot use unary operator ") + unaryOp + 
                std::string(" on ") + ToString(ctx->unaryExp()->dataType) + std::string(" value")
            );
            return;
        } else if (ctx->unaryExp()->isArray) {
            throw std::runtime_error(
                std::string("cannot use unary operator ") + unaryOp + std::string(" on array")
            );
            return;
        } else {
            ctx->isArray = false;
            ctx->dataType = DataType::BOOL;
        }
    }
}

void SemanticAnalysis::enterUnaryOp(CACTParser::UnaryOpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitUnaryOp(CACTParser::UnaryOpContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterFuncRParams(CACTParser::FuncRParamsContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitFuncRParams(CACTParser::FuncRParamsContext * ctx) {
    FuncSymbolInfo * thisFunc = ctx->thisFunc;
    size_t paramNum = thisFunc->getparamNum();
    if (ctx->exp().size() != paramNum) {
        throw std::runtime_error(
            std::string("too many or too few parameters for function ") +
            thisFunc->getName()
        );
        return;
    }
    std::vector < SymbolInfo * > paramList = thisFunc->getparamList();
    for (size_t i = 0; i < paramNum; i++) {
        bool paramIsArray = paramList[i]->getSymbolType() == SymbolType::CONST_ARRAY || paramList[i]->getSymbolType() == SymbolType::VAR_ARRAY;

        if (ctx->exp(i)->dataType != paramList[i]->getDataType()) {
            throw std::runtime_error("different data type of parameters");
            return;
        } else if (ctx->exp(i)->isArray != paramIsArray) {
            throw std::runtime_error("different array type of parameters");
            return;
        }
    }
}

void SemanticAnalysis::enterMulOp(CACTParser::MulOpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitMulOp(CACTParser::MulOpContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * ctx) {
    ctx->isArray = ctx->unaryExp()->isArray;
    ctx->arraySize = ctx->unaryExp()->arraySize;
    ctx->dataType = ctx->unaryExp()->dataType;
}

void SemanticAnalysis::enterMulExpMulExp(CACTParser::MulExpMulExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitMulExpMulExp(CACTParser::MulExpMulExpContext * ctx) {
    ctx->isArray = ctx->mulExp()->isArray;
    ctx->arraySize = ctx->mulExp()->arraySize;
    ctx->dataType = ctx->mulExp()->dataType;
    
    if (ctx->dataType != ctx->unaryExp()->dataType) {
        throw std::runtime_error(
            std::string("different data type beside operator:") + 
            ToString(ctx->dataType) + std::string(", ") + ToString(ctx->unaryExp()->dataType)
        );
        return;
    } else if (ctx->dataType == DataType::BOOL) {
        throw std::runtime_error("cannot use non-logical operator for bool value");
        return;
    }

    if (ctx->isArray) {
        if (!ctx->unaryExp()->isArray) {
            throw std::runtime_error("cannot do operation between basic value and array");
            return;
        } else if (ctx->arraySize != ctx->unaryExp()->arraySize) {
            throw std::runtime_error("cannot do operation between arrays with different size");
            return;
        }
    } else {
        if (ctx->unaryExp()->isArray) {
            throw std::runtime_error("cannot do operation between basic value and array");
            return;
        }
    }
}

void SemanticAnalysis::enterAddOp(CACTParser::AddOpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitAddOp(CACTParser::AddOpContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterAddExpMulExp(CACTParser::AddExpMulExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitAddExpMulExp(CACTParser::AddExpMulExpContext * ctx) {
    ctx->isArray = ctx->mulExp()->isArray;
    ctx->arraySize = ctx->mulExp()->arraySize;
    ctx->dataType = ctx->mulExp()->dataType;
}

void SemanticAnalysis::enterAddExpAddExp(CACTParser::AddExpAddExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitAddExpAddExp(CACTParser::AddExpAddExpContext * ctx) {
    ctx->isArray = ctx->addExp()->isArray;
    ctx->arraySize = ctx->addExp()->arraySize;
    ctx->dataType = ctx->addExp()->dataType;
    
    if (ctx->dataType != ctx->mulExp()->dataType) {
        throw std::runtime_error(
            std::string("different data type beside operator:") + 
            ToString(ctx->dataType) + std::string(", ") + ToString(ctx->mulExp()->dataType)
        );
        return;
    } else if (ctx->dataType == DataType::BOOL) {
        throw std::runtime_error("cannot use non-logical operator for bool value");
        return;
    }

    if (ctx->isArray) {
        if (!ctx->mulExp()->isArray) {
            throw std::runtime_error("cannot do operation between basic value and array");
            return;
        } else if (ctx->arraySize != ctx->mulExp()->arraySize) {
            throw std::runtime_error("cannot do operation between arrays with different size");
            return;
        }
    } else {
        if (ctx->mulExp()->isArray) {
            throw std::runtime_error("cannot do operation between basic value and array");
            return;
        }
    }
}

void SemanticAnalysis::enterRelOp(CACTParser::RelOpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitRelOp(CACTParser::RelOpContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterRelExpAddExp(CACTParser::RelExpAddExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitRelExpAddExp(CACTParser::RelExpAddExpContext * ctx) {
    ctx->isArray = ctx->addExp()->isArray;
    ctx->arraySize = ctx->addExp()->arraySize;
    ctx->dataType = ctx->addExp()->dataType;
}

void SemanticAnalysis::enterRelExpRelExp(CACTParser::RelExpRelExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitRelExpRelExp(CACTParser::RelExpRelExpContext * ctx) {
    ctx->isArray = false;
    ctx->dataType = DataType::BOOL;

    if (ctx->relExp()->dataType != ctx->addExp()->dataType) {
        throw std::runtime_error(
            std::string("different data type beside operator:") + 
            ToString(ctx->relExp()->dataType) + std::string(", ") + ToString(ctx->addExp()->dataType)
        );
        return;
    } else if (ctx->relExp()->dataType == DataType::BOOL) {
        throw std::runtime_error("cannot use non-logical operator for bool value");
        return;
    }

    if (ctx->relExp()->isArray || ctx->addExp()->isArray) {
        throw std::runtime_error("cannot use logical operation between arrays");
        return;
    }
}

void SemanticAnalysis::enterRelExpBoolConst(CACTParser::RelExpBoolConstContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitRelExpBoolConst(CACTParser::RelExpBoolConstContext * ctx) {
    ctx->isArray = false;
    ctx->dataType = DataType::BOOL;
}

void SemanticAnalysis::enterEqOp(CACTParser::EqOpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitEqOp(CACTParser::EqOpContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterEqExpRelExp(CACTParser::EqExpRelExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitEqExpRelExp(CACTParser::EqExpRelExpContext * ctx) {
    ctx->isArray = ctx->relExp()->isArray;
    ctx->arraySize = ctx->relExp()->arraySize;
    ctx->dataType = ctx->relExp()->dataType;
}

void SemanticAnalysis::enterEqExpEqExp(CACTParser::EqExpEqExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitEqExpEqExp(CACTParser::EqExpEqExpContext * ctx) {
    ctx->isArray = false;
    ctx->dataType = DataType::BOOL;

    if (ctx->eqExp()->dataType != ctx->relExp()->dataType) {
        throw std::runtime_error(
            std::string("different data type beside operator:") + 
            ToString(ctx->eqExp()->dataType) + std::string(", ") + ToString(ctx->relExp()->dataType)
        );
        return;
    }

    if (ctx->eqExp()->isArray || ctx->relExp()->isArray) {
        throw std::runtime_error("cannot use logical operation between arrays");
        return;
    }
}

void SemanticAnalysis::enterLAndExpEqExp(CACTParser::LAndExpEqExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitLAndExpEqExp(CACTParser::LAndExpEqExpContext * ctx) {
    ctx->isArray = ctx->eqExp()->isArray;
    ctx->arraySize = ctx->eqExp()->arraySize;
    ctx->dataType = ctx->eqExp()->dataType;
}

void SemanticAnalysis::enterLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * ctx) {
    ctx->isArray = false;
    ctx->dataType = DataType::BOOL;

    if (ctx->lAndExp()->dataType != ctx->eqExp()->dataType) {
        throw std::runtime_error(
            std::string("different data type beside operator:") + 
            ToString(ctx->lAndExp()->dataType) + std::string(", ") + ToString(ctx->eqExp()->dataType)
        );
        return;
    } else if (ctx->lAndExp()->dataType != DataType::BOOL) {
        throw std::runtime_error("cannot use non-logical operator for bool value");
        return;
    }

    if (ctx->lAndExp()->isArray || ctx->eqExp()->isArray) {
        throw std::runtime_error("cannot use logical operation between arrays");
        return;
    }
}

void SemanticAnalysis::enterLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * ctx) {
    ctx->isArray = ctx->lAndExp()->isArray;
    ctx->arraySize = ctx->lAndExp()->arraySize;
    ctx->dataType = ctx->lAndExp()->dataType;
}

void SemanticAnalysis::enterLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * ctx) {
    ctx->isArray = false;
    ctx->dataType = DataType::BOOL;

    if (ctx->lOrExp()->dataType != ctx->lAndExp()->dataType) {
        throw std::runtime_error(
            std::string("different data type beside operator:") + 
            ToString(ctx->lOrExp()->dataType) + std::string(", ") + ToString(ctx->lAndExp()->dataType)
        );
        return;
    } else if (ctx->lAndExp()->dataType != DataType::BOOL) {
        throw std::runtime_error("cannot use non-logical operator for bool value");
        return;
    }

    if (ctx->lOrExp()->isArray || ctx->lAndExp()->isArray) {
        throw std::runtime_error("cannot use logical operation between arrays");
        return;
    }
}

void SemanticAnalysis::enterConstExpNumVal(CACTParser::ConstExpNumValContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitConstExpNumVal(CACTParser::ConstExpNumValContext * ctx) {
    ctx->dataType = ctx->number()->dataType;
    ctx->result = ctx->number()->result;
}

void SemanticAnalysis::enterConstArrExp(CACTParser::ConstArrExpContext * ctx) {
    
}
void SemanticAnalysis::exitConstArrExp(CACTParser::ConstArrExpContext * ctx) {
    
}

void SemanticAnalysis::enterConstExpBoolVal(CACTParser::ConstExpBoolValContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitConstExpBoolVal(CACTParser::ConstExpBoolValContext * ctx) {
    ctx->dataType = DataType::BOOL;
}

void SemanticAnalysis::enterNumValIntConst(CACTParser::NumValIntConstContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitNumValIntConst(CACTParser::NumValIntConstContext * ctx) {
    ctx->dataType = DataType::INT;
}

void SemanticAnalysis::enterNumValDoubleConst(CACTParser::NumValDoubleConstContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitNumValDoubleConst(CACTParser::NumValDoubleConstContext * ctx) {
    ctx->dataType = DataType::DOUBLE;
}

void SemanticAnalysis::enterNumValFloatConst(CACTParser::NumValFloatConstContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitNumValFloatConst(CACTParser::NumValFloatConstContext * ctx) {
    ctx->dataType = DataType::FLOAT;
}

void SemanticAnalysis::enterBoolVal(CACTParser::BoolValContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitBoolVal(CACTParser::BoolValContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterLVal(CACTParser::LValContext * ctx) {
    SymbolInfo * thisSymbol = currentBlock->lookUpSymbol(ctx->Ident()->getText());
    if (thisSymbol == nullptr) {
        throw std::runtime_error(
            std::string("cannot find symbol ") + ctx->Ident()->getText()
        );
        return;
    }
    ctx->thisSymbol = thisSymbol;
}
void SemanticAnalysis::exitLVal(CACTParser::LValContext * ctx) {
    SymbolInfo * thisSymbol = ctx->thisSymbol;
    SymbolType thisSymbolType = thisSymbol->getSymbolType();
    ctx->dataType = thisSymbol->getDataType();
    if (ctx->exp() != nullptr) {    // with "[exp]"
        if (!ctx->exp()->isArray && ctx->exp()->dataType == DataType::INT) {
            if (thisSymbolType == SymbolType::CONST_ARRAY) {
                ctx->isVar = false;
                ctx->isArray = false;
            } else if (thisSymbolType == SymbolType::VAR_ARRAY) {
                ctx->isVar = true;
                ctx->isArray = false;
            } else {
                throw std::runtime_error("cannot use \"[index]\" for basic variable");
                return;
            }
        } else {
            throw std::runtime_error("array index should be int");
            return;
        }
    } else {    // without "[exp]"
        if (thisSymbolType == SymbolType::CONST) {
            ctx->isArray = false;
            ctx->isVar = false;
        } else if (thisSymbolType == SymbolType::CONST_ARRAY) {
            ctx->isArray = true;
            ctx->arraySize = thisSymbol->getArraySize();
            ctx->isVar = false;
        } else if (thisSymbolType == SymbolType::VAR) {
            ctx->isArray = false;
            ctx->isVar = true;
        } else if (thisSymbolType == SymbolType::VAR_ARRAY) {
            ctx->isArray = true;
            ctx->arraySize = thisSymbol->getArraySize();
            ctx->isVar = true;
        } else {
            throw std::runtime_error(
                std::string("cannot use symbol ") + ctx->Ident()->getText()
            );
        }
    }
}

void SemanticAnalysis::enterFuncVal(CACTParser::FuncValContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitFuncVal(CACTParser::FuncValContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterEveryRule(antlr4::ParserRuleContext * ctx) {}
void SemanticAnalysis::exitEveryRule(antlr4::ParserRuleContext * ctx) {}
void SemanticAnalysis::visitTerminal(antlr4::tree::TerminalNode * node) {}
void SemanticAnalysis::visitErrorNode(antlr4::tree::ErrorNode * node) {}
