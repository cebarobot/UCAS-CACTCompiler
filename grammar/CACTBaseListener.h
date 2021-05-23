
    #include <vector>
    #include <string>
    #include "../src/symbolTable.h"


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

  virtual void enterDecl(CACTParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(CACTParser::DeclContext * /*ctx*/) override { }

  virtual void enterConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override { }
  virtual void exitConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override { }

  virtual void enterBType(CACTParser::BTypeContext * /*ctx*/) override { }
  virtual void exitBType(CACTParser::BTypeContext * /*ctx*/) override { }

  virtual void enterConstDef(CACTParser::ConstDefContext * /*ctx*/) override { }
  virtual void exitConstDef(CACTParser::ConstDefContext * /*ctx*/) override { }

  virtual void enterConstInitValBasic(CACTParser::ConstInitValBasicContext * /*ctx*/) override { }
  virtual void exitConstInitValBasic(CACTParser::ConstInitValBasicContext * /*ctx*/) override { }

  virtual void enterConstInitValArray(CACTParser::ConstInitValArrayContext * /*ctx*/) override { }
  virtual void exitConstInitValArray(CACTParser::ConstInitValArrayContext * /*ctx*/) override { }

  virtual void enterVarDecl(CACTParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(CACTParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterVarDef(CACTParser::VarDefContext * /*ctx*/) override { }
  virtual void exitVarDef(CACTParser::VarDefContext * /*ctx*/) override { }

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

  virtual void enterStmt(CACTParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(CACTParser::StmtContext * /*ctx*/) override { }

  virtual void enterExp(CACTParser::ExpContext * /*ctx*/) override { }
  virtual void exitExp(CACTParser::ExpContext * /*ctx*/) override { }

  virtual void enterCond(CACTParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(CACTParser::CondContext * /*ctx*/) override { }

  virtual void enterLVal(CACTParser::LValContext * /*ctx*/) override { }
  virtual void exitLVal(CACTParser::LValContext * /*ctx*/) override { }

  virtual void enterPrimaryExp(CACTParser::PrimaryExpContext * /*ctx*/) override { }
  virtual void exitPrimaryExp(CACTParser::PrimaryExpContext * /*ctx*/) override { }

  virtual void enterUnaryExp(CACTParser::UnaryExpContext * /*ctx*/) override { }
  virtual void exitUnaryExp(CACTParser::UnaryExpContext * /*ctx*/) override { }

  virtual void enterUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }
  virtual void exitFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }

  virtual void enterMulExp(CACTParser::MulExpContext * /*ctx*/) override { }
  virtual void exitMulExp(CACTParser::MulExpContext * /*ctx*/) override { }

  virtual void enterAddExp(CACTParser::AddExpContext * /*ctx*/) override { }
  virtual void exitAddExp(CACTParser::AddExpContext * /*ctx*/) override { }

  virtual void enterRelExp(CACTParser::RelExpContext * /*ctx*/) override { }
  virtual void exitRelExp(CACTParser::RelExpContext * /*ctx*/) override { }

  virtual void enterEqExp(CACTParser::EqExpContext * /*ctx*/) override { }
  virtual void exitEqExp(CACTParser::EqExpContext * /*ctx*/) override { }

  virtual void enterLAndExp(CACTParser::LAndExpContext * /*ctx*/) override { }
  virtual void exitLAndExp(CACTParser::LAndExpContext * /*ctx*/) override { }

  virtual void enterLOrExp(CACTParser::LOrExpContext * /*ctx*/) override { }
  virtual void exitLOrExp(CACTParser::LOrExpContext * /*ctx*/) override { }

  virtual void enterConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override { }
  virtual void exitConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override { }

  virtual void enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override { }
  virtual void exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override { }

  virtual void enterNumberIntConst(CACTParser::NumberIntConstContext * /*ctx*/) override { }
  virtual void exitNumberIntConst(CACTParser::NumberIntConstContext * /*ctx*/) override { }

  virtual void enterNumberDoubleConst(CACTParser::NumberDoubleConstContext * /*ctx*/) override { }
  virtual void exitNumberDoubleConst(CACTParser::NumberDoubleConstContext * /*ctx*/) override { }

  virtual void enterNumberFloatConst(CACTParser::NumberFloatConstContext * /*ctx*/) override { }
  virtual void exitNumberFloatConst(CACTParser::NumberFloatConstContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

