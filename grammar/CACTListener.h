
    #include <vector>
    #include <string>


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

  virtual void enterConstInitVal(CACTParser::ConstInitValContext *ctx) = 0;
  virtual void exitConstInitVal(CACTParser::ConstInitValContext *ctx) = 0;

  virtual void enterVarDecl(CACTParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(CACTParser::VarDeclContext *ctx) = 0;

  virtual void enterVarDef(CACTParser::VarDefContext *ctx) = 0;
  virtual void exitVarDef(CACTParser::VarDefContext *ctx) = 0;

  virtual void enterConstExpNumber(CACTParser::ConstExpNumberContext *ctx) = 0;
  virtual void exitConstExpNumber(CACTParser::ConstExpNumberContext *ctx) = 0;

  virtual void enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext *ctx) = 0;
  virtual void exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext *ctx) = 0;

  virtual void enterNumber(CACTParser::NumberContext *ctx) = 0;
  virtual void exitNumber(CACTParser::NumberContext *ctx) = 0;


};

