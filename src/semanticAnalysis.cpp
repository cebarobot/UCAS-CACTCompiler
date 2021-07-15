#include "semanticAnalysis.h"
#include <iostream>

SemanticAnalysis::SemanticAnalysis(BlockInfo * globalBlock, IRProgram * new_ir)
: globalBlock(globalBlock), currentBlock(globalBlock), currentSymbol(nullptr), 
    currentFunc(nullptr), currentDataType(DataType::VOID),
    ir(new_ir), currentIRFunc(nullptr) {}

void SemanticAnalysis::enterCompUnit(CACTParser::CompUnitContext * ctx) {
    // add build-in functions
    std::cerr << "check point asdf" << std::endl;
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
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    }
    if (mainSymbolInfo->getparamNum() > 0) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    }
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

    // for debug
    std::cout << "const variable define: " << std::endl;
    for(const auto & const_def : ctx->constDef())
    {
        std::cout << "\tname: " << const_def->Ident()->getText().c_str() \
                << " type: " << ctx->bType()->getText().c_str() << std::endl;
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
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    }
    currentDataType = ctx->bDataType;
}

void SemanticAnalysis::enterConstDef(CACTParser::ConstDefContext * ctx) {
    // check whether it is array & add new symbol
    if (ctx->IntConst() != nullptr) { // array
        size_t arraySize = std::stoi(ctx->IntConst()->getText());
        ctx->thisSymbolInfo = currentBlock->addNewConstArray(ctx->Ident()->getText(), currentDataType, arraySize);
    } else { // basic
        ctx->thisSymbolInfo = currentBlock->addNewConst(ctx->Ident()->getText(), currentDataType);
    }
    ctx->constInitVal()->thisSymbolInfo = ctx->thisSymbolInfo;
}
void SemanticAnalysis::exitConstDef(CACTParser::ConstDefContext * ctx) {
    ctx->thisSymbolInfo->checkValue();
}

void SemanticAnalysis::enterConstInitValBasic(CACTParser::ConstInitValBasicContext * ctx) {
    SymbolType thisSymbolType = ctx->thisSymbolInfo->getSymbolType();
    if (thisSymbolType != SymbolType::CONST && thisSymbolType != SymbolType::VAR) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return ;
    }
}
void SemanticAnalysis::exitConstInitValBasic(CACTParser::ConstInitValBasicContext * ctx) {
    ctx->thisSymbolInfo->addValue(ctx->constExp()->dataType, ctx->constExp()->getText());
}

void SemanticAnalysis::enterConstInitValArray(CACTParser::ConstInitValArrayContext * ctx) {
    SymbolType thisSymbolType = ctx->thisSymbolInfo->getSymbolType();
    if (thisSymbolType != SymbolType::CONST_ARRAY && thisSymbolType != SymbolType::VAR_ARRAY) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return ;
    }
}
void SemanticAnalysis::exitConstInitValArray(CACTParser::ConstInitValArrayContext * ctx) {
    for (const auto & oneConstExp : ctx->constExp()) {
        ctx->thisSymbolInfo->addValue(oneConstExp->dataType, oneConstExp->getText());
    }
}

