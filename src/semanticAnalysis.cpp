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
        currentDataType = DataType::BOOL;
    } else if (dataTypeText == "int") {
        currentDataType = DataType::INT;
    } else if (dataTypeText == "float") {
        currentDataType = DataType::FLOAT;
    } else if (dataTypeText == "double") {
        currentDataType = DataType::DOUBLE;
    } else {
        // TODO: throw exception
        return;
    }
}

void SemanticAnalysis::enterConstDef(CACTParser::ConstDefContext * ctx) {
    // check whether it is array & add new symbol
    if (ctx->IntConst() != nullptr) { // array
        size_t arraySize = std::stoi(ctx->IntConst()->getText());
        ctx->thisSymbolInfo = currentBlock->addNewConstArray(ctx->Ident()->getText(), currentDataType, arraySize);
        ctx->constInitVal()->thisSymbolInfo = ctx->thisSymbolInfo;
    } else { // basic
        ctx->thisSymbolInfo = currentBlock->addNewConst(ctx->Ident()->getText(), currentDataType);
        ctx->constInitVal()->thisSymbolInfo = ctx->thisSymbolInfo;
    }
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

void SemanticAnalysis::enterVarDecl(CACTParser::VarDeclContext * ctx) {}
void SemanticAnalysis::exitVarDecl(CACTParser::VarDeclContext * ctx) {
    std::cout << "variable define: " << std::endl;
    for(const auto & var_def : ctx->varDef())
    {
        std::cout << "\tname: " << var_def->Ident()->getText().c_str() \
                << " type: " << ctx->bType()->getText().c_str() << std::endl;
    }
}

void SemanticAnalysis::enterVarDef(CACTParser::VarDefContext * ctx) {}
void SemanticAnalysis::exitVarDef(CACTParser::VarDefContext * ctx) {}

void SemanticAnalysis::enterFuncDef(CACTParser::FuncDefContext * ctx) {}
void SemanticAnalysis::exitFuncDef(CACTParser::FuncDefContext * ctx) {}

void SemanticAnalysis::enterFuncType(CACTParser::FuncTypeContext * ctx) {}
void SemanticAnalysis::exitFuncType(CACTParser::FuncTypeContext * ctx) {}

void SemanticAnalysis::enterFuncFParams(CACTParser::FuncFParamsContext * ctx) {}
void SemanticAnalysis::exitFuncFParams(CACTParser::FuncFParamsContext * ctx) {}

void SemanticAnalysis::enterFuncFParam(CACTParser::FuncFParamContext * ctx) {}
void SemanticAnalysis::exitFuncFParam(CACTParser::FuncFParamContext * ctx) {}

void SemanticAnalysis::enterBlock(CACTParser::BlockContext * ctx) {}
void SemanticAnalysis::exitBlock(CACTParser::BlockContext * ctx) {}

void SemanticAnalysis::enterBlockItem(CACTParser::BlockItemContext * ctx) {}
void SemanticAnalysis::exitBlockItem(CACTParser::BlockItemContext * ctx) {}

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
