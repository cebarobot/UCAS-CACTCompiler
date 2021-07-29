#pragma once

#include "../grammar/CACTBaseListener.h"
#include "CACT.h"
#include "symbolTable.h"
#include "IRGenerator.h"

class SemanticAnalysis : public CACTBaseListener {
private:
    BlockInfo * globalBlock;

    BlockInfo * currentBlock;
    SymbolInfo * currentSymbol;
    FuncSymbolInfo * currentFunc;
    DataType currentDataType;
    
    IRGenerator * irGen;
public:
    SemanticAnalysis(BlockInfo * globalBlock, IRGenerator * newIRGen);
    ~SemanticAnalysis(){}


    void enterCompUnit(CACTParser::CompUnitContext * ctx) override;
    void exitCompUnit(CACTParser::CompUnitContext * ctx) override;

    void enterBType(CACTParser::BTypeContext * ctx) override;
    void exitBType(CACTParser::BTypeContext * ctx) override;

    void enterDecl(CACTParser::DeclContext * ctx) override;
    void exitDecl(CACTParser::DeclContext * ctx) override;

    void enterConstDecl(CACTParser::ConstDeclContext * ctx) override;
    void exitConstDecl(CACTParser::ConstDeclContext * ctx) override;

    void enterConstDefBasic(CACTParser::ConstDefBasicContext * ctx) override;
    void exitConstDefBasic(CACTParser::ConstDefBasicContext * ctx) override;

    void enterConstDefArray(CACTParser::ConstDefArrayContext * ctx) override;
    void exitConstDefArray(CACTParser::ConstDefArrayContext * ctx) override;
  
    void enterVarDecl(CACTParser::VarDeclContext * ctx) override;
    void exitVarDecl(CACTParser::VarDeclContext * ctx) override;

    void enterVarDefBasic(CACTParser::VarDefBasicContext * ctx) override;
    void exitVarDefBasic(CACTParser::VarDefBasicContext * ctx) override;

    void enterVarDefArray(CACTParser::VarDefArrayContext * ctx) override;
    void exitVarDefArray(CACTParser::VarDefArrayContext * ctx) override;

    void enterFuncDef(CACTParser::FuncDefContext * ctx) override;
    void exitFuncDef(CACTParser::FuncDefContext * ctx) override;

    void enterFuncType(CACTParser::FuncTypeContext * ctx) override;
    void exitFuncType(CACTParser::FuncTypeContext * ctx) override;

    void enterFuncFParams(CACTParser::FuncFParamsContext * ctx) override;
    void exitFuncFParams(CACTParser::FuncFParamsContext * ctx) override;

    void enterFuncFParam(CACTParser::FuncFParamContext * ctx) override;
    void exitFuncFParam(CACTParser::FuncFParamContext * ctx) override;

    void enterBlock(CACTParser::BlockContext * ctx) override;
    void exitBlock(CACTParser::BlockContext * ctx) override;

    void enterBlockItem(CACTParser::BlockItemContext * ctx) override;
    void exitBlockItem(CACTParser::BlockItemContext * ctx) override;

    void enterStmtAssign(CACTParser::StmtAssignContext * ctx) override;
    void exitStmtAssign(CACTParser::StmtAssignContext * ctx) override;

    void enterStmtExp(CACTParser::StmtExpContext * ctx) override;
    void exitStmtExp(CACTParser::StmtExpContext * ctx) override;

    void enterStmtBlock(CACTParser::StmtBlockContext * ctx) override;
    void exitStmtBlock(CACTParser::StmtBlockContext * ctx) override;

    void enterStmtCtrlIf(CACTParser::StmtCtrlIfContext * ctx) override;
    void exitStmtCtrlIf(CACTParser::StmtCtrlIfContext * ctx) override;

    void enterStmtCtrlIfElse(CACTParser::StmtCtrlIfElseContext * ctx) override;
    void exitStmtCtrlIfElse(CACTParser::StmtCtrlIfElseContext * ctx) override;

    void enterStmtCtrlWhile(CACTParser::StmtCtrlWhileContext * ctx) override;
    void exitStmtCtrlWhile(CACTParser::StmtCtrlWhileContext * ctx) override;

    void enterStmtCtrlBreak(CACTParser::StmtCtrlBreakContext * ctx) override;
    void exitStmtCtrlBreak(CACTParser::StmtCtrlBreakContext * ctx) override;

    void enterStmtCtrlContinue(CACTParser::StmtCtrlContinueContext * ctx) override;
    void exitStmtCtrlContinue(CACTParser::StmtCtrlContinueContext * ctx) override;

    void enterStmtReturn(CACTParser::StmtReturnContext * ctx) override;
    void exitStmtReturn(CACTParser::StmtReturnContext * ctx) override;

    void enterExpAddExp(CACTParser::ExpAddExpContext * ctx) override;
    void exitExpAddExp(CACTParser::ExpAddExpContext * ctx) override;

    void enterExpBoolConst(CACTParser::ExpBoolConstContext * ctx) override;
    void exitExpBoolConst(CACTParser::ExpBoolConstContext * ctx) override;

    void enterCond(CACTParser::CondContext * ctx) override;
    void exitCond(CACTParser::CondContext * ctx) override;

    void enterPrimaryExpExp(CACTParser::PrimaryExpExpContext * ctx) override;
    void exitPrimaryExpExp(CACTParser::PrimaryExpExpContext * ctx) override;

    void enterPrimaryExpRVal(CACTParser::PrimaryExpRValContext * ctx) override;
    void exitPrimaryExpRVal(CACTParser::PrimaryExpRValContext * ctx) override;

    void enterPrimaryNumVal(CACTParser::PrimaryNumValContext * ctx) override;
    void exitPrimaryNumVal(CACTParser::PrimaryNumValContext * ctx) override;