void SemanticAnalysis::enterVarDecl(CACTParser::VarDeclContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitVarDecl(CACTParser::VarDeclContext * ctx) {

    // for debug
    std::cout << "variable define: " << std::endl;
    for(const auto & var_def : ctx->varDef())
    {
        std::cout << "\tname: " << var_def->Ident()->getText().c_str() \
                << " type: " << ctx->bType()->getText().c_str() << std::endl;
    }
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
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    }

    std::cerr << ctx->Ident()->getText() << std::endl;
    ctx->thisFuncInfo = currentBlock->addNewFunc(ctx->Ident()->getText(), returnType);
    if (ctx->funcFParams() != nullptr) {
        ctx->funcFParams()->thisFuncInfo = ctx->thisFuncInfo;
    }
    ctx->block()->thisFuncInfo = ctx->thisFuncInfo;
    currentFunc = ctx->thisFuncInfo;

    currentIRFunc = new IRFunction(ctx->Ident()->getText());
    ir->functions.push_back(currentIRFunc);

}
void SemanticAnalysis::exitFuncDef(CACTParser::FuncDefContext * ctx) {
    ctx->thisFuncInfo->calcParamNum();
    currentFunc = nullptr;

    currentIRFunc = nullptr;
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
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 135\n");
        return;
    }

    if (ctx->lVal()->dataType != ctx->exp()->dataType) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 146\n");
        return;
    }

    if (ctx->lVal()->isArray) {
        if (!ctx->exp()->isArray) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 123\n");
            return;
        } else if (ctx->lVal()->arraySize != ctx->exp()->arraySize) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 2345\n");
            return;
        }
    } else {
        if (ctx->exp()->isArray) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 2753\n");
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

void SemanticAnalysis::enterStmtCtrl(CACTParser::StmtCtrlContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitStmtCtrl(CACTParser::StmtCtrlContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterStmtReturn(CACTParser::StmtReturnContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitStmtReturn(CACTParser::StmtReturnContext * ctx) {
    if (currentFunc == nullptr) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 45\n");
        return;
    }

    if (ctx->exp() != nullptr) {
        if (currentFunc->getDataType() != ctx->exp()->dataType) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC4586\n");
            return;
        }
    } else {
        if (currentFunc->getDataType() != DataType::VOID) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 4679\n");
            return;
        }
    }
}

void SemanticAnalysis::enterExpAddExp(CACTParser::ExpAddExpContext * ctx) {
    // nothing to do
    std::cerr << "@@@@@@@@@@@22" << std::endl;
}
void SemanticAnalysis::exitExpAddExp(CACTParser::ExpAddExpContext * ctx) {
    ctx->isArray = ctx->addExp()->isArray;
    ctx->arraySize = ctx->addExp()->arraySize;
    ctx->dataType = ctx->addExp()->dataType;

    ctx->result = ctx->addExp()->result;

    std::cerr << int(ctx->dataType) << std::endl;
    std::cerr << ctx->getText() << std::endl;
    std::cerr << "++++" << ctx << std::endl;
}

void SemanticAnalysis::enterExpBoolConst(CACTParser::ExpBoolConstContext * ctx) {
    // nothing to do
    std::cerr << "!!!!!!!!!11" << std::endl;
}

void SemanticAnalysis::exitExpBoolConst(CACTParser::ExpBoolConstContext * ctx) {
    ctx->isArray = false;
    ctx->dataType = DataType::BOOL;
    std::cerr << int(ctx->dataType) << std::endl;
    std::cerr << ctx->getText() << std::endl;
    std::cerr << "++++" << ctx << std::endl;
}

void SemanticAnalysis::enterCond(CACTParser::CondContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitCond(CACTParser::CondContext * ctx) {
    if (ctx->lOrExp()->isArray) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC e45\n");
        return;
    }

    if (ctx->lOrExp()->dataType != DataType::BOOL) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 345\n");
        return;
    }
}

