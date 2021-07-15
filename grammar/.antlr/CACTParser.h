
    #include <vector>
    #include <string>
    #include "../src/symbolTable.h"
    #include "../src/IR.h"


// Generated from /home/ceba/compiler/grammar/CACT.g4 by ANTLR 4.8

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
    RuleCompUnit = 0, RuleDecl = 1, RuleConstDecl = 2, RuleBType = 3, RuleConstDef = 4, 
    RuleConstInitVal = 5, RuleVarDecl = 6, RuleVarDef = 7, RuleFuncDef = 8, 
    RuleFuncType = 9, RuleFuncFParams = 10, RuleFuncFParam = 11, RuleBlock = 12, 
    RuleBlockItem = 13, RuleStmt = 14, RuleExp = 15, RuleCond = 16, RuleLVal = 17, 
    RulePrimaryExp = 18, RuleUnaryExp = 19, RuleUnaryOp = 20, RuleFuncRParams = 21, 
    RuleMulExp = 22, RuleAddExp = 23, RuleRelExp = 24, RuleEqExp = 25, RuleLAndExp = 26, 
    RuleLOrExp = 27, RuleConstExp = 28, RuleNumber = 29
  };

  CACTParser(antlr4::TokenStream *input);
  ~CACTParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CompUnitContext;
  class DeclContext;
  class ConstDeclContext;
  class BTypeContext;
  class ConstDefContext;
  class ConstInitValContext;
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
  class LValContext;
  class PrimaryExpContext;
  class UnaryExpContext;
  class UnaryOpContext;
  class FuncRParamsContext;
  class MulExpContext;
  class AddExpContext;
  class RelExpContext;
  class EqExpContext;
  class LAndExpContext;
  class LOrExpContext;
  class ConstExpContext;
  class NumberContext; 

  class  CompUnitContext : public antlr4::ParserRuleContext {
  public:
    CompUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DeclContext *> decl();
    DeclContext* decl(size_t i);
    std::vector<FuncDefContext *> funcDef();
    FuncDefContext* funcDef(size_t i);

   
  };

  CompUnitContext* compUnit();

  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstDeclContext *constDecl();
    VarDeclContext *varDecl();

   
  };

  DeclContext* decl();

  class  ConstDeclContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    std::vector<ConstDefContext *> constDef();
    ConstDefContext* constDef(size_t i);

   
  };

  ConstDeclContext* constDecl();

  class  BTypeContext : public antlr4::ParserRuleContext {
  public:
    DataType bDataType;
    BTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  BTypeContext* bType();

  class  ConstDefContext : public antlr4::ParserRuleContext {
  public:
    SymbolInfo * thisSymbolInfo;
    ConstDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Ident();
    ConstInitValContext *constInitVal();
    antlr4::tree::TerminalNode *IntConst();

   
  };

  ConstDefContext* constDef();

  class  ConstInitValContext : public antlr4::ParserRuleContext {
  public:
    SymbolInfo * thisSymbolInfo;
    ConstInitValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstInitValContext() = default;
    void copyFrom(ConstInitValContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstInitValBasicContext : public ConstInitValContext {
  public:
    ConstInitValBasicContext(ConstInitValContext *ctx);

    ConstExpContext *constExp();
  };

  class  ConstInitValArrayContext : public ConstInitValContext {
  public:
    ConstInitValArrayContext(ConstInitValContext *ctx);

    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);
  };

  ConstInitValContext* constInitVal();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    std::vector<VarDefContext *> varDef();
    VarDefContext* varDef(size_t i);

   
  };

  VarDeclContext* varDecl();

  class  VarDefContext : public antlr4::ParserRuleContext {
  public:
    SymbolInfo * thisSymbolInfo;
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Ident();
    antlr4::tree::TerminalNode *IntConst();
    ConstInitValContext *constInitVal();

   
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

   
  };

  FuncDefContext* funcDef();

  class  FuncTypeContext : public antlr4::ParserRuleContext {
  public:
    FuncTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  FuncTypeContext* funcType();

  class  FuncFParamsContext : public antlr4::ParserRuleContext {
  public:
    FuncSymbolInfo * thisFuncInfo;
    FuncFParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FuncFParamContext *> funcFParam();
    FuncFParamContext* funcFParam(size_t i);

   
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

   
  };

  FuncFParamContext* funcFParam();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    FuncSymbolInfo * thisFuncInfo;
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BlockItemContext *> blockItem();
    BlockItemContext* blockItem(size_t i);

   
  };

  BlockContext* block();

  class  BlockItemContext : public antlr4::ParserRuleContext {
  public:
    BlockItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclContext *decl();
    StmtContext *stmt();

   
  };

  BlockItemContext* blockItem();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() = default;
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StmtExpContext : public StmtContext {
  public:
    StmtExpContext(StmtContext *ctx);

    ExpContext *exp();
  };

  class  StmtBlockContext : public StmtContext {
  public:
    StmtBlockContext(StmtContext *ctx);

    BlockContext *block();
  };

  class  StmtCtrlContext : public StmtContext {
  public:
    StmtCtrlContext(StmtContext *ctx);

    CondContext *cond();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
  };

  class  StmtReturnContext : public StmtContext {
  public:
    StmtReturnContext(StmtContext *ctx);

    ExpContext *exp();
  };

  class  StmtAssignContext : public StmtContext {
  public:
    StmtAssignContext(StmtContext *ctx);

    LValContext *lVal();
    ExpContext *exp();
  };

  StmtContext* stmt();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    size_t arraySize;
    DataType dataType;
    IRArgument * result;
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
  };

  class  ExpBoolConstContext : public ExpContext {
  public:
    ExpBoolConstContext(ExpContext *ctx);

    antlr4::tree::TerminalNode *BoolConst();
  };

  ExpContext* exp();

  class  CondContext : public antlr4::ParserRuleContext {
  public:
    DataType dataType;
    CondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LOrExpContext *lOrExp();

   
  };

  CondContext* cond();

  class  LValContext : public antlr4::ParserRuleContext {
  public:
    bool isVar;
    bool isArray;
    size_t arraySize;
    DataType dataType;
    SymbolInfo * thisSymbol;
    LValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Ident();
    ExpContext *exp();

   
  };

  LValContext* lVal();

  class  PrimaryExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    size_t arraySize;
    DataType dataType;
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
  };

  class  PrimaryExpLValContext : public PrimaryExpContext {
  public:
    PrimaryExpLValContext(PrimaryExpContext *ctx);

    LValContext *lVal();
  };

  class  PrimaryNumberContext : public PrimaryExpContext {
  public:
    PrimaryNumberContext(PrimaryExpContext *ctx);

    NumberContext *number();
  };

  PrimaryExpContext* primaryExp();

  class  UnaryExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    size_t arraySize;
    DataType dataType;
    FuncSymbolInfo * thisFunc;
    UnaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnaryExpContext() = default;
    void copyFrom(UnaryExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnaryExpFuncContext : public UnaryExpContext {
  public:
    UnaryExpFuncContext(UnaryExpContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    FuncRParamsContext *funcRParams();
  };

  class  UnaryExpUnaryOpContext : public UnaryExpContext {
  public:
    UnaryExpUnaryOpContext(UnaryExpContext *ctx);

    UnaryOpContext *unaryOp();
    UnaryExpContext *unaryExp();
  };

  class  UnaryExpPrimaryExpContext : public UnaryExpContext {
  public:
    UnaryExpPrimaryExpContext(UnaryExpContext *ctx);

    PrimaryExpContext *primaryExp();
  };

  UnaryExpContext* unaryExp();

  class  UnaryOpContext : public antlr4::ParserRuleContext {
  public:
    UnaryOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  UnaryOpContext* unaryOp();

  class  FuncRParamsContext : public antlr4::ParserRuleContext {
  public:
    FuncSymbolInfo * thisFunc;
    FuncRParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

   
  };

  FuncRParamsContext* funcRParams();

  class  MulExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    size_t arraySize;
    DataType dataType;
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
    UnaryExpContext *unaryExp();
  };

  class  MulExpUnaryExpContext : public MulExpContext {
  public:
    MulExpUnaryExpContext(MulExpContext *ctx);

    UnaryExpContext *unaryExp();
  };

  MulExpContext* mulExp();
  MulExpContext* mulExp(int precedence);
  class  AddExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    size_t arraySize;
    DataType dataType;
    IRArgument * result;
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
    MulExpContext *mulExp();
  };

  class  AddExpMulExpContext : public AddExpContext {
  public:
    AddExpMulExpContext(AddExpContext *ctx);

    MulExpContext *mulExp();
  };

  AddExpContext* addExp();
  AddExpContext* addExp(int precedence);
  class  RelExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    size_t arraySize;
    DataType dataType;
    IRArgument * result;
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
    AddExpContext *addExp();
  };

  class  RelExpAddExpContext : public RelExpContext {
  public:
    RelExpAddExpContext(RelExpContext *ctx);

    AddExpContext *addExp();
  };

  class  RelExpBoolConstContext : public RelExpContext {
  public:
    RelExpBoolConstContext(RelExpContext *ctx);

    antlr4::tree::TerminalNode *BoolConst();
  };

  RelExpContext* relExp();
  RelExpContext* relExp(int precedence);
  class  EqExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    size_t arraySize;
    DataType dataType;
    IRArgument * result;
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
  };

  class  EqExpEqExpContext : public EqExpContext {
  public:
    EqExpEqExpContext(EqExpContext *ctx);

    EqExpContext *eqExp();
    RelExpContext *relExp();
  };

  EqExpContext* eqExp();
  EqExpContext* eqExp(int precedence);
  class  LAndExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    size_t arraySize;
    DataType dataType;
    IRArgument * result;
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
  };

  class  LAndExpEqExpContext : public LAndExpContext {
  public:
    LAndExpEqExpContext(LAndExpContext *ctx);

    EqExpContext *eqExp();
  };

  LAndExpContext* lAndExp();
  LAndExpContext* lAndExp(int precedence);
  class  LOrExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    size_t arraySize;
    DataType dataType;
    IRArgument * result;
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
  };

  class  LOrExpLOrExpContext : public LOrExpContext {
  public:
    LOrExpLOrExpContext(LOrExpContext *ctx);

    LOrExpContext *lOrExp();
    LAndExpContext *lAndExp();
  };

  LOrExpContext* lOrExp();
  LOrExpContext* lOrExp(int precedence);
  class  ConstExpContext : public antlr4::ParserRuleContext {
  public:
    DataType dataType;
    IRArgument * result;
    ConstExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstExpContext() = default;
    void copyFrom(ConstExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstExpBoolConstContext : public ConstExpContext {
  public:
    ConstExpBoolConstContext(ConstExpContext *ctx);

    antlr4::tree::TerminalNode *BoolConst();
  };

  class  ConstExpNumberContext : public ConstExpContext {
  public:
    ConstExpNumberContext(ConstExpContext *ctx);

    NumberContext *number();
  };

  ConstExpContext* constExp();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    DataType dataType;
    IRArgument * result;
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    NumberContext() = default;
    void copyFrom(NumberContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NumberDoubleConstContext : public NumberContext {
  public:
    NumberDoubleConstContext(NumberContext *ctx);

    antlr4::tree::TerminalNode *DoubleConst();
  };

  class  NumberFloatConstContext : public NumberContext {
  public:
    NumberFloatConstContext(NumberContext *ctx);

    antlr4::tree::TerminalNode *FloatConst();
  };

  class  NumberIntConstContext : public NumberContext {
  public:
    NumberIntConstContext(NumberContext *ctx);

    antlr4::tree::TerminalNode *IntConst();
  };

  NumberContext* number();


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

