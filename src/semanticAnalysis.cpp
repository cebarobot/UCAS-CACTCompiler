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

void SemanticAnalysis::enterConstDecl(CACTParser::ConstDeclContext * ctx) {}
void SemanticAnalysis::exitConstDecl(CACTParser::ConstDeclContext * ctx) {
    std::cout << "const variable define: " << std::endl;
    for(const auto & const_def : ctx->constDef())
    {
        std::cout << "\tname: " << const_def->Ident()->getText().c_str() \
                << " type: " << ctx->bType()->getText().c_str() << std::endl;
    }
}

void SemanticAnalysis::enterBType(CACTParser::BTypeContext * ctx) {}
void SemanticAnalysis::exitBType(CACTParser::BTypeContext * ctx) {}

void SemanticAnalysis::enterConstDef(CACTParser::ConstDefContext * ctx) {}
void SemanticAnalysis::exitConstDef(CACTParser::ConstDefContext * ctx) {}

void SemanticAnalysis::enterConstInitVal(CACTParser::ConstInitValContext * ctx) {}
void SemanticAnalysis::exitConstInitVal(CACTParser::ConstInitValContext * ctx) {}

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

void SemanticAnalysis::enterConstExpNumber(CACTParser::ConstExpNumberContext * ctx) {}
void SemanticAnalysis::exitConstExpNumber(CACTParser::ConstExpNumberContext * ctx) {
    ctx->basic_or_array_and_type = ctx->number()->basic_or_array_and_type;
}

void SemanticAnalysis::enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext * ctx) {}
void SemanticAnalysis::exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext * ctx) {}

void SemanticAnalysis::enterNumber(CACTParser::NumberContext * ctx) {}
void SemanticAnalysis::exitNumber(CACTParser::NumberContext * ctx) {}

void SemanticAnalysis::enterEveryRule(antlr4::ParserRuleContext * ctx) {}
void SemanticAnalysis::exitEveryRule(antlr4::ParserRuleContext * ctx) {}
void SemanticAnalysis::visitTerminal(antlr4::tree::TerminalNode * node) {}
void SemanticAnalysis::visitErrorNode(antlr4::tree::ErrorNode * node) {}
