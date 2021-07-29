
    #include <vector>
    #include <string>
    #include "../src/CACT.h"
    #include "../src/symbolTable.h"
    #include "../src/IR.h"


// Generated from CACT.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "CACTListener.h"


/**
 * This class provides an empty implementation of CACTListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CACTBaseListener : public CACTListener {
public:

  virtual void enterCompUnit(CACTParser::CompUnitContext * /*ctx*/) override { }
  virtual void exitCompUnit(CACTParser::CompUnitContext * /*ctx*/) override { }

  virtual void enterBType(CACTParser::BTypeContext * /*ctx*/) override { }
  virtual void exitBType(CACTParser::BTypeContext * /*ctx*/) override { }

  virtual void enterDecl(CACTParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(CACTParser::DeclContext * /*ctx*/) override { }

  virtual void enterConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override { }
  virtual void exitConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override { }

  virtual void enterConstDefBasic(CACTParser::ConstDefBasicContext * /*ctx*/) override { }
  virtual void exitConstDefBasic(CACTParser::ConstDefBasicContext * /*ctx*/) override { }

  virtual void enterConstDefArray(CACTParser::ConstDefArrayContext * /*ctx*/) override { }
  virtual void exitConstDefArray(CACTParser::ConstDefArrayContext * /*ctx*/) override { }

  virtual void enterVarDecl(CACTParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(CACTParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterVarDefBasic(CACTParser::VarDefBasicContext * /*ctx*/) override { }
  virtual void exitVarDefBasic(CACTParser::VarDefBasicContext * /*ctx*/) override { }

  virtual void enterVarDefArray(CACTParser::VarDefArrayContext * /*ctx*/) override { }
  virtual void exitVarDefArray(CACTParser::VarDefArrayContext * /*ctx*/) override { }

  virtual void enterFuncDef(CACTParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(CACTParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }
  virtual void exitFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }

  virtual void enterFuncFParams(CACTParser::FuncFParamsContext * /*ctx*/) override { }
  virtual void exitFuncFParams(CACTParser::FuncFParamsContext * /*ctx*/) override { }

  virtual void enterFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override { }
  virtual void exitFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override { }

  virtual void enterBlock(CACTParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(CACTParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlockItem(CACTParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(CACTParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterStmtAssign(CACTParser::StmtAssignContext * /*ctx*/) override { }
  virtual void exitStmtAssign(CACTParser::StmtAssignContext * /*ctx*/) override { }

  virtual void enterStmtExp(CACTParser::StmtExpContext * /*ctx*/) override { }
  virtual void exitStmtExp(CACTParser::StmtExpContext * /*ctx*/) override { }

  virtual void enterStmtBlock(CACTParser::StmtBlockContext * /*ctx*/) override { }
  virtual void exitStmtBlock(CACTParser::StmtBlockContext * /*ctx*/) override { }

  virtual void enterStmtCtrlIf(CACTParser::StmtCtrlIfContext * /*ctx*/) override { }
  virtual void exitStmtCtrlIf(CACTParser::StmtCtrlIfContext * /*ctx*/) override { }

  virtual void enterStmtCtrlIfElse(CACTParser::StmtCtrlIfElseContext * /*ctx*/) override { }
  virtual void exitStmtCtrlIfElse(CACTParser::StmtCtrlIfElseContext * /*ctx*/) override { }

  virtual void enterStmtCtrlWhile(CACTParser::StmtCtrlWhileContext * /*ctx*/) override { }
  virtual void exitStmtCtrlWhile(CACTParser::StmtCtrlWhileContext * /*ctx*/) override { }

  virtual void enterStmtCtrlBreak(CACTParser::StmtCtrlBreakContext * /*ctx*/) override { }
  virtual void exitStmtCtrlBreak(CACTParser::StmtCtrlBreakContext * /*ctx*/) override { }

  virtual void enterStmtCtrlContinue(CACTParser::StmtCtrlContinueContext * /*ctx*/) override { }
  virtual void exitStmtCtrlContinue(CACTParser::StmtCtrlContinueContext * /*ctx*/) override { }

  virtual void enterStmtReturn(CACTParser::StmtReturnContext * /*ctx*/) override { }
  virtual void exitStmtReturn(CACTParser::StmtReturnContext * /*ctx*/) override { }

  virtual void enterExpAddExp(CACTParser::ExpAddExpContext * /*ctx*/) override { }
  virtual void exitExpAddExp(CACTParser::ExpAddExpContext * /*ctx*/) override { }

  virtual void enterExpBoolConst(CACTParser::ExpBoolConstContext * /*ctx*/) override { }
  virtual void exitExpBoolConst(CACTParser::ExpBoolConstContext * /*ctx*/) override { }

  virtual void enterCond(CACTParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(CACTParser::CondContext * /*ctx*/) override { }

  virtual void enterPrimaryExpExp(CACTParser::PrimaryExpExpContext * /*ctx*/) override { }
  virtual void exitPrimaryExpExp(CACTParser::PrimaryExpExpContext * /*ctx*/) override { }

  virtual void enterPrimaryExpRVal(CACTParser::PrimaryExpRValContext * /*ctx*/) override { }
  virtual void exitPrimaryExpRVal(CACTParser::PrimaryExpRValContext * /*ctx*/) override { }

  virtual void enterPrimaryNumVal(CACTParser::PrimaryNumValContext * /*ctx*/) override { }
  virtual void exitPrimaryNumVal(CACTParser::PrimaryNumValContext * /*ctx*/) override { }

  virtual void enterUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * /*ctx*/) override { }
  virtual void exitUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * /*ctx*/) override { }

  virtual void enterUnaryExpFunc(CACTParser::UnaryExpFuncContext * /*ctx*/) override { }
  virtual void exitUnaryExpFunc(CACTParser::UnaryExpFuncContext * /*ctx*/) override { }

  virtual void enterUnaryExpUnaryOp(CACTParser::UnaryExpUnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryExpUnaryOp(CACTParser::UnaryExpUnaryOpContext * /*ctx*/) override { }

  virtual void enterUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterMulExpMulExp(CACTParser::MulExpMulExpContext * /*ctx*/) override { }
  virtual void exitMulExpMulExp(CACTParser::MulExpMulExpContext * /*ctx*/) override { }

  virtual void enterMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * /*ctx*/) override { }
  virtual void exitMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * /*ctx*/) override { }

  virtual void enterMulOp(CACTParser::MulOpContext * /*ctx*/) override { }
  virtual void exitMulOp(CACTParser::MulOpContext * /*ctx*/) override { }

  virtual void enterAddExpAddExp(CACTParser::AddExpAddExpContext * /*ctx*/) override { }
  virtual void exitAddExpAddExp(CACTParser::AddExpAddExpContext * /*ctx*/) override { }

  virtual void enterAddExpMulExp(CACTParser::AddExpMulExpContext * /*ctx*/) override { }
  virtual void exitAddExpMulExp(CACTParser::AddExpMulExpContext * /*ctx*/) override { }

  virtual void enterAddOp(CACTParser::AddOpContext * /*ctx*/) override { }
  virtual void exitAddOp(CACTParser::AddOpContext * /*ctx*/) override { }

  virtual void enterRelExpRelExp(CACTParser::RelExpRelExpContext * /*ctx*/) override { }
  virtual void exitRelExpRelExp(CACTParser::RelExpRelExpContext * /*ctx*/) override { }

  virtual void enterRelExpBoolVal(CACTParser::RelExpBoolValContext * /*ctx*/) override { }
  virtual void exitRelExpBoolVal(CACTParser::RelExpBoolValContext * /*ctx*/) override { }

  virtual void enterRelExpAddExp(CACTParser::RelExpAddExpContext * /*ctx*/) override { }
  virtual void exitRelExpAddExp(CACTParser::RelExpAddExpContext * /*ctx*/) override { }

  virtual void enterRelOp(CACTParser::RelOpContext * /*ctx*/) override { }
  virtual void exitRelOp(CACTParser::RelOpContext * /*ctx*/) override { }

  virtual void enterEqExpRelExp(CACTParser::EqExpRelExpContext * /*ctx*/) override { }
  virtual void exitEqExpRelExp(CACTParser::EqExpRelExpContext * /*ctx*/) override { }

  virtual void enterEqExpEqExp(CACTParser::EqExpEqExpContext * /*ctx*/) override { }
  virtual void exitEqExpEqExp(CACTParser::EqExpEqExpContext * /*ctx*/) override { }

  virtual void enterEqOp(CACTParser::EqOpContext * /*ctx*/) override { }
  virtual void exitEqOp(CACTParser::EqOpContext * /*ctx*/) override { }

  virtual void enterLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * /*ctx*/) override { }
  virtual void exitLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * /*ctx*/) override { }

  virtual void enterLAndExpEqExp(CACTParser::LAndExpEqExpContext * /*ctx*/) override { }
  virtual void exitLAndExpEqExp(CACTParser::LAndExpEqExpContext * /*ctx*/) override { }

  virtual void enterLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * /*ctx*/) override { }
  virtual void exitLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * /*ctx*/) override { }

  virtual void enterLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * /*ctx*/) override { }
  virtual void exitLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * /*ctx*/) override { }

  virtual void enterConstArrExp(CACTParser::ConstArrExpContext * /*ctx*/) override { }
  virtual void exitConstArrExp(CACTParser::ConstArrExpContext * /*ctx*/) override { }

  virtual void enterConstExpNumVal(CACTParser::ConstExpNumValContext * /*ctx*/) override { }
  virtual void exitConstExpNumVal(CACTParser::ConstExpNumValContext * /*ctx*/) override { }

  virtual void enterConstExpBoolVal(CACTParser::ConstExpBoolValContext * /*ctx*/) override { }
  virtual void exitConstExpBoolVal(CACTParser::ConstExpBoolValContext * /*ctx*/) override { }

  virtual void enterNumValIntConst(CACTParser::NumValIntConstContext * /*ctx*/) override { }
  virtual void exitNumValIntConst(CACTParser::NumValIntConstContext * /*ctx*/) override { }

  virtual void enterNumValDoubleConst(CACTParser::NumValDoubleConstContext * /*ctx*/) override { }
  virtual void exitNumValDoubleConst(CACTParser::NumValDoubleConstContext * /*ctx*/) override { }

  virtual void enterNumValFloatConst(CACTParser::NumValFloatConstContext * /*ctx*/) override { }
  virtual void exitNumValFloatConst(CACTParser::NumValFloatConstContext * /*ctx*/) override { }

  virtual void enterBoolVal(CACTParser::BoolValContext * /*ctx*/) override { }
  virtual void exitBoolVal(CACTParser::BoolValContext * /*ctx*/) override { }

  virtual void enterLValBasic(CACTParser::LValBasicContext * /*ctx*/) override { }
  virtual void exitLValBasic(CACTParser::LValBasicContext * /*ctx*/) override { }

  virtual void enterLValIndexed(CACTParser::LValIndexedContext * /*ctx*/) override { }
  virtual void exitLValIndexed(CACTParser::LValIndexedContext * /*ctx*/) override { }

  virtual void enterRValBasic(CACTParser::RValBasicContext * /*ctx*/) override { }
  virtual void exitRValBasic(CACTParser::RValBasicContext * /*ctx*/) override { }

  virtual void enterRValIndexed(CACTParser::RValIndexedContext * /*ctx*/) override { }
  virtual void exitRValIndexed(CACTParser::RValIndexedContext * /*ctx*/) override { }

  virtual void enterFuncVal(CACTParser::FuncValContext * /*ctx*/) override { }
  virtual void exitFuncVal(CACTParser::FuncValContext * /*ctx*/) override { }

  virtual void enterFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }
  virtual void exitFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