void SemanticAnalysis::enterLVal(CACTParser::LValContext * ctx) {
    SymbolInfo * thisSymbol = currentBlock->lookUpSymbol(ctx->Ident()->getText());
    if (thisSymbol == nullptr) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 23r\n");
        return;
    }
    ctx->thisSymbol = thisSymbol;
}
void SemanticAnalysis::exitLVal(CACTParser::LValContext * ctx) {
    SymbolInfo * thisSymbol = ctx->thisSymbol;
    SymbolType thisSymbolType = thisSymbol->getSymbolType();
    ctx->dataType = thisSymbol->getDataType();
    if (ctx->exp() != nullptr) {    // with "[exp]""
        if (!ctx->exp()->isArray && ctx->exp()->dataType == DataType::INT) {
            if (thisSymbolType == SymbolType::CONST_ARRAY) {
                ctx->isVar = false;
                ctx->isArray = false;
            } else if (thisSymbolType == SymbolType::VAR_ARRAY) {
                ctx->isVar = true;
                ctx->isArray = false;
            } else {
                // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 3q4t\n");
                return;
            }
        } else {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC qrew\n");
            return;
        }
    } else {    // without "xxx"
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
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 789C\n");
        }
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
    std::cerr << "check point asdf1" << std::endl;
    FuncSymbolInfo * thisFunc = globalBlock->lookUpFunc(ctx->Ident()->getText());
    if (thisFunc == nullptr) {
        // TODO: throw exception
    std::cerr << "check point asdf2" << std::endl;
throw std::runtime_error("\nWRONG SENMANTIC 1234\n");
        return;
    }
    std::cerr << "check point asdf3" << std::endl;
    ctx->thisFunc = thisFunc;
    std::cerr << "check point asdf4" << std::endl;
    if (ctx->funcRParams() != nullptr) {
        ctx->funcRParams()->thisFunc = thisFunc;
    }
    std::cerr << "check point asdf5" << std::endl;
}
void SemanticAnalysis::exitUnaryExpFunc(CACTParser::UnaryExpFuncContext * ctx) {
    std::cerr << "check point asdf5" << std::endl;
    FuncSymbolInfo * thisFunc = ctx->thisFunc;
    std::cerr << "check point asdf6" << std::endl;
    ctx->isArray = false;
    std::cerr << "check point asd7f" << std::endl;
    ctx->dataType = thisFunc->getDataType();
    
    if (ctx->funcRParams() == nullptr && thisFunc->getparamNum() > 0) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 758\n");
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
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 758\n");
            return;
        } else {
            ctx->isArray = ctx->unaryExp()->isArray;
            ctx->arraySize = ctx->unaryExp()->arraySize;
            ctx->dataType = ctx->unaryExp()->dataType;
        }
    } else if (unaryOp == "!") {
        if (ctx->unaryExp()->dataType != DataType::BOOL) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 274\n");
            return;
        } else if (ctx->unaryExp()->isArray) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 364\n");
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
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC sfad\n");
        return;
    }
    std::vector < SymbolInfo * > paramList = thisFunc->getparamList();
    for (size_t i = 0; i < paramNum; i++) {
        bool paramIsArray = paramList[i]->getSymbolType() == SymbolType::CONST_ARRAY || paramList[i]->getSymbolType() == SymbolType::VAR_ARRAY;

        if (ctx->exp(i)->dataType != paramList[i]->getDataType()) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 4ei75\n");
            return;
        } else if (ctx->exp(i)->isArray != paramIsArray) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC zryu\n");
            return;
        }
    }
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
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC q34t\n");
        return;
    } else if (ctx->dataType == DataType::BOOL) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 6rth\n");
        return;
    }

    if (ctx->isArray) {
        if (!ctx->unaryExp()->isArray) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC q34\n");
            return;
        } else if (ctx->arraySize != ctx->unaryExp()->arraySize) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC vhj\n");
            return;
        }
    } else {
        if (ctx->unaryExp()->isArray) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC zeaa\n");
            return;
        }
    }
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
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC r765\n");
        return;
    } else if (ctx->dataType == DataType::BOOL) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC yfu87to\n");
        return;
    }

    if (ctx->isArray) {
        if (!ctx->mulExp()->isArray) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC     q3w\n");
            return;
        } else if (ctx->arraySize != ctx->mulExp()->arraySize) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC awet\n");
            return;
        }
    } else {
        if (ctx->mulExp()->isArray) {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 784w5\n");
            return;
        }
    }
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
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC q34\n");
        return;
    } else if (ctx->relExp()->dataType == DataType::BOOL) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC fhjg\n");
        return;
    }

    if (ctx->relExp()->isArray || ctx->addExp()->isArray) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC w6y\n");
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
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC qw4\n");
        return;
    }

    if (ctx->eqExp()->isArray || ctx->relExp()->isArray) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC sd \n");
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
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC q3564\n");
        return;
    } else if (ctx->lAndExp()->dataType != DataType::BOOL) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC 123\n");
        return;
    }

    if (ctx->lAndExp()->isArray || ctx->eqExp()->isArray) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC wetq\n");
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
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    } else if (ctx->lAndExp()->dataType != DataType::BOOL) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    }

    if (ctx->lOrExp()->isArray || ctx->lAndExp()->isArray) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    }
}

void SemanticAnalysis::enterConstExpNumber(CACTParser::ConstExpNumberContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitConstExpNumber(CACTParser::ConstExpNumberContext * ctx) {
    ctx->dataType = ctx->number()->dataType;
    ctx->result = ctx->number()->result;
}

void SemanticAnalysis::enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext * ctx) {
    ctx->dataType = DataType::BOOL;
}

void SemanticAnalysis::enterNumberIntConst(CACTParser::NumberIntConstContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitNumberIntConst(CACTParser::NumberIntConstContext * ctx) {
    ctx->dataType = DataType::INT;
    ctx->result = new IRIntConst(ctx->IntConst()->getText());
}

void SemanticAnalysis::enterNumberDoubleConst(CACTParser::NumberDoubleConstContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitNumberDoubleConst(CACTParser::NumberDoubleConstContext * ctx) {
    ctx->dataType = DataType::DOUBLE;
}

void SemanticAnalysis::enterNumberFloatConst(CACTParser::NumberFloatConstContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitNumberFloatConst(CACTParser::NumberFloatConstContext * ctx) {
    ctx->dataType = DataType::FLOAT;
}

void SemanticAnalysis::enterEveryRule(antlr4::ParserRuleContext * ctx) {}
void SemanticAnalysis::exitEveryRule(antlr4::ParserRuleContext * ctx) {}
void SemanticAnalysis::visitTerminal(antlr4::tree::TerminalNode * node) {}
void SemanticAnalysis::visitErrorNode(antlr4::tree::ErrorNode * node) {}
