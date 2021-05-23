#include "semanticAnalysis.h"

void SemanticAnalysis::enterCompUnit(CACTParser::CompUnitContext * ctx) {
    
}
void SemanticAnalysis::exitCompUnit(CACTParser::CompUnitContext * ctx) {
    
}

void SemanticAnalysis::enterDecl(CACTParser::DeclContext * ctx) {}
void SemanticAnalysis::exitDecl(CACTParser::DeclContext * ctx) {}

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
