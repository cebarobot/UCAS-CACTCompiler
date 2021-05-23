#include "semanticAnalysis.h"

SemanticAnalysis::SemanticAnalysis(BlockInfo * globalBlock)
: globalBlock(globalBlock), currentBlock(globalBlock), currentSymbol(nullptr), 
    currentFunc(nullptr), currentDataType(DataType::VOID) { }

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
    SymbolInfo * mainSymbolInfo = globalBlock->lookUpSymbol("main");
    if (mainSymbolInfo == nullptr || mainSymbolInfo->getSymbolType() != SymbolType::FUNC) {
        // TODO: throw exception
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
    // nothing to do
}
void SemanticAnalysis::exitConstInitValBasic(CACTParser::ConstInitValBasicContext * ctx) {
    ctx->thisSymbolInfo->addValue(ctx->constExp()->dataType, ctx->constExp()->getText());
}

void SemanticAnalysis::enterConstInitValArray(CACTParser::ConstInitValArrayContext * ctx) {
    // nothing to do
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
        return;
    }

    ctx->thisFuncInfo = currentBlock->addNewFunc(ctx->Ident()->getText(), returnType);
    ctx->funcFParams()->thisFuncInfo = ctx->thisFuncInfo;
    ctx->block()->thisFuncInfo = ctx->thisFuncInfo;
}
void SemanticAnalysis::exitFuncDef(CACTParser::FuncDefContext * ctx) {
    ctx->thisFuncInfo->calcParamNum();
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
        } else {
            ctx->thisFuncInfo->addParamVar(oneParam->Ident()->getText(), oneParam->bDataType);
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
        currentBlock = currentBlock->addNewBlock();
    } else {
        currentBlock = currentBlock->addNewBlock(ctx->thisFuncInfo);
    }
}
void SemanticAnalysis::exitBlock(CACTParser::BlockContext * ctx) {
    currentBlock = currentBlock->getParentBlock();
}

void SemanticAnalysis::enterBlockItem(CACTParser::BlockItemContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitBlockItem(CACTParser::BlockItemContext * ctx) {
    // nothing to do
}

void SemanticAnalysis::enterStmt(CACTParser::StmtContext * ctx) {}
void SemanticAnalysis::exitStmt(CACTParser::StmtContext * ctx) {}

void SemanticAnalysis::enterExp(CACTParser::ExpContext * ctx) {}
void SemanticAnalysis::exitExp(CACTParser::ExpContext * ctx) {}

void SemanticAnalysis::enterCond(CACTParser::CondContext * ctx) {}
void SemanticAnalysis::exitCond(CACTParser::CondContext * ctx) {}

void SemanticAnalysis::enterLVal(CACTParser::LValContext * ctx) {}
void SemanticAnalysis::exitLVal(CACTParser::LValContext * ctx) {}

void SemanticAnalysis::enterPrimaryExp(CACTParser::PrimaryExpContext * ctx) {}
void SemanticAnalysis::exitPrimaryExp(CACTParser::PrimaryExpContext * ctx) {}

void SemanticAnalysis::enterUnaryExp(CACTParser::UnaryExpContext * ctx) {}
void SemanticAnalysis::exitUnaryExp(CACTParser::UnaryExpContext * ctx) {}

void SemanticAnalysis::enterUnaryOp(CACTParser::UnaryOpContext * ctx) {}
void SemanticAnalysis::exitUnaryOp(CACTParser::UnaryOpContext * ctx) {}

void SemanticAnalysis::enterFuncRParams(CACTParser::FuncRParamsContext * ctx) {}
void SemanticAnalysis::exitFuncRParams(CACTParser::FuncRParamsContext * ctx) {}

void SemanticAnalysis::enterMulExp(CACTParser::MulExpContext * ctx) {}
void SemanticAnalysis::exitMulExp(CACTParser::MulExpContext * ctx) {}

void SemanticAnalysis::enterAddExp(CACTParser::AddExpContext * ctx) {}
void SemanticAnalysis::exitAddExp(CACTParser::AddExpContext * ctx) {}

void SemanticAnalysis::enterRelExp(CACTParser::RelExpContext * ctx) {}
void SemanticAnalysis::exitRelExp(CACTParser::RelExpContext * ctx) {}

void SemanticAnalysis::enterEqExp(CACTParser::EqExpContext * ctx) {}
void SemanticAnalysis::exitEqExp(CACTParser::EqExpContext * ctx) {}

void SemanticAnalysis::enterLAndExp(CACTParser::LAndExpContext * ctx) {}
void SemanticAnalysis::exitLAndExp(CACTParser::LAndExpContext * ctx) {}

void SemanticAnalysis::enterLOrExp(CACTParser::LOrExpContext * ctx) {}
void SemanticAnalysis::exitLOrExp(CACTParser::LOrExpContext * ctx) {}

void SemanticAnalysis::enterConstExpNumber(CACTParser::ConstExpNumberContext * ctx) {
    // nothing to do
}
void SemanticAnalysis::exitConstExpNumber(CACTParser::ConstExpNumberContext * ctx) {
    ctx->dataType = ctx->number()->dataType;
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
