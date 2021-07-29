
    #include <vector>
    #include <string>
    #include "../src/CACT.h"
    #include "../src/symbolTable.h"
    #include "../src/IR.h"


// Generated from CACT.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  CACTParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, BoolConst = 36, Ident = 37, IntConst = 38, 
    FloatConst = 39, DoubleConst = 40, ArraySymbol = 41, NewLine = 42, WhiteSpace = 43, 
    BlockComment = 44, LineComment = 45
  };

  enum {
    RuleCompUnit = 0, RuleBType = 1, RuleDecl = 2, RuleConstDecl = 3, RuleConstDef = 4, 
    RuleVarDecl = 5, RuleVarDef = 6, RuleFuncDef = 7, RuleFuncType = 8, 
    RuleFuncFParams = 9, RuleFuncFParam = 10, RuleBlock = 11, RuleBlockItem = 12, 
    RuleStmt = 13, RuleExp = 14, RuleCond = 15, RulePrimaryExp = 16, RuleUnaryExp = 17, 
    RuleUnaryOp = 18, RuleMulExp = 19, RuleMulOp = 20, RuleAddExp = 21, 
    RuleAddOp = 22, RuleRelExp = 23, RuleRelOp = 24, RuleEqExp = 25, RuleEqOp = 26, 
    RuleLAndExp = 27, RuleLOrExp = 28, RuleConstArrExp = 29, RuleConstExp = 30, 
    RuleNumVal = 31, RuleBoolVal = 32, RuleLVal = 33, RuleRVal = 34, RuleFuncVal = 35, 
    RuleFuncRParams = 36
  };

  CACTParser(antlr4::TokenStream *input);
  ~CACTParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CompUnitContext;
  class BTypeContext;
  class DeclContext;
  class ConstDeclContext;
  class ConstDefContext;
  class VarDeclContext;
  class VarDefContext;
  class FuncDefContext;
  class FuncTypeContext;
  class FuncFParamsContext;
  class FuncFParamContext;
  class BlockContext;
  class BlockItemContext;
  class StmtContext;
  class ExpContext;
  class CondContext;
  class PrimaryExpContext;
  class UnaryExpContext;
  class UnaryOpContext;
  class MulExpContext;
  class MulOpContext;
  class AddExpContext;
  class AddOpContext;
  class RelExpContext;
  class RelOpContext;
  class EqExpContext;
  class EqOpContext;
  class LAndExpContext;
  class LOrExpContext;
  class ConstArrExpContext;
  class ConstExpContext;
  class NumValContext;
  class BoolValContext;
  class LValContext;
  class RValContext;
  class FuncValContext;
  class FuncRParamsContext; 

  class  CompUnitContext : public antlr4::ParserRuleContext {
  public:
    CompUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DeclContext *> decl();
    DeclContext* decl(size_t i);
    std::vector<FuncDefContext *> funcDef();
    FuncDefContext* funcDef(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CompUnitContext* compUnit();

  class  BTypeContext : public antlr4::ParserRuleContext {
  public:
    DataType bDataType;
    BTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BTypeContext* bType();

  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstDeclContext *constDecl();
    VarDeclContext *varDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DeclContext* decl();

  class  ConstDeclContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    std::vector<ConstDefContext *> constDef();
    ConstDefContext* constDef(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConstDeclContext* constDecl();

  class  ConstDefContext : public antlr4::ParserRuleContext {
  public:
    SymbolInfo * thisSymbolInfo;
    ConstDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstDefContext() = default;
    void copyFrom(ConstDefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstDefArrayContext : public ConstDefContext {
  public:
    ConstDefArrayContext(ConstDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    antlr4::tree::TerminalNode *IntConst();
    ConstArrExpContext *constArrExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ConstDefBasicContext : public ConstDefContext {
  public:
    ConstDefBasicContext(ConstDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    ConstExpContext *constExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ConstDefContext* constDef();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    std::vector<VarDefContext *> varDef();
    VarDefContext* varDef(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VarDeclContext* varDecl();

  class  VarDefContext : public antlr4::ParserRuleContext {
  public:
    SymbolInfo * thisSymbolInfo;
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VarDefContext() = default;
    void copyFrom(VarDefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VarDefBasicContext : public VarDefContext {
  public:
    VarDefBasicContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    ConstExpContext *constExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  VarDefArrayContext : public VarDefContext {
  public:
    VarDefArrayContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    antlr4::tree::TerminalNode *IntConst();
    ConstArrExpContext *constArrExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  VarDefContext* varDef();

  class  FuncDefContext : public antlr4::ParserRuleContext {
  public:
    FuncSymbolInfo * thisFuncInfo;
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncTypeContext *funcType();
    antlr4::tree::TerminalNode *Ident();
    BlockContext *block();
    FuncFParamsContext *funcFParams();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncDefContext* funcDef();

  class  FuncTypeContext : public antlr4::ParserRuleContext {
  public:
    FuncTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncTypeContext* funcType();

  class  FuncFParamsContext : public antlr4::ParserRuleContext {
  public:
    FuncSymbolInfo * thisFuncInfo;
    FuncFParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FuncFParamContext *> funcFParam();
    FuncFParamContext* funcFParam(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncFParamsContext* funcFParams();

  class  FuncFParamContext : public antlr4::ParserRuleContext {
  public:
    DataType bDataType;
    FuncFParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    antlr4::tree::TerminalNode *Ident();
    antlr4::tree::TerminalNode *ArraySymbol();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncFParamContext* funcFParam();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    FuncSymbolInfo * thisFuncInfo;
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BlockItemContext *> blockItem();
    BlockItemContext* blockItem(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockContext* block();

  class  BlockItemContext : public antlr4::ParserRuleContext {
  public:
    BlockItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclContext *decl();
    StmtContext *stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockItemContext* blockItem();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    IRLabel * flowNext = nullptr;
    IRLabel * flowEnd = nullptr;
    std::vector<IRCode *> codeBefore;
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() = default;
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StmtCtrlBreakContext : public StmtContext {
  public:
    StmtCtrlBreakContext(StmtContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StmtExpContext : public StmtContext {
  public:
    StmtExpContext(StmtContext *ctx);

    ExpContext *exp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StmtBlockContext : public StmtContext {
  public:
    StmtBlockContext(StmtContext *ctx);

    BlockContext *block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StmtCtrlContinueContext : public StmtContext {
  public:
    StmtCtrlContinueContext(StmtContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StmtCtrlWhileContext : public StmtContext {
  public:
    StmtCtrlWhileContext(StmtContext *ctx);

    CondContext *cond();
    StmtContext *stmt();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StmtReturnContext : public StmtContext {
  public:
    StmtReturnContext(StmtContext *ctx);

    ExpContext *exp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StmtAssignContext : public StmtContext {
  public:
    StmtAssignContext(StmtContext *ctx);

    LValContext *lVal();
    ExpContext *exp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StmtCtrlIfContext : public StmtContext {
  public:
    StmtCtrlIfContext(StmtContext *ctx);

    CondContext *cond();
    StmtContext *stmt();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StmtCtrlIfElseContext : public StmtContext {
  public:
    StmtCtrlIfElseContext(StmtContext *ctx);

    CondContext *cond();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  StmtContext* stmt();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    int arraySize;
    DataType dataType;
    IROperand * result;
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpContext() = default;
    void copyFrom(ExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExpAddExpContext : public ExpContext {
  public:
    ExpAddExpContext(ExpContext *ctx);

    AddExpContext *addExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ExpBoolConstContext : public ExpContext {
  public:
    ExpBoolConstContext(ExpContext *ctx);

    BoolValContext *boolVal();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ExpContext* exp();

  class  CondContext : public antlr4::ParserRuleContext {
  public:
    IRLabel * flowTrue = nullptr;
    IRLabel * flowFalse = nullptr;
    DataType dataType;
    IROperand * result;
    CondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LOrExpContext *lOrExp();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CondContext* cond();

  class  PrimaryExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    int arraySize;
    DataType dataType;
    IROperand * result;
    PrimaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrimaryExpContext() = default;
    void copyFrom(PrimaryExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PrimaryExpExpContext : public PrimaryExpContext {
  public:
    PrimaryExpExpContext(PrimaryExpContext *ctx);

    ExpContext *exp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  PrimaryExpRValContext : public PrimaryExpContext {
  public:
    PrimaryExpRValContext(PrimaryExpContext *ctx);

    RValContext *rVal();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  PrimaryNumValContext : public PrimaryExpContext {
  public:
    PrimaryNumValContext(PrimaryExpContext *ctx);

    NumValContext *numVal();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  PrimaryExpContext* primaryExp();

  class  UnaryExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    int arraySize;
    DataType dataType;
    IROperand * result;
    UnaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnaryExpContext() = default;
    void copyFrom(UnaryExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnaryExpFuncContext : public UnaryExpContext {
  public:
    UnaryExpFuncContext(UnaryExpContext *ctx);

    FuncValContext *funcVal();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  UnaryExpUnaryOpContext : public UnaryExpContext {
  public:
    UnaryExpUnaryOpContext(UnaryExpContext *ctx);

    UnaryOpContext *unaryOp();
    UnaryExpContext *unaryExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  UnaryExpPrimaryExpContext : public UnaryExpContext {
  public:
    UnaryExpPrimaryExpContext(UnaryExpContext *ctx);

    PrimaryExpContext *primaryExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  UnaryExpContext* unaryExp();

  class  UnaryOpContext : public antlr4::ParserRuleContext {
  public:
    UnaryOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnaryOpContext* unaryOp();

  class  MulExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    int arraySize;
    DataType dataType;
    IROperand * result;
    MulExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MulExpContext() = default;
    void copyFrom(MulExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MulExpMulExpContext : public MulExpContext {
  public:
    MulExpMulExpContext(MulExpContext *ctx);

    MulExpContext *mulExp();
    MulOpContext *mulOp();
    UnaryExpContext *unaryExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MulExpUnaryExpContext : public MulExpContext {
  public:
    MulExpUnaryExpContext(MulExpContext *ctx);

    UnaryExpContext *unaryExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  MulExpContext* mulExp();
  MulExpContext* mulExp(int precedence);
  class  MulOpContext : public antlr4::ParserRuleContext {
  public:
    MulOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MulOpContext* mulOp();

  class  AddExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    int arraySize;
    DataType dataType;
    IROperand * result;
    AddExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AddExpContext() = default;
    void copyFrom(AddExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AddExpAddExpContext : public AddExpContext {
  public:
    AddExpAddExpContext(AddExpContext *ctx);

    AddExpContext *addExp();
    AddOpContext *addOp();
    MulExpContext *mulExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  AddExpMulExpContext : public AddExpContext {
  public:
    AddExpMulExpContext(AddExpContext *ctx);

    MulExpContext *mulExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  AddExpContext* addExp();
  AddExpContext* addExp(int precedence);
  class  AddOpContext : public antlr4::ParserRuleContext {
  public:
    AddOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AddOpContext* addOp();

  class  RelExpContext : public antlr4::ParserRuleContext {
  public:
    IRLabel * flowTrue = nullptr;
    IRLabel * flowFalse = nullptr;
    bool isArray;
    int arraySize;
    DataType dataType;
    IROperand * result;
    RelExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RelExpContext() = default;
    void copyFrom(RelExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RelExpRelExpContext : public RelExpContext {
  public:
    RelExpRelExpContext(RelExpContext *ctx);

    RelExpContext *relExp();
    RelOpContext *relOp();
    AddExpContext *addExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  RelExpBoolValContext : public RelExpContext {
  public:
    RelExpBoolValContext(RelExpContext *ctx);

    BoolValContext *boolVal();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  RelExpAddExpContext : public RelExpContext {
  public:
    RelExpAddExpContext(RelExpContext *ctx);

    AddExpContext *addExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  RelExpContext* relExp();
  RelExpContext* relExp(int precedence);
  class  RelOpContext : public antlr4::ParserRuleContext {
  public:
    RelOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelOpContext* relOp();

  class  EqExpContext : public antlr4::ParserRuleContext {
  public:
    std::vector<IRCode *> codeBefore;
    IRLabel * flowTrue = nullptr;
    IRLabel * flowFalse = nullptr;
    bool isArray;
    int arraySize;
    DataType dataType;
    IROperand * result;
    EqExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    EqExpContext() = default;
    void copyFrom(EqExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  EqExpRelExpContext : public EqExpContext {
  public:
    EqExpRelExpContext(EqExpContext *ctx);

    RelExpContext *relExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  EqExpEqExpContext : public EqExpContext {
  public:
    EqExpEqExpContext(EqExpContext *ctx);

    EqExpContext *eqExp();
    EqOpContext *eqOp();
    RelExpContext *relExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  EqExpContext* eqExp();
  EqExpContext* eqExp(int precedence);
  class  EqOpContext : public antlr4::ParserRuleContext {
  public:
    EqOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EqOpContext* eqOp();

  class  LAndExpContext : public antlr4::ParserRuleContext {
  public:
    std::vector<IRCode *> codeBefore;
    IRLabel * label = nullptr;
            IRLabel * flowTrue = nullptr;
    IRLabel * flowFalse = nullptr;
    bool isArray;
    int arraySize;
    DataType dataType;
    IROperand * result;
    LAndExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LAndExpContext() = default;
    void copyFrom(LAndExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LAndExpLAndExpContext : public LAndExpContext {
  public:
    LAndExpLAndExpContext(LAndExpContext *ctx);

    LAndExpContext *lAndExp();
    EqExpContext *eqExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  LAndExpEqExpContext : public LAndExpContext {
  public:
    LAndExpEqExpContext(LAndExpContext *ctx);

    EqExpContext *eqExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  LAndExpContext* lAndExp();
  LAndExpContext* lAndExp(int precedence);
  class  LOrExpContext : public antlr4::ParserRuleContext {
  public:
    IRLabel * flowTrue = nullptr;
    IRLabel * flowFalse = nullptr;
    bool isArray;
    int arraySize;
    DataType dataType;
    IROperand * result;
    LOrExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LOrExpContext() = default;
    void copyFrom(LOrExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LOrExpLAndExpContext : public LOrExpContext {
  public:
    LOrExpLAndExpContext(LOrExpContext *ctx);

    LAndExpContext *lAndExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  LOrExpLOrExpContext : public LOrExpContext {
  public:
    LOrExpLOrExpContext(LOrExpContext *ctx);

    LOrExpContext *lOrExp();
    LAndExpContext *lAndExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  LOrExpContext* lOrExp();
  LOrExpContext* lOrExp(int precedence);
  class  ConstArrExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    int arraySize;
    DataType dataType;
    IRValue * result;
    ConstArrExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConstArrExpContext* constArrExp();

  class  ConstExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    int arraySize;
    DataType dataType;
    IRValue * result;
    ConstExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstExpContext() = default;
    void copyFrom(ConstExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstExpNumValContext : public ConstExpContext {
  public:
    ConstExpNumValContext(ConstExpContext *ctx);

    NumValContext *numVal();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ConstExpBoolValContext : public ConstExpContext {
  public:
    ConstExpBoolValContext(ConstExpContext *ctx);

    BoolValContext *boolVal();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ConstExpContext* constExp();

  class  NumValContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    int arraySize;
    DataType dataType;
    IRValue * result;
    NumValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    NumValContext() = default;
    void copyFrom(NumValContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NumValDoubleConstContext : public NumValContext {
  public:
    NumValDoubleConstContext(NumValContext *ctx);

    antlr4::tree::TerminalNode *DoubleConst();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  NumValIntConstContext : public NumValContext {
  public:
    NumValIntConstContext(NumValContext *ctx);

    antlr4::tree::TerminalNode *IntConst();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  NumValFloatConstContext : public NumValContext {
  public:
    NumValFloatConstContext(NumValContext *ctx);

    antlr4::tree::TerminalNode *FloatConst();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  NumValContext* numVal();

  class  BoolValContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    int arraySize;
    DataType dataType;
    IRValue * result;
    BoolValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BoolConst();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BoolValContext* boolVal();

  class  LValContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    int arraySize;
    DataType dataType;
    IROperand * result;
    IROperand * index;
    SymbolInfo * thisSymbol;
    LValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LValContext() = default;
    void copyFrom(LValContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LValBasicContext : public LValContext {
  public:
    LValBasicContext(LValContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  LValIndexedContext : public LValContext {
  public:
    LValIndexedContext(LValContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    ExpContext *exp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  LValContext* lVal();

  class  RValContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    int arraySize;
    DataType dataType;
    IROperand * result;
    SymbolInfo * thisSymbol;
    RValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RValContext() = default;
    void copyFrom(RValContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RValBasicContext : public RValContext {
  public:
    RValBasicContext(RValContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  RValIndexedContext : public RValContext {
  public:
    RValIndexedContext(RValContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    ExpContext *exp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  RValContext* rVal();

  class  FuncValContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    int arraySize;
    DataType dataType;
    IROperand * result;
    FuncSymbolInfo * thisFunc;
    FuncValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Ident();
    FuncRParamsContext *funcRParams();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncValContext* funcVal();

  class  FuncRParamsContext : public antlr4::ParserRuleContext {
  public:
    FuncSymbolInfo * thisFunc;
    FuncRParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncRParamsContext* funcRParams();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool mulExpSempred(MulExpContext *_localctx, size_t predicateIndex);
  bool addExpSempred(AddExpContext *_localctx, size_t predicateIndex);
  bool relExpSempred(RelExpContext *_localctx, size_t predicateIndex);
  bool eqExpSempred(EqExpContext *_localctx, size_t predicateIndex);
  bool lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex);
  bool lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

