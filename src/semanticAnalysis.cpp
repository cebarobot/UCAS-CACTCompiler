#include "semanticAnalysis.h"
#include <iostream>

SemanticAnalysis::SemanticAnalysis(BlockInfo * globalBlock, IRGenerator * newIRGen)
: globalBlock(globalBlock), currentBlock(globalBlock), currentSymbol(nullptr), 
    currentFunc(nullptr), currentDataType(DataType::VOID),
    irGen(newIRGen) {}

void SemanticAnalysis::enterCompUnit(CACTParser::CompUnitContext * ctx) {
    // add build-in functions
    IRLabel * funcLabel;

    FuncSymbolInfo * printBoolFunc = globalBlock->addNewFunc("print_bool", DataType::VOID);
    printBoolFunc->addParamVar("value", DataType::BOOL);
    printBoolFunc->calcParamNum();
    printBoolFunc->setOp(irGen->newLabel("print_bool"));

    FuncSymbolInfo * printIntFunc = globalBlock->addNewFunc("print_int", DataType::VOID);
    printIntFunc->addParamVar("value", DataType::INT);
    printIntFunc->calcParamNum();
    printIntFunc->setOp(irGen->newLabel("print_int"));
    
    FuncSymbolInfo * printFloatFunc = globalBlock->addNewFunc("print_float", DataType::VOID);
    printFloatFunc->addParamVar("value", DataType::FLOAT);
    printFloatFunc->calcParamNum();
    printFloatFunc->setOp(irGen->newLabel("print_float"));

    FuncSymbolInfo * printDoubleFunc = globalBlock->addNewFunc("print_double", DataType::VOID);
    printDoubleFunc->addParamVar("value", DataType::DOUBLE);
    printDoubleFunc->calcParamNum();
    printDoubleFunc->setOp(irGen->newLabel("print_double"));

    FuncSymbolInfo * getBoolFunc = globalBlock->addNewFunc("get_bool", DataType::BOOL);
    getBoolFunc->calcParamNum();
    getBoolFunc->setOp(irGen->newLabel("get_bool"));

    FuncSymbolInfo * getIntFunc = globalBlock->addNewFunc("get_int", DataType::INT);
    getIntFunc->calcParamNum();
    getIntFunc->setOp(irGen->newLabel("get_int"));

    FuncSymbolInfo * getFloatFunc = globalBlock->addNewFunc("get_float", DataType::FLOAT);
    getFloatFunc->calcParamNum();
    getFloatFunc->setOp(irGen->newLabel("get_float"));

    FuncSymbolInfo * getDoubleFunc = globalBlock->addNewFunc("get_double", DataType::DOUBLE);
    getDoubleFunc->calcParamNum();
    getDoubleFunc->setOp(irGen->newLabel("get_double"));
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

    ctx->thisSymbolInfo = currentBlock->addNewConst(name, currentDataType);
}
void SemanticAnalysis::exitConstDefBasic(CACTParser::ConstDefBasicContext * ctx) {
    std::string name = ctx->Ident()->getText();
    IRValue * initVal = ctx->constExp()->result;

    if (ctx->constExp()->dataType != currentDataType) {
        throw std::runtime_error("inital value data type not match.");
    }

    if (currentFunc) {
        IRVariable* irVar = irGen->newVar(name, currentDataType);
        irGen->assignBasic(currentDataType, irVar, initVal);
        ctx->thisSymbolInfo->setOp(irVar);

    } else {
        initVal->setName(name);
        initVal->setVariable(true);
        ctx->thisSymbolInfo->setOp(initVal);
    }
}

void SemanticAnalysis::enterConstDefArray(CACTParser::ConstDefArrayContext * ctx) {
    std::string name = ctx->Ident()->getText();
    int arraySize = std::stoi(ctx->IntConst()->getText());

    ctx->thisSymbolInfo = currentBlock->addNewConstArray(name, currentDataType, arraySize);
}
void SemanticAnalysis::exitConstDefArray(CACTParser::ConstDefArrayContext * ctx) {
    std::string name = ctx->Ident()->getText();
    int arraySize = std::stoi(ctx->IntConst()->getText());
    IRValue * initVal = ctx->constArrExp()->result;
    
    if (ctx->constArrExp()->dataType != currentDataType) {
        throw std::runtime_error("inital value data type not match.");
    }

    if (ctx->constArrExp()->arraySize > arraySize) {
        throw std::runtime_error("inital value array size not match.");
    }
    initVal->fillValue(arraySize);

    if (currentFunc) {
        IRVariable * irVar = irGen->newVar(name, currentDataType, arraySize);
        irGen->assignArray(currentDataType, arraySize, irVar, initVal);
        ctx->thisSymbolInfo->setOp(irVar);

    } else {
        initVal->setName(name);
        ctx->thisSymbolInfo->setOp(initVal);
    }
}