    void enterUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * ctx) override;
    void exitUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * ctx) override;

    void enterUnaryExpFunc(CACTParser::UnaryExpFuncContext * ctx) override;
    void exitUnaryExpFunc(CACTParser::UnaryExpFuncContext * ctx) override;

    void enterUnaryExpUnaryOp(CACTParser::UnaryExpUnaryOpContext * ctx) override;
    void exitUnaryExpUnaryOp(CACTParser::UnaryExpUnaryOpContext * ctx) override;

    void enterUnaryOp(CACTParser::UnaryOpContext * ctx) override;
    void exitUnaryOp(CACTParser::UnaryOpContext * ctx) override;

    void enterMulOp(CACTParser::MulOpContext * ctx) override;
    void exitMulOp(CACTParser::MulOpContext * ctx) override;

    void enterMulExpMulExp(CACTParser::MulExpMulExpContext * ctx) override;
    void exitMulExpMulExp(CACTParser::MulExpMulExpContext * ctx) override;

    void enterMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * ctx) override;
    void exitMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * ctx) override;

    void enterAddOp(CACTParser::AddOpContext * ctx) override;
    void exitAddOp(CACTParser::AddOpContext * ctx) override;

    void enterAddExpAddExp(CACTParser::AddExpAddExpContext * ctx) override;
    void exitAddExpAddExp(CACTParser::AddExpAddExpContext * ctx) override;

    void enterAddExpMulExp(CACTParser::AddExpMulExpContext * ctx) override;
    void exitAddExpMulExp(CACTParser::AddExpMulExpContext * ctx) override;

    void enterRelOp(CACTParser::RelOpContext * ctx) override;
    void exitRelOp(CACTParser::RelOpContext * ctx) override;

    void enterRelExpRelExp(CACTParser::RelExpRelExpContext * ctx) override;
    void exitRelExpRelExp(CACTParser::RelExpRelExpContext * ctx) override;

    void enterRelExpAddExp(CACTParser::RelExpAddExpContext * ctx) override;
    void exitRelExpAddExp(CACTParser::RelExpAddExpContext * ctx) override;

    void enterRelExpBoolVal(CACTParser::RelExpBoolValContext * ctx) override;
    void exitRelExpBoolVal(CACTParser::RelExpBoolValContext * ctx) override;

    void enterEqOp(CACTParser::EqOpContext * ctx) override;
    void exitEqOp(CACTParser::EqOpContext * ctx) override;

    void enterEqExpRelExp(CACTParser::EqExpRelExpContext * ctx) override;
    void exitEqExpRelExp(CACTParser::EqExpRelExpContext * ctx) override;

    void enterEqExpEqExp(CACTParser::EqExpEqExpContext * ctx) override;
    void exitEqExpEqExp(CACTParser::EqExpEqExpContext * ctx) override;

    void enterLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * ctx) override;
    void exitLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * ctx) override;

    void enterLAndExpEqExp(CACTParser::LAndExpEqExpContext * ctx) override;
    void exitLAndExpEqExp(CACTParser::LAndExpEqExpContext * ctx) override;

    void enterLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * ctx) override;
    void exitLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * ctx) override;

    void enterLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * ctx) override;
    void exitLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * ctx) override;

    void enterConstExpNumVal(CACTParser::ConstExpNumValContext * ctx) override;
    void exitConstExpNumVal(CACTParser::ConstExpNumValContext * ctx) override;

    void enterConstArrExp(CACTParser::ConstArrExpContext * ctx) override;
    void exitConstArrExp(CACTParser::ConstArrExpContext * ctx) override;

    void enterConstExpBoolVal(CACTParser::ConstExpBoolValContext * ctx) override;
    void exitConstExpBoolVal(CACTParser::ConstExpBoolValContext * ctx) override;

    void enterNumValIntConst(CACTParser::NumValIntConstContext * ctx) override;
    void exitNumValIntConst(CACTParser::NumValIntConstContext * ctx) override;

    void enterNumValDoubleConst(CACTParser::NumValDoubleConstContext * ctx) override;
    void exitNumValDoubleConst(CACTParser::NumValDoubleConstContext * ctx) override;

    void enterNumValFloatConst(CACTParser::NumValFloatConstContext * ctx) override;
    void exitNumValFloatConst(CACTParser::NumValFloatConstContext * ctx) override;

    void enterBoolVal(CACTParser::BoolValContext * ctx) override;
    void exitBoolVal(CACTParser::BoolValContext * ctx) override;

    void enterLValBasic(CACTParser::LValBasicContext * ctx) override;
    void exitLValBasic(CACTParser::LValBasicContext * ctx) override;

    void enterLValIndexed(CACTParser::LValIndexedContext * ctx) override;
    void exitLValIndexed(CACTParser::LValIndexedContext * ctx) override;

    void enterRValBasic(CACTParser::RValBasicContext * ctx) override;
    void exitRValBasic(CACTParser::RValBasicContext * ctx) override;

    void enterRValIndexed(CACTParser::RValIndexedContext * ctx) override;
    void exitRValIndexed(CACTParser::RValIndexedContext * ctx) override;

    void enterFuncVal(CACTParser::FuncValContext * ctx) override;
    void exitFuncVal(CACTParser::FuncValContext * ctx) override;

    void enterFuncRParams(CACTParser::FuncRParamsContext * ctx) override;
    void exitFuncRParams(CACTParser::FuncRParamsContext * ctx) override;

    void enterEveryRule(antlr4::ParserRuleContext * ctx) override;
    void exitEveryRule(antlr4::ParserRuleContext * ctx) override;
    void visitTerminal(antlr4::tree::TerminalNode * node) override;
    void visitErrorNode(antlr4::tree::ErrorNode * node) override;
};