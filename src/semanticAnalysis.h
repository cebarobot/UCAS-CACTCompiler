#pragma once

#include "../grammar/CACTBaseListener.h"
#include "symbolTable.h"

class SemanticAnalysis : public CACTBaseListener {
private:
    BlockInfo * globalBlock;

    BlockInfo * currentBlock;
    SymbolInfo * currentSymbol;
    FuncSymbolInfo * currentFunc;
    DataType currentDataType;

public:
    SemanticAnalysis(BlockInfo * globalBlock);
    ~SemanticAnalysis(){}


    void enterCompUnit(CACTParser::CompUnitContext * ctx) override ;
    void exitCompUnit(CACTParser::CompUnitContext * ctx) override ;

    void enterDecl(CACTParser::DeclContext * ctx) override ;
    void exitDecl(CACTParser::DeclContext * ctx) override ;

    void enterConstDecl(CACTParser::ConstDeclContext * ctx) override;
    void exitConstDecl(CACTParser::ConstDeclContext * ctx) override;

    void enterBType(CACTParser::BTypeContext * ctx) override ;
    void exitBType(CACTParser::BTypeContext * ctx) override ;

    void enterConstDef(CACTParser::ConstDefContext * ctx) override ;
    void exitConstDef(CACTParser::ConstDefContext * ctx) override ;

    // void enterConstInitVal(CACTParser::ConstInitValContext * ctx) override ;
    // void exitConstInitVal(CACTParser::ConstInitValContext * ctx) override ;

    void enterConstInitValBasic(CACTParser::ConstInitValBasicContext * ctx) override;
    void exitConstInitValBasic(CACTParser::ConstInitValBasicContext * ctx) override;

    void enterConstInitValArray(CACTParser::ConstInitValArrayContext * ctx) override;
    void exitConstInitValArray(CACTParser::ConstInitValArrayContext * ctx) override;


    void enterVarDecl(CACTParser::VarDeclContext * ctx) override;
    void exitVarDecl(CACTParser::VarDeclContext * ctx) override;

    void enterVarDef(CACTParser::VarDefContext * ctx) override ;
    void exitVarDef(CACTParser::VarDefContext * ctx) override ;

    void enterFuncDef(CACTParser::FuncDefContext * ctx) override ;
    void exitFuncDef(CACTParser::FuncDefContext * ctx) override ;

    void enterFuncType(CACTParser::FuncTypeContext * ctx) override ;
    void exitFuncType(CACTParser::FuncTypeContext * ctx) override ;

    void enterFuncFParams(CACTParser::FuncFParamsContext * ctx) override ;
    void exitFuncFParams(CACTParser::FuncFParamsContext * ctx) override ;

    void enterFuncFParam(CACTParser::FuncFParamContext * ctx) override ;
    void exitFuncFParam(CACTParser::FuncFParamContext * ctx) override ;

    void enterBlock(CACTParser::BlockContext * ctx) override ;
    void exitBlock(CACTParser::BlockContext * ctx) override ;

    void enterBlockItem(CACTParser::BlockItemContext * ctx) override ;
    void exitBlockItem(CACTParser::BlockItemContext * ctx) override ;

    void enterStmt(CACTParser::StmtContext * ctx) override ;
    void exitStmt(CACTParser::StmtContext * ctx) override ;

    void enterExp(CACTParser::ExpContext * ctx) override ;
    void exitExp(CACTParser::ExpContext * ctx) override ;

    void enterCond(CACTParser::CondContext * ctx) override ;
    void exitCond(CACTParser::CondContext * ctx) override ;

    void enterLVal(CACTParser::LValContext * ctx) override ;
    void exitLVal(CACTParser::LValContext * ctx) override ;

    void enterPrimaryExp(CACTParser::PrimaryExpContext * ctx) override ;
    void exitPrimaryExp(CACTParser::PrimaryExpContext * ctx) override ;

    void enterUnaryExp(CACTParser::UnaryExpContext * ctx) override ;
    void exitUnaryExp(CACTParser::UnaryExpContext * ctx) override ;

    void enterUnaryOp(CACTParser::UnaryOpContext * ctx) override ;
    void exitUnaryOp(CACTParser::UnaryOpContext * ctx) override ;

    void enterFuncRParams(CACTParser::FuncRParamsContext * ctx) override ;
    void exitFuncRParams(CACTParser::FuncRParamsContext * ctx) override ;

    void enterMulExp(CACTParser::MulExpContext * ctx) override ;
    void exitMulExp(CACTParser::MulExpContext * ctx) override ;

    void enterAddExp(CACTParser::AddExpContext * ctx) override ;
    void exitAddExp(CACTParser::AddExpContext * ctx) override ;

    void enterRelExp(CACTParser::RelExpContext * ctx) override ;
    void exitRelExp(CACTParser::RelExpContext * ctx) override ;

    void enterEqExp(CACTParser::EqExpContext * ctx) override ;
    void exitEqExp(CACTParser::EqExpContext * ctx) override ;

    void enterLAndExp(CACTParser::LAndExpContext * ctx) override ;
    void exitLAndExp(CACTParser::LAndExpContext * ctx) override ;

    void enterLOrExp(CACTParser::LOrExpContext * ctx) override ;
    void exitLOrExp(CACTParser::LOrExpContext * ctx) override ;

    void enterConstExpNumber(CACTParser::ConstExpNumberContext * ctx) override ;
    void exitConstExpNumber(CACTParser::ConstExpNumberContext * ctx) override ;

    void enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext * ctx) override ;
    void exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext * ctx) override ;

    void enterNumberIntConst(CACTParser::NumberIntConstContext * ctx) override;
    void exitNumberIntConst(CACTParser::NumberIntConstContext * ctx) override;

    void enterNumberDoubleConst(CACTParser::NumberDoubleConstContext * ctx) override;
    void exitNumberDoubleConst(CACTParser::NumberDoubleConstContext * ctx) override;

    void enterNumberFloatConst(CACTParser::NumberFloatConstContext * ctx) override;
    void exitNumberFloatConst(CACTParser::NumberFloatConstContext * ctx) override;


    void enterEveryRule(antlr4::ParserRuleContext * ctx) override ;
    void exitEveryRule(antlr4::ParserRuleContext * ctx) override ;
    void visitTerminal(antlr4::tree::TerminalNode * node) override ;
    void visitErrorNode(antlr4::tree::ErrorNode * node) override ;
};