void SemanticAnalysis::enterVarDecl(CACTParser::VarDeclContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitVarDecl(CACTParser::VarDeclContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterVarDefBasic(CACTParser::VarDefBasicContext * ctx) {
    std::string name = ctx->Ident()->getText();

    ctx->thisSymbolInfo = currentBlock->addNewVar(name, currentDataType);
}
void SemanticAnalysis::exitVarDefBasic(CACTParser::VarDefBasicContext * ctx) {
    std::string name = ctx->Ident()->getText();
    IRValue * initVal;

    if (ctx->constExp()) {
        initVal = ctx->constExp()->result;

        if (ctx->constExp()->dataType != currentDataType) {
            throw std::runtime_error("inital value data type not match.");
        }

    } else {
        initVal = irGen->newValue(currentDataType, "");
    }

    if (currentFunc) {
        IRVariable * irVar = irGen->newVar(name, currentDataType);
        std::cerr << irVar << std::endl;
        irGen->assignBasic(currentDataType, irVar, initVal);
        ctx->thisSymbolInfo->setOp(irVar);

    } else {
        initVal->setName(name);
        ctx->thisSymbolInfo->setOp(initVal);
    }
}

void SemanticAnalysis::enterVarDefArray(CACTParser::VarDefArrayContext * ctx) {
    std::string name = ctx->Ident()->getText();
    int arraySize = std::stoi(ctx->IntConst()->getText());

    ctx->thisSymbolInfo = currentBlock->addNewVarArray(name, currentDataType, arraySize);
}
void SemanticAnalysis::exitVarDefArray(CACTParser::VarDefArrayContext * ctx) {
    std::string name = ctx->Ident()->getText();
    int arraySize = std::stoi(ctx->IntConst()->getText());
    IRValue * initVal;

    if (ctx->constArrExp()) {
        initVal = ctx->constArrExp()->result;

        if (ctx->constArrExp()->dataType != currentDataType) {
            throw std::runtime_error("inital value data type not match.");
        }
        
        if (ctx->constArrExp()->arraySize > arraySize) {
            throw std::runtime_error("inital value array size not match.");
        }
    } else {
        initVal = irGen->newValue(currentDataType);
    }
    initVal->fillValue(arraySize);

    if (currentFunc) {
        IRVariable * irVar = irGen->newVar(name, currentDataType, arraySize);
        irGen->assignArray(currentDataType, arraySize, irVar, initVal);
        ctx->thisSymbolInfo->setOp(irVar);

    } else {
        initVal->setName(name);
        ctx->thisSymbolInfo->setOp(initVal);
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
    currentFunc->setOp(new IRLabel(ctx->Ident()->getText()));

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
        std::string name = oneParam->Ident()->getText();
        DataType dt = oneParam->bDataType;

        if (oneParam->ArraySymbol() != nullptr) {
            SymbolInfo * thisSymbolInfo = ctx->thisFuncInfo->addParamArray(name, dt);
            // TODO: add to ir variable
        } else {
            SymbolInfo * thisSymbolInfo = ctx->thisFuncInfo->addParamVar(name, dt);
            IROperand * param_var = irGen->newVar(name, dt);
            thisSymbolInfo->setOp(param_var);

            if (dt == BOOL || dt == INT) {
                irGen->addCode(new IRGetParamW(param_var));
            } else if (dt == FLOAT) {
                irGen->addCode(new IRGetParamF(param_var));
            } else if (dt == DOUBLE) {
                irGen->addCode(new IRGetParamD(param_var));
            }
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

    if (ctx->lVal()->index) {
        if (ctx->lVal()->dataType == INT || ctx->lVal()->dataType == BOOL) {
            irGen->addCode(new IRCopyToIndexedW(ctx->lVal()->result, ctx->exp()->result, ctx->lVal()->index));
        } else if (ctx->lVal()->dataType == FLOAT) {
            irGen->addCode(new IRCopyToIndexedF(ctx->lVal()->result, ctx->exp()->result, ctx->lVal()->index));
        } else if (ctx->lVal()->dataType == DOUBLE) {
            irGen->addCode(new IRCopyToIndexedD(ctx->lVal()->result, ctx->exp()->result, ctx->lVal()->index));
        }
    } else {
        if (ctx->lVal()->dataType == INT || ctx->lVal()->dataType == BOOL) {
            irGen->addCode(new IRCopyW(ctx->lVal()->result, ctx->exp()->result));
        } else if (ctx->lVal()->dataType == FLOAT) {
            irGen->addCode(new IRCopyF(ctx->lVal()->result, ctx->exp()->result));
        } else if (ctx->lVal()->dataType == DOUBLE) {
            irGen->addCode(new IRCopyD(ctx->lVal()->result, ctx->exp()->result));
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

    DataType dt = currentFunc->getDataType();

    if (ctx->exp() != nullptr) {
        if (dt != ctx->exp()->dataType) {
            throw std::runtime_error("return data type not match");
            return;
        }
    } else {
        if (dt != DataType::VOID) {
            throw std::runtime_error("this function needs an unvoid return value");
            return;
        }
    }

    if (dt == BOOL || dt == INT) {
        irGen->addCode(new IRReturnW(ctx->exp()->result));
    } else if (dt == FLOAT) {
        irGen->addCode(new IRReturnF(ctx->exp()->result));
    } else if (dt == DOUBLE) {
        irGen->addCode(new IRReturnD(ctx->exp()->result));
    }
    irGen->addReturn();

}

void SemanticAnalysis::enterExpAddExp(CACTParser::ExpAddExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitExpAddExp(CACTParser::ExpAddExpContext * ctx) {
    ctx->isArray = ctx->addExp()->isArray;
    ctx->arraySize = ctx->addExp()->arraySize;
    ctx->dataType = ctx->addExp()->dataType;
    ctx->result = ctx->addExp()->result;
}

void SemanticAnalysis::enterExpBoolConst(CACTParser::ExpBoolConstContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::exitExpBoolConst(CACTParser::ExpBoolConstContext * ctx) {
    ctx->isArray = ctx->boolVal()->isArray;
    ctx->arraySize = ctx->boolVal()->arraySize;
    ctx->dataType = ctx->boolVal()->dataType;
    ctx->result = ctx->boolVal()->result;
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
    ctx->result = ctx->exp()->result;
}

void SemanticAnalysis::enterPrimaryExpRVal(CACTParser::PrimaryExpRValContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitPrimaryExpRVal(CACTParser::PrimaryExpRValContext * ctx) {
    ctx->isArray = ctx->rVal()->isArray;
    ctx->arraySize = ctx->rVal()->arraySize;
    ctx->dataType = ctx->rVal()->dataType;
    ctx->result = ctx->rVal()->result;
}

void SemanticAnalysis::enterPrimaryNumVal(CACTParser::PrimaryNumValContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitPrimaryNumVal(CACTParser::PrimaryNumValContext * ctx) {
    ctx->isArray = ctx->numVal()->isArray;
    ctx->arraySize = ctx->numVal()->arraySize;
    ctx->dataType = ctx->numVal()->dataType;
    ctx->result = ctx->numVal()->result;
}

void SemanticAnalysis::enterUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * ctx) {
    ctx->isArray = ctx->primaryExp()->isArray;
    ctx->arraySize = ctx->primaryExp()->arraySize;
    ctx->dataType = ctx->primaryExp()->dataType;
    ctx->result = ctx->primaryExp()->result;
}

void SemanticAnalysis::enterUnaryExpFunc(CACTParser::UnaryExpFuncContext * ctx) {
    // nothing to do 
}
void SemanticAnalysis::exitUnaryExpFunc(CACTParser::UnaryExpFuncContext * ctx) {
    ctx->isArray = ctx->funcVal()->isArray;
    ctx->arraySize = ctx->funcVal()->arraySize;
    ctx->dataType = ctx->funcVal()->dataType;
    ctx->result = ctx->funcVal()->result;
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

        if (unaryOp == "+") {
            ctx->result = ctx->unaryExp()->result;
        } else if (unaryOp == "-") {
            if (ctx->dataType == INT) {
                ctx->result = irGen->newTemp(ctx->dataType);
                irGen->addCode(new IRNegInt(ctx->result, ctx->unaryExp()->result));
            } else if (ctx->dataType == FLOAT) {
                ctx->result = irGen->newTemp(ctx->dataType);
                irGen->addCode(new IRNegFloat(ctx->result, ctx->unaryExp()->result));
            } else if (ctx->dataType == DOUBLE) {
                ctx->result = irGen->newTemp(ctx->dataType);
                irGen->addCode(new IRNegDouble(ctx->result, ctx->unaryExp()->result));
            }
            // TODO:
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

        // TODO

    }
}

void SemanticAnalysis::enterUnaryOp(CACTParser::UnaryOpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitUnaryOp(CACTParser::UnaryOpContext * ctx) {
    // nothing to do
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
    ctx->result = ctx->unaryExp()->result;
}

void SemanticAnalysis::enterMulExpMulExp(CACTParser::MulExpMulExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitMulExpMulExp(CACTParser::MulExpMulExpContext * ctx) {
    ctx->isArray = ctx->mulExp()->isArray;
    ctx->arraySize = ctx->mulExp()->arraySize;
    ctx->dataType = ctx->mulExp()->dataType;
    ctx->result = irGen->newTemp(ctx->dataType);
    
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

    std::string mul_op = ctx->mulOp()->getText();
    if (mul_op == "*") {
        if (ctx->dataType == INT) {
            irGen->addCode(new IRMulInt(ctx->result, ctx->mulExp()->result, ctx->unaryExp()->result));
        } else if (ctx->dataType == FLOAT) {
            irGen->addCode(new IRMulFloat(ctx->result, ctx->mulExp()->result, ctx->unaryExp()->result));
        } else if (ctx->dataType == DOUBLE) {
            irGen->addCode(new IRMulDouble(ctx->result, ctx->mulExp()->result, ctx->unaryExp()->result));
        }
    } else if (mul_op == "/") {
        if (ctx->dataType == INT) {
            irGen->addCode(new IRDivInt(ctx->result, ctx->mulExp()->result, ctx->unaryExp()->result));
        } else if (ctx->dataType == FLOAT) {
            irGen->addCode(new IRDivFloat(ctx->result, ctx->mulExp()->result, ctx->unaryExp()->result));
        } else if (ctx->dataType == DOUBLE) {
            irGen->addCode(new IRDivDouble(ctx->result, ctx->mulExp()->result, ctx->unaryExp()->result));
        }
    } else if (mul_op == "%") {
        if (ctx->dataType == INT) {
            irGen->addCode(new IRModInt(ctx->result, ctx->mulExp()->result, ctx->unaryExp()->result));
        }
    }

    // TODO:
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
    ctx->result = ctx->mulExp()->result;
}

void SemanticAnalysis::enterAddExpAddExp(CACTParser::AddExpAddExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitAddExpAddExp(CACTParser::AddExpAddExpContext * ctx) {
    ctx->isArray = ctx->addExp()->isArray;
    ctx->arraySize = ctx->addExp()->arraySize;
    ctx->dataType = ctx->addExp()->dataType;
    ctx->result = irGen->newTemp(ctx->dataType);
    
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

    std::string add_op = ctx->addOp()->getText();
    if (add_op == "+") {
        if (ctx->dataType == INT) {
            irGen->addCode(new IRAddInt(ctx->result, ctx->addExp()->result, ctx->mulExp()->result));
        } else if (ctx->dataType == FLOAT) {
            irGen->addCode(new IRAddFloat(ctx->result, ctx->addExp()->result, ctx->mulExp()->result));
        } else if (ctx->dataType == DOUBLE) {
            irGen->addCode(new IRAddDouble(ctx->result, ctx->addExp()->result, ctx->mulExp()->result));
        }
    } else if (add_op == "-") {
        if (ctx->dataType == INT) {
            irGen->addCode(new IRSubInt(ctx->result, ctx->addExp()->result, ctx->mulExp()->result));
        } else if (ctx->dataType == FLOAT) {
            irGen->addCode(new IRSubFloat(ctx->result, ctx->addExp()->result, ctx->mulExp()->result));
        } else if (ctx->dataType == DOUBLE) {
            irGen->addCode(new IRSubDouble(ctx->result, ctx->addExp()->result, ctx->mulExp()->result));
        }
    }
    // TODO:

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

void SemanticAnalysis::enterConstArrExp(CACTParser::ConstArrExpContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitConstArrExp(CACTParser::ConstArrExpContext * ctx) {
    irGen->removeValues(ctx->constExp().size());

    ctx->isArray = true;
    ctx->arraySize = ctx->constExp().size();
    ctx->dataType = ctx->constExp(0)->dataType;
    ctx->result = irGen->newValue(ctx->dataType);

    for (auto pExp : ctx->constExp()) {
        if (pExp->dataType != ctx->dataType) {
            throw std::runtime_error("data type not match");
        }

        ctx->result->addValue(pExp->result->getValue(0));
        delete pExp->result;
    }
}

void SemanticAnalysis::enterConstExpNumVal(CACTParser::ConstExpNumValContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitConstExpNumVal(CACTParser::ConstExpNumValContext * ctx) {
    ctx->isArray = ctx->numVal()->isArray;
    ctx->arraySize = ctx->numVal()->arraySize;
    ctx->dataType = ctx->numVal()->dataType;
    ctx->result = ctx->numVal()->result;
}

void SemanticAnalysis::enterConstExpBoolVal(CACTParser::ConstExpBoolValContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitConstExpBoolVal(CACTParser::ConstExpBoolValContext * ctx) {
    ctx->isArray = ctx->boolVal()->isArray;
    ctx->arraySize = ctx->boolVal()->arraySize;
    ctx->dataType = ctx->boolVal()->dataType;
    ctx->result = ctx->boolVal()->result;
}

void SemanticAnalysis::enterNumValIntConst(CACTParser::NumValIntConstContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitNumValIntConst(CACTParser::NumValIntConstContext * ctx) {
    ctx->isArray = false;
    ctx->arraySize = 0;
    ctx->dataType = DataType::INT;
    ctx->result = irGen->newValue(INT, ctx->IntConst()->getText());
}

void SemanticAnalysis::enterNumValFloatConst(CACTParser::NumValFloatConstContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitNumValFloatConst(CACTParser::NumValFloatConstContext * ctx) {
    ctx->isArray = false;
    ctx->arraySize = 0;
    ctx->dataType = DataType::FLOAT;

    std::string val_str = ctx->FloatConst()->getText();
    val_str = val_str.substr(0, val_str.size()-1);

    ctx->result = irGen->newValue(FLOAT, val_str);
}

void SemanticAnalysis::enterNumValDoubleConst(CACTParser::NumValDoubleConstContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitNumValDoubleConst(CACTParser::NumValDoubleConstContext * ctx) {
    ctx->isArray = false;
    ctx->arraySize = 0;
    ctx->dataType = DataType::DOUBLE;
    ctx->result = irGen->newValue(DOUBLE, ctx->DoubleConst()->getText());
}

void SemanticAnalysis::enterBoolVal(CACTParser::BoolValContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitBoolVal(CACTParser::BoolValContext * ctx) {
    ctx->isArray = false;
    ctx->arraySize = 0;
    ctx->dataType = DataType::BOOL;

    std::string val_str = ctx->BoolConst()->getText();
    if (val_str == "true") {
        ctx->result = irGen->newValue(BOOL, "1");
    } else {
        ctx->result = irGen->newValue(BOOL, "0");
    }
}

void SemanticAnalysis::enterLValBasic(CACTParser::LValBasicContext * ctx) {
    SymbolInfo * thisSymbol = currentBlock->lookUpSymbol(ctx->Ident()->getText());
    if (thisSymbol == nullptr) {
        throw std::runtime_error(
            std::string("cannot find symbol ") + ctx->Ident()->getText()
        );
        return;
    }
    ctx->thisSymbol = thisSymbol;
}
void SemanticAnalysis::exitLValBasic(CACTParser::LValBasicContext * ctx) {
    SymbolInfo * thisSymbol = ctx->thisSymbol;
    SymbolType thisSymbolType = thisSymbol->getSymbolType();
    ctx->dataType = thisSymbol->getDataType();
    ctx->result = thisSymbol->getOp();

    if (thisSymbolType == SymbolType::CONST) {
        throw std::runtime_error(std::string("cannot assign to a constant: ") + ctx->getText());
        return;
    } else if (thisSymbolType == SymbolType::CONST_ARRAY) {
        throw std::runtime_error(std::string("cannot assign to a constant: ") + ctx->getText());
        return;
    } else if (thisSymbolType == SymbolType::VAR) {
        ctx->isArray = false;
        ctx->index = nullptr;
    } else if (thisSymbolType == SymbolType::VAR_ARRAY) {
        ctx->isArray = true;
        ctx->arraySize = thisSymbol->getArraySize();
        ctx->index = irGen->getArrRepeatVar();
    } else {
        throw std::runtime_error(
            std::string("cannot use symbol ") + ctx->Ident()->getText()
        );
        return;
    }
}

void SemanticAnalysis::enterLValIndexed(CACTParser::LValIndexedContext * ctx) {
    SymbolInfo * thisSymbol = currentBlock->lookUpSymbol(ctx->Ident()->getText());
    if (thisSymbol == nullptr) {
        throw std::runtime_error(
            std::string("cannot find symbol ") + ctx->Ident()->getText()
        );
        return;
    }
    ctx->thisSymbol = thisSymbol;
}
void SemanticAnalysis::exitLValIndexed(CACTParser::LValIndexedContext * ctx) {
    SymbolInfo * thisSymbol = ctx->thisSymbol;
    SymbolType thisSymbolType = thisSymbol->getSymbolType();
    ctx->result = thisSymbol->getOp();
    ctx->dataType = thisSymbol->getDataType();
    ctx->isArray = false;

    if (ctx->exp()->isArray || ctx->exp()->dataType != DataType::INT) {
        throw std::runtime_error("array index should be int");
        return;
    }
    ctx->index = irGen->newTemp(INT);
    IROperand * ir_cs = irGen->newInt(SizeOfDataType(ctx->dataType));
    irGen->addCode(new IRMulInt(ctx->index, ir_cs, ctx->exp()->result));

    if (thisSymbolType == SymbolType::CONST_ARRAY) {
        throw std::runtime_error(std::string("cannot assign to a constant: ") + ctx->getText());
        return;
    } else if (thisSymbolType == SymbolType::VAR_ARRAY) {
    } else {
        throw std::runtime_error("cannot use \"[index]\" for basic variable");
        return;
    }
}


void SemanticAnalysis::enterRValBasic(CACTParser::RValBasicContext * ctx) {
    SymbolInfo * thisSymbol = currentBlock->lookUpSymbol(ctx->Ident()->getText());
    if (thisSymbol == nullptr) {
        throw std::runtime_error(
            std::string("cannot find symbol ") + ctx->Ident()->getText()
        );
        return;
    }
    ctx->thisSymbol = thisSymbol;
}
void SemanticAnalysis::exitRValBasic(CACTParser::RValBasicContext * ctx) {
    SymbolInfo * thisSymbol = ctx->thisSymbol;
    SymbolType thisSymbolType = thisSymbol->getSymbolType();
    ctx->dataType = thisSymbol->getDataType();

    IROperand * var = thisSymbol->getOp();

    if (thisSymbolType == SymbolType::CONST || thisSymbolType == SymbolType::VAR) {
        ctx->isArray = false;
        ctx->result = var;

    } else if (thisSymbolType == SymbolType::CONST_ARRAY || thisSymbolType == SymbolType::VAR_ARRAY) {
        ctx->isArray = true;
        ctx->arraySize = thisSymbol->getArraySize();
        ctx->result = irGen->newTemp(ctx->dataType);

        IROperand * index = irGen->getArrRepeatVar();
        if (ctx->dataType == DOUBLE) {
            irGen->addCode(new IRCopyFromIndexedD(ctx->result, var, index));
        } else {
            irGen->addCode(new IRCopyFromIndexedW(ctx->result, var, index));
        }
    } else {
        throw std::runtime_error(
            std::string("cannot use symbol ") + ctx->Ident()->getText()
        );
    }

}

void SemanticAnalysis::enterRValIndexed(CACTParser::RValIndexedContext * ctx) {
    SymbolInfo * thisSymbol = currentBlock->lookUpSymbol(ctx->Ident()->getText());
    if (thisSymbol == nullptr) {
        throw std::runtime_error(
            std::string("cannot find symbol ") + ctx->Ident()->getText()
        );
        return;
    }
    ctx->thisSymbol = thisSymbol;
}
void SemanticAnalysis::exitRValIndexed(CACTParser::RValIndexedContext * ctx) {
    SymbolInfo * thisSymbol = ctx->thisSymbol;
    SymbolType thisSymbolType = thisSymbol->getSymbolType();
    ctx->dataType = thisSymbol->getDataType();
    ctx->isArray = false;

    IROperand * var = thisSymbol->getOp();

    if (ctx->exp()->isArray || ctx->exp()->dataType != DataType::INT) {
        throw std::runtime_error("array index should be int");
        return;
    }
    IROperand * index = irGen->newTemp(INT);
    IROperand * ir_cs = irGen->newInt(SizeOfDataType(ctx->dataType));
    irGen->addCode(new IRMulInt(index, ir_cs, ctx->exp()->result));

    ctx->result = irGen->newTemp(ctx->dataType);

    if (thisSymbolType == SymbolType::CONST_ARRAY || thisSymbolType == SymbolType::VAR_ARRAY) {
        if (ctx->dataType == DOUBLE) {
            irGen->addCode(new IRCopyFromIndexedD(ctx->result, var, index));
        } else {
            irGen->addCode(new IRCopyFromIndexedW(ctx->result, var, index));
        }
    } else {
        throw std::runtime_error("cannot use \"[index]\" for basic variable");
        return;
    }
}


void SemanticAnalysis::enterFuncVal(CACTParser::FuncValContext * ctx) {
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
void SemanticAnalysis::exitFuncVal(CACTParser::FuncValContext * ctx) {
    FuncSymbolInfo * thisFunc = ctx->thisFunc;
    ctx->isArray = false;
    ctx->dataType = thisFunc->getDataType();
    ctx->result = irGen->newTemp(ctx->dataType);
    IROperand * funcLabel = ctx->thisFunc->getOp();
    
    if (ctx->funcRParams() == nullptr && thisFunc->getparamNum() > 0) {
        throw std::runtime_error(
            std::string("too many or too few parameters for function ") +
            thisFunc->getName()
        );
        return;
    }

    irGen->addCode(new IRCall(funcLabel));
    if (ctx->dataType == BOOL || ctx->dataType == INT) {
        irGen->addCode(new IRGetReturnW(ctx->result));
    } else if (ctx->dataType == FLOAT) {
        irGen->addCode(new IRGetReturnF(ctx->result));
    } else if (ctx->dataType == DOUBLE) {
        irGen->addCode(new IRGetReturnD(ctx->result));
    }
}

void SemanticAnalysis::enterFuncRParams(CACTParser::FuncRParamsContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitFuncRParams(CACTParser::FuncRParamsContext * ctx) {
    FuncSymbolInfo * thisFunc = ctx->thisFunc;
    int paramNum = thisFunc->getparamNum();
    if ((int) ctx->exp().size() != paramNum) {
        throw std::runtime_error(
            std::string("too many or too few parameters for function ") +
            thisFunc->getName()
        );
        return;
    }
    std::vector < SymbolInfo * > paramList = thisFunc->getparamList();
    for (int i = 0; i < paramNum; i++) {
        bool paramIsArray = paramList[i]->getSymbolType() == SymbolType::CONST_ARRAY || paramList[i]->getSymbolType() == SymbolType::VAR_ARRAY;
        DataType dt = ctx->exp(i)->dataType;
        if (dt != paramList[i]->getDataType()) {
            throw std::runtime_error("different data type of parameters");
            return;
        } else if (ctx->exp(i)->isArray != paramIsArray) {
            throw std::runtime_error("different array type of parameters");
            return;
        }

        IROperand * temp = ctx->exp(i)->result;
        if (dt == BOOL || dt == INT) {
            irGen->addCode(new IRParamW(temp));
        } else if (dt == FLOAT) {
            irGen->addCode(new IRParamF(temp));
        } else if (dt == DOUBLE) {
            irGen->addCode(new IRParamD(temp));
        }
    }
}

void SemanticAnalysis::enterEveryRule(antlr4::ParserRuleContext * ctx) {}
void SemanticAnalysis::exitEveryRule(antlr4::ParserRuleContext * ctx) {}
void SemanticAnalysis::visitTerminal(antlr4::tree::TerminalNode * node) {}
void SemanticAnalysis::visitErrorNode(antlr4::tree::ErrorNode * node) {}
