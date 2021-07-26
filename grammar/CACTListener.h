
    #include <vector>
    #include <string>
    #include "../src/symbolTable.h"
    #include "../src/IR.h"


// Generated from CACT.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "CACTParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CACTParser.
 */
class  CACTListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompUnit(CACTParser::CompUnitContext *ctx) = 0;
  virtual void exitCompUnit(CACTParser::CompUnitContext *ctx) = 0;

  virtual void enterDecl(CACTParser::DeclContext *ctx) = 0;
  virtual void exitDecl(CACTParser::DeclContext *ctx) = 0;

  virtual void enterConstDecl(CACTParser::ConstDeclContext *ctx) = 0;
  virtual void exitConstDecl(CACTParser::ConstDeclContext *ctx) = 0;

  virtual void enterBType(CACTParser::BTypeContext *ctx) = 0;
  virtual void exitBType(CACTParser::BTypeContext *ctx) = 0;

  virtual void enterConstDef(CACTParser::ConstDefContext *ctx) = 0;
  virtual void exitConstDef(CACTParser::ConstDefContext *ctx) = 0;

  virtual void enterConstInitValBasic(CACTParser::ConstInitValBasicContext *ctx) = 0;
  virtual void exitConstInitValBasic(CACTParser::ConstInitValBasicContext *ctx) = 0;

  virtual void enterConstInitValArray(CACTParser::ConstInitValArrayContext *ctx) = 0;
  virtual void exitConstInitValArray(CACTParser::ConstInitValArrayContext *ctx) = 0;

  virtual void enterVarDecl(CACTParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(CACTParser::VarDeclContext *ctx) = 0;

  virtual void enterVarDef(CACTParser::VarDefContext *ctx) = 0;
  virtual void exitVarDef(CACTParser::VarDefContext *ctx) = 0;

  virtual void enterFuncDef(CACTParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(CACTParser::FuncDefContext *ctx) = 0;

  virtual void enterFuncType(CACTParser::FuncTypeContext *ctx) = 0;
  virtual void exitFuncType(CACTParser::FuncTypeContext *ctx) = 0;

  virtual void enterFuncFParams(CACTParser::FuncFParamsContext *ctx) = 0;
  virtual void exitFuncFParams(CACTParser::FuncFParamsContext *ctx) = 0;

  virtual void enterFuncFParam(CACTParser::FuncFParamContext *ctx) = 0;
  virtual void exitFuncFParam(CACTParser::FuncFParamContext *ctx) = 0;

  virtual void enterBlock(CACTParser::BlockContext *ctx) = 0;
  virtual void exitBlock(CACTParser::BlockContext *ctx) = 0;

  virtual void enterBlockItem(CACTParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(CACTParser::BlockItemContext *ctx) = 0;

  virtual void enterStmtAssign(CACTParser::StmtAssignContext *ctx) = 0;
  virtual void exitStmtAssign(CACTParser::StmtAssignContext *ctx) = 0;

  virtual void enterStmtExp(CACTParser::StmtExpContext *ctx) = 0;
  virtual void exitStmtExp(CACTParser::StmtExpContext *ctx) = 0;

  virtual void enterStmtBlock(CACTParser::StmtBlockContext *ctx) = 0;
  virtual void exitStmtBlock(CACTParser::StmtBlockContext *ctx) = 0;

  virtual void enterStmtCtrlIf(CACTParser::StmtCtrlIfContext *ctx) = 0;
  virtual void exitStmtCtrlIf(CACTParser::StmtCtrlIfContext *ctx) = 0;

  virtual void enterStmtCtrlWhile(CACTParser::StmtCtrlWhileContext *ctx) = 0;
  virtual void exitStmtCtrlWhile(CACTParser::StmtCtrlWhileContext *ctx) = 0;

  virtual void enterStmtCtrlBreak(CACTParser::StmtCtrlBreakContext *ctx) = 0;
  virtual void exitStmtCtrlBreak(CACTParser::StmtCtrlBreakContext *ctx) = 0;

  virtual void enterStmtCtrlContinue(CACTParser::StmtCtrlContinueContext *ctx) = 0;
  virtual void exitStmtCtrlContinue(CACTParser::StmtCtrlContinueContext *ctx) = 0;

  virtual void enterStmtReturn(CACTParser::StmtReturnContext *ctx) = 0;
  virtual void exitStmtReturn(CACTParser::StmtReturnContext *ctx) = 0;

  virtual void enterExpAddExp(CACTParser::ExpAddExpContext *ctx) = 0;
  virtual void exitExpAddExp(CACTParser::ExpAddExpContext *ctx) = 0;

  virtual void enterExpBoolConst(CACTParser::ExpBoolConstContext *ctx) = 0;
  virtual void exitExpBoolConst(CACTParser::ExpBoolConstContext *ctx) = 0;

  virtual void enterCond(CACTParser::CondContext *ctx) = 0;
  virtual void exitCond(CACTParser::CondContext *ctx) = 0;

  virtual void enterLVal(CACTParser::LValContext *ctx) = 0;
  virtual void exitLVal(CACTParser::LValContext *ctx) = 0;

  virtual void enterPrimaryExpExp(CACTParser::PrimaryExpExpContext *ctx) = 0;
  virtual void exitPrimaryExpExp(CACTParser::PrimaryExpExpContext *ctx) = 0;

  virtual void enterPrimaryExpLVal(CACTParser::PrimaryExpLValContext *ctx) = 0;
  virtual void exitPrimaryExpLVal(CACTParser::PrimaryExpLValContext *ctx) = 0;

  virtual void enterPrimaryNumber(CACTParser::PrimaryNumberContext *ctx) = 0;
  virtual void exitPrimaryNumber(CACTParser::PrimaryNumberContext *ctx) = 0;

  virtual void enterUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext *ctx) = 0;
  virtual void exitUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext *ctx) = 0;

  virtual void enterUnaryExpFunc(CACTParser::UnaryExpFuncContext *ctx) = 0;
  virtual void exitUnaryExpFunc(CACTParser::UnaryExpFuncContext *ctx) = 0;

  virtual void enterUnaryExpUnaryOp(CACTParser::UnaryExpUnaryOpContext *ctx) = 0;
  virtual void exitUnaryExpUnaryOp(CACTParser::UnaryExpUnaryOpContext *ctx) = 0;

  virtual void enterUnaryOp(CACTParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(CACTParser::UnaryOpContext *ctx) = 0;

  virtual void enterFuncRParams(CACTParser::FuncRParamsContext *ctx) = 0;
  virtual void exitFuncRParams(CACTParser::FuncRParamsContext *ctx) = 0;

  virtual void enterMulExpMulExp(CACTParser::MulExpMulExpContext *ctx) = 0;
  virtual void exitMulExpMulExp(CACTParser::MulExpMulExpContext *ctx) = 0;

  virtual void enterMulExpUnaryExp(CACTParser::MulExpUnaryExpContext *ctx) = 0;
  virtual void exitMulExpUnaryExp(CACTParser::MulExpUnaryExpContext *ctx) = 0;

  virtual void enterMulOp(CACTParser::MulOpContext *ctx) = 0;
  virtual void exitMulOp(CACTParser::MulOpContext *ctx) = 0;

  virtual void enterAddExpAddExp(CACTParser::AddExpAddExpContext *ctx) = 0;
  virtual void exitAddExpAddExp(CACTParser::AddExpAddExpContext *ctx) = 0;

  virtual void enterAddExpMulExp(CACTParser::AddExpMulExpContext *ctx) = 0;
  virtual void exitAddExpMulExp(CACTParser::AddExpMulExpContext *ctx) = 0;

  virtual void enterAddOp(CACTParser::AddOpContext *ctx) = 0;
  virtual void exitAddOp(CACTParser::AddOpContext *ctx) = 0;

  virtual void enterRelExpRelExp(CACTParser::RelExpRelExpContext *ctx) = 0;
  virtual void exitRelExpRelExp(CACTParser::RelExpRelExpContext *ctx) = 0;

  virtual void enterRelExpAddExp(CACTParser::RelExpAddExpContext *ctx) = 0;
  virtual void exitRelExpAddExp(CACTParser::RelExpAddExpContext *ctx) = 0;

  virtual void enterRelExpBoolConst(CACTParser::RelExpBoolConstContext *ctx) = 0;
  virtual void exitRelExpBoolConst(CACTParser::RelExpBoolConstContext *ctx) = 0;

  virtual void enterRelOp(CACTParser::RelOpContext *ctx) = 0;
  virtual void exitRelOp(CACTParser::RelOpContext *ctx) = 0;

  virtual void enterEqExpRelExp(CACTParser::EqExpRelExpContext *ctx) = 0;
  virtual void exitEqExpRelExp(CACTParser::EqExpRelExpContext *ctx) = 0;

  virtual void enterEqExpEqExp(CACTParser::EqExpEqExpContext *ctx) = 0;
  virtual void exitEqExpEqExp(CACTParser::EqExpEqExpContext *ctx) = 0;

  virtual void enterEqOp(CACTParser::EqOpContext *ctx) = 0;
  virtual void exitEqOp(CACTParser::EqOpContext *ctx) = 0;

  virtual void enterLAndExpLAndExp(CACTParser::LAndExpLAndExpContext *ctx) = 0;
  virtual void exitLAndExpLAndExp(CACTParser::LAndExpLAndExpContext *ctx) = 0;

  virtual void enterLAndExpEqExp(CACTParser::LAndExpEqExpContext *ctx) = 0;
  virtual void exitLAndExpEqExp(CACTParser::LAndExpEqExpContext *ctx) = 0;

  virtual void enterLOrExpLAndExp(CACTParser::LOrExpLAndExpContext *ctx) = 0;
  virtual void exitLOrExpLAndExp(CACTParser::LOrExpLAndExpContext *ctx) = 0;

  virtual void enterLOrExpLOrExp(CACTParser::LOrExpLOrExpContext *ctx) = 0;
  virtual void exitLOrExpLOrExp(CACTParser::LOrExpLOrExpContext *ctx) = 0;

  virtual void enterConstExpNumber(CACTParser::ConstExpNumberContext *ctx) = 0;
  virtual void exitConstExpNumber(CACTParser::ConstExpNumberContext *ctx) = 0;

  virtual void enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext *ctx) = 0;
  virtual void exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext *ctx) = 0;

  virtual void enterNumberIntConst(CACTParser::NumberIntConstContext *ctx) = 0;
  virtual void exitNumberIntConst(CACTParser::NumberIntConstContext *ctx) = 0;

  virtual void enterNumberDoubleConst(CACTParser::NumberDoubleConstContext *ctx) = 0;
  virtual void exitNumberDoubleConst(CACTParser::NumberDoubleConstContext *ctx) = 0;

  virtual void enterNumberFloatConst(CACTParser::NumberFloatConstContext *ctx) = 0;
  virtual void exitNumberFloatConst(CACTParser::NumberFloatConstContext *ctx) = 0;


};

