
    #include <vector>
    #include <string>
    #include "../src/CACT.h"
    #include "../src/symbolTable.h"
    #include "../src/IR.h"


// Generated from CACT.g4 by ANTLR 4.8


#include "CACTListener.h"

#include "CACTParser.h"


using namespace antlrcpp;
using namespace antlr4;

CACTParser::CACTParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CACTParser::~CACTParser() {
  delete _interpreter;
}

std::string CACTParser::getGrammarFileName() const {
  return "CACT.g4";
}

const std::vector<std::string>& CACTParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CACTParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompUnitContext ------------------------------------------------------------------

CACTParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::CompUnitContext::EOF() {
  return getToken(CACTParser::EOF, 0);
}

std::vector<CACTParser::DeclContext *> CACTParser::CompUnitContext::decl() {
  return getRuleContexts<CACTParser::DeclContext>();
}

CACTParser::DeclContext* CACTParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<CACTParser::DeclContext>(i);
}

std::vector<CACTParser::FuncDefContext *> CACTParser::CompUnitContext::funcDef() {
  return getRuleContexts<CACTParser::FuncDefContext>();
}

CACTParser::FuncDefContext* CACTParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<CACTParser::FuncDefContext>(i);
}


size_t CACTParser::CompUnitContext::getRuleIndex() const {
  return CACTParser::RuleCompUnit;
}

void CACTParser::CompUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompUnit(this);
}

void CACTParser::CompUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompUnit(this);
}

CACTParser::CompUnitContext* CACTParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, CACTParser::RuleCompUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__1)
      | (1ULL << CACTParser::T__2)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__12))) != 0)) {
      setState(76);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(74);
        decl();
        break;
      }

      case 2: {
        setState(75);
        funcDef();
        break;
      }

      }
      setState(80);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(81);
    match(CACTParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

CACTParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::BTypeContext::getRuleIndex() const {
  return CACTParser::RuleBType;
}

void CACTParser::BTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBType(this);
}

void CACTParser::BTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBType(this);
}

CACTParser::BTypeContext* CACTParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 2, CACTParser::RuleBType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__1)
      | (1ULL << CACTParser::T__2)
      | (1ULL << CACTParser::T__3))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

CACTParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::ConstDeclContext* CACTParser::DeclContext::constDecl() {
  return getRuleContext<CACTParser::ConstDeclContext>(0);
}

CACTParser::VarDeclContext* CACTParser::DeclContext::varDecl() {
  return getRuleContext<CACTParser::VarDeclContext>(0);
}


size_t CACTParser::DeclContext::getRuleIndex() const {
  return CACTParser::RuleDecl;
}

void CACTParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void CACTParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}

CACTParser::DeclContext* CACTParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 4, CACTParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(87);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(85);
        constDecl();
        break;
      }

      case CACTParser::T__0:
      case CACTParser::T__1:
      case CACTParser::T__2:
      case CACTParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(86);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

CACTParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::ConstDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::ConstDefContext *> CACTParser::ConstDeclContext::constDef() {
  return getRuleContexts<CACTParser::ConstDefContext>();
}

CACTParser::ConstDefContext* CACTParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<CACTParser::ConstDefContext>(i);
}


size_t CACTParser::ConstDeclContext::getRuleIndex() const {
  return CACTParser::RuleConstDecl;
}

void CACTParser::ConstDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDecl(this);
}

void CACTParser::ConstDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDecl(this);
}

CACTParser::ConstDeclContext* CACTParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, CACTParser::RuleConstDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    match(CACTParser::T__4);
    setState(90);
    bType();
    setState(91);
    constDef();
    setState(96);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__5) {
      setState(92);
      match(CACTParser::T__5);
      setState(93);
      constDef();
      setState(98);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(99);
    match(CACTParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

CACTParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstDefContext::getRuleIndex() const {
  return CACTParser::RuleConstDef;
}

void CACTParser::ConstDefContext::copyFrom(ConstDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->thisSymbolInfo = ctx->thisSymbolInfo;
}

//----------------- ConstDefArrayContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstDefArrayContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::ConstDefArrayContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::ConstArrExpContext* CACTParser::ConstDefArrayContext::constArrExp() {
  return getRuleContext<CACTParser::ConstArrExpContext>(0);
}

CACTParser::ConstDefArrayContext::ConstDefArrayContext(ConstDefContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstDefArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDefArray(this);
}
void CACTParser::ConstDefArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDefArray(this);
}
//----------------- ConstDefBasicContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstDefBasicContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstExpContext* CACTParser::ConstDefBasicContext::constExp() {
  return getRuleContext<CACTParser::ConstExpContext>(0);
}

CACTParser::ConstDefBasicContext::ConstDefBasicContext(ConstDefContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstDefBasicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDefBasic(this);
}
void CACTParser::ConstDefBasicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDefBasic(this);
}
CACTParser::ConstDefContext* CACTParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 8, CACTParser::RuleConstDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(110);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ConstDefContext *>(_tracker.createInstance<CACTParser::ConstDefBasicContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(101);
      match(CACTParser::Ident);
      setState(102);
      match(CACTParser::T__7);
      setState(103);
      constExp();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ConstDefContext *>(_tracker.createInstance<CACTParser::ConstDefArrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(104);
      match(CACTParser::Ident);
      setState(105);
      match(CACTParser::T__8);
      setState(106);
      match(CACTParser::IntConst);
      setState(107);
      match(CACTParser::T__9);
      setState(108);
      match(CACTParser::T__7);
      setState(109);
      constArrExp();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

CACTParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::VarDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::VarDefContext *> CACTParser::VarDeclContext::varDef() {
  return getRuleContexts<CACTParser::VarDefContext>();
}

CACTParser::VarDefContext* CACTParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<CACTParser::VarDefContext>(i);
}


size_t CACTParser::VarDeclContext::getRuleIndex() const {
  return CACTParser::RuleVarDecl;
}

void CACTParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void CACTParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}

CACTParser::VarDeclContext* CACTParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, CACTParser::RuleVarDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    bType();
    setState(113);
    varDef();
    setState(118);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__5) {
      setState(114);
      match(CACTParser::T__5);
      setState(115);
      varDef();
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(121);
    match(CACTParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

CACTParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::VarDefContext::getRuleIndex() const {
  return CACTParser::RuleVarDef;
}

void CACTParser::VarDefContext::copyFrom(VarDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->thisSymbolInfo = ctx->thisSymbolInfo;
}

//----------------- VarDefBasicContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::VarDefBasicContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstExpContext* CACTParser::VarDefBasicContext::constExp() {
  return getRuleContext<CACTParser::ConstExpContext>(0);
}

CACTParser::VarDefBasicContext::VarDefBasicContext(VarDefContext *ctx) { copyFrom(ctx); }

void CACTParser::VarDefBasicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDefBasic(this);
}
void CACTParser::VarDefBasicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDefBasic(this);
}
//----------------- VarDefArrayContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::VarDefArrayContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::VarDefArrayContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::ConstArrExpContext* CACTParser::VarDefArrayContext::constArrExp() {
  return getRuleContext<CACTParser::ConstArrExpContext>(0);
}

CACTParser::VarDefArrayContext::VarDefArrayContext(VarDefContext *ctx) { copyFrom(ctx); }

void CACTParser::VarDefArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDefArray(this);
}
void CACTParser::VarDefArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDefArray(this);
}
CACTParser::VarDefContext* CACTParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 12, CACTParser::RuleVarDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::VarDefBasicContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(123);
      match(CACTParser::Ident);
      setState(126);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CACTParser::T__7) {
        setState(124);
        match(CACTParser::T__7);
        setState(125);
        constExp();
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::VarDefArrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(128);
      match(CACTParser::Ident);
      setState(129);
      match(CACTParser::T__8);
      setState(130);
      match(CACTParser::IntConst);
      setState(131);
      match(CACTParser::T__9);
      setState(134);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CACTParser::T__7) {
        setState(132);
        match(CACTParser::T__7);
        setState(133);
        constArrExp();
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

CACTParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::FuncTypeContext* CACTParser::FuncDefContext::funcType() {
  return getRuleContext<CACTParser::FuncTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::BlockContext* CACTParser::FuncDefContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::FuncFParamsContext* CACTParser::FuncDefContext::funcFParams() {
  return getRuleContext<CACTParser::FuncFParamsContext>(0);
}


size_t CACTParser::FuncDefContext::getRuleIndex() const {
  return CACTParser::RuleFuncDef;
}

void CACTParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void CACTParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}

CACTParser::FuncDefContext* CACTParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 14, CACTParser::RuleFuncDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    funcType();
    setState(139);
    match(CACTParser::Ident);
    setState(140);
    match(CACTParser::T__10);
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__1)
      | (1ULL << CACTParser::T__2)
      | (1ULL << CACTParser::T__3))) != 0)) {
      setState(141);
      funcFParams();
    }
    setState(144);
    match(CACTParser::T__11);
    setState(145);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

CACTParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::FuncTypeContext::getRuleIndex() const {
  return CACTParser::RuleFuncType;
}

void CACTParser::FuncTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncType(this);
}

void CACTParser::FuncTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncType(this);
}

CACTParser::FuncTypeContext* CACTParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 16, CACTParser::RuleFuncType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__1)
      | (1ULL << CACTParser::T__2)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__12))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamsContext ------------------------------------------------------------------

CACTParser::FuncFParamsContext::FuncFParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::FuncFParamContext *> CACTParser::FuncFParamsContext::funcFParam() {
  return getRuleContexts<CACTParser::FuncFParamContext>();
}

CACTParser::FuncFParamContext* CACTParser::FuncFParamsContext::funcFParam(size_t i) {
  return getRuleContext<CACTParser::FuncFParamContext>(i);
}


size_t CACTParser::FuncFParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParams;
}

void CACTParser::FuncFParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParams(this);
}

void CACTParser::FuncFParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParams(this);
}

CACTParser::FuncFParamsContext* CACTParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 18, CACTParser::RuleFuncFParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    funcFParam();
    setState(154);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__5) {
      setState(150);
      match(CACTParser::T__5);
      setState(151);
      funcFParam();
      setState(156);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

CACTParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::FuncFParamContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncFParamContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::FuncFParamContext::ArraySymbol() {
  return getToken(CACTParser::ArraySymbol, 0);
}


size_t CACTParser::FuncFParamContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParam;
}

void CACTParser::FuncFParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParam(this);
}

void CACTParser::FuncFParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParam(this);
}

CACTParser::FuncFParamContext* CACTParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 20, CACTParser::RuleFuncFParam);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    bType();
    setState(158);
    match(CACTParser::Ident);
    setState(160);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::ArraySymbol) {
      setState(159);
      match(CACTParser::ArraySymbol);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

CACTParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::BlockItemContext *> CACTParser::BlockContext::blockItem() {
  return getRuleContexts<CACTParser::BlockItemContext>();
}

CACTParser::BlockItemContext* CACTParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<CACTParser::BlockItemContext>(i);
}


size_t CACTParser::BlockContext::getRuleIndex() const {
  return CACTParser::RuleBlock;
}

void CACTParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void CACTParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

CACTParser::BlockContext* CACTParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 22, CACTParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    match(CACTParser::T__13);
    setState(166);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__1)
      | (1ULL << CACTParser::T__2)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__10)
      | (1ULL << CACTParser::T__13)
      | (1ULL << CACTParser::T__15)
      | (1ULL << CACTParser::T__17)
      | (1ULL << CACTParser::T__18)
      | (1ULL << CACTParser::T__19)
      | (1ULL << CACTParser::T__20)
      | (1ULL << CACTParser::T__21)
      | (1ULL << CACTParser::T__22)
      | (1ULL << CACTParser::T__23)
      | (1ULL << CACTParser::BoolConst)
      | (1ULL << CACTParser::Ident)
      | (1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::FloatConst)
      | (1ULL << CACTParser::DoubleConst))) != 0)) {
      setState(163);
      blockItem();
      setState(168);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(169);
    match(CACTParser::T__14);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

CACTParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::DeclContext* CACTParser::BlockItemContext::decl() {
  return getRuleContext<CACTParser::DeclContext>(0);
}

CACTParser::StmtContext* CACTParser::BlockItemContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}


size_t CACTParser::BlockItemContext::getRuleIndex() const {
  return CACTParser::RuleBlockItem;
}

void CACTParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void CACTParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}

CACTParser::BlockItemContext* CACTParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 24, CACTParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(173);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0:
      case CACTParser::T__1:
      case CACTParser::T__2:
      case CACTParser::T__3:
      case CACTParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(171);
        decl();
        break;
      }

      case CACTParser::T__6:
      case CACTParser::T__10:
      case CACTParser::T__13:
      case CACTParser::T__15:
      case CACTParser::T__17:
      case CACTParser::T__18:
      case CACTParser::T__19:
      case CACTParser::T__20:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::T__23:
      case CACTParser::BoolConst:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 2);
        setState(172);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

CACTParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::StmtContext::getRuleIndex() const {
  return CACTParser::RuleStmt;
}

void CACTParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StmtCtrlBreakContext ------------------------------------------------------------------

CACTParser::StmtCtrlBreakContext::StmtCtrlBreakContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtCtrlBreakContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtCtrlBreak(this);
}
void CACTParser::StmtCtrlBreakContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtCtrlBreak(this);
}
//----------------- StmtExpContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::StmtExpContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtExpContext::StmtExpContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtExp(this);
}
void CACTParser::StmtExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtExp(this);
}
//----------------- StmtBlockContext ------------------------------------------------------------------

CACTParser::BlockContext* CACTParser::StmtBlockContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::StmtBlockContext::StmtBlockContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtBlock(this);
}
void CACTParser::StmtBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtBlock(this);
}
//----------------- StmtCtrlContinueContext ------------------------------------------------------------------

CACTParser::StmtCtrlContinueContext::StmtCtrlContinueContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtCtrlContinueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtCtrlContinue(this);
}
void CACTParser::StmtCtrlContinueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtCtrlContinue(this);
}
//----------------- StmtCtrlWhileContext ------------------------------------------------------------------

CACTParser::CondContext* CACTParser::StmtCtrlWhileContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

CACTParser::StmtContext* CACTParser::StmtCtrlWhileContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::StmtCtrlWhileContext::StmtCtrlWhileContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtCtrlWhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtCtrlWhile(this);
}
void CACTParser::StmtCtrlWhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtCtrlWhile(this);
}
//----------------- StmtReturnContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::StmtReturnContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtReturnContext::StmtReturnContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtReturn(this);
}
void CACTParser::StmtReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtReturn(this);
}
//----------------- StmtAssignContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::StmtAssignContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::ExpContext* CACTParser::StmtAssignContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtAssignContext::StmtAssignContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtAssign(this);
}
void CACTParser::StmtAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtAssign(this);
}
//----------------- StmtCtrlIfContext ------------------------------------------------------------------

CACTParser::CondContext* CACTParser::StmtCtrlIfContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

std::vector<CACTParser::StmtContext *> CACTParser::StmtCtrlIfContext::stmt() {
  return getRuleContexts<CACTParser::StmtContext>();
}

CACTParser::StmtContext* CACTParser::StmtCtrlIfContext::stmt(size_t i) {
  return getRuleContext<CACTParser::StmtContext>(i);
}

CACTParser::StmtCtrlIfContext::StmtCtrlIfContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtCtrlIfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtCtrlIf(this);
}
void CACTParser::StmtCtrlIfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtCtrlIf(this);
}
CACTParser::StmtContext* CACTParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 26, CACTParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(209);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtAssignContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(175);
      lVal();
      setState(176);
      match(CACTParser::T__7);
      setState(177);
      exp();
      setState(178);
      match(CACTParser::T__6);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtExpContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(181);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__10)
        | (1ULL << CACTParser::T__21)
        | (1ULL << CACTParser::T__22)
        | (1ULL << CACTParser::T__23)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(180);
        exp();
      }
      setState(183);
      match(CACTParser::T__6);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtBlockContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(184);
      block();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtCtrlIfContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(185);
      match(CACTParser::T__15);
      setState(186);
      match(CACTParser::T__10);
      setState(187);
      cond();
      setState(188);
      match(CACTParser::T__11);
      setState(189);
      stmt();
      setState(192);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
      case 1: {
        setState(190);
        match(CACTParser::T__16);
        setState(191);
        stmt();
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtCtrlWhileContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(194);
      match(CACTParser::T__17);
      setState(195);
      match(CACTParser::T__10);
      setState(196);
      cond();
      setState(197);
      match(CACTParser::T__11);
      setState(198);
      stmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtCtrlBreakContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(200);
      match(CACTParser::T__18);
      setState(201);
      match(CACTParser::T__6);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtCtrlContinueContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(202);
      match(CACTParser::T__19);
      setState(203);
      match(CACTParser::T__6);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtReturnContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(204);
      match(CACTParser::T__20);
      setState(206);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__10)
        | (1ULL << CACTParser::T__21)
        | (1ULL << CACTParser::T__22)
        | (1ULL << CACTParser::T__23)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(205);
        exp();
      }
      setState(208);
      match(CACTParser::T__6);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

CACTParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ExpContext::getRuleIndex() const {
  return CACTParser::RuleExp;
}

void CACTParser::ExpContext::copyFrom(ExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- ExpAddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::ExpAddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::ExpAddExpContext::ExpAddExpContext(ExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ExpAddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpAddExp(this);
}
void CACTParser::ExpAddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpAddExp(this);
}
//----------------- ExpBoolConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ExpBoolConstContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::ExpBoolConstContext::ExpBoolConstContext(ExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ExpBoolConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpBoolConst(this);
}
void CACTParser::ExpBoolConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpBoolConst(this);
}
CACTParser::ExpContext* CACTParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 28, CACTParser::RuleExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(213);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__10:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::T__23:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<ExpContext *>(_tracker.createInstance<CACTParser::ExpAddExpContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(211);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = dynamic_cast<ExpContext *>(_tracker.createInstance<CACTParser::ExpBoolConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(212);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

CACTParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::LOrExpContext* CACTParser::CondContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}


size_t CACTParser::CondContext::getRuleIndex() const {
  return CACTParser::RuleCond;
}

void CACTParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void CACTParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}

CACTParser::CondContext* CACTParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 30, CACTParser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    lOrExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::PrimaryExpContext::getRuleIndex() const {
  return CACTParser::RulePrimaryExp;
}

void CACTParser::PrimaryExpContext::copyFrom(PrimaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- PrimaryExpExpContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::PrimaryExpExpContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::PrimaryExpExpContext::PrimaryExpExpContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::PrimaryExpExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpExp(this);
}
void CACTParser::PrimaryExpExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpExp(this);
}
//----------------- PrimaryExpRValContext ------------------------------------------------------------------

CACTParser::RValContext* CACTParser::PrimaryExpRValContext::rVal() {
  return getRuleContext<CACTParser::RValContext>(0);
}

CACTParser::PrimaryExpRValContext::PrimaryExpRValContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::PrimaryExpRValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpRVal(this);
}
void CACTParser::PrimaryExpRValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpRVal(this);
}
//----------------- PrimaryNumValContext ------------------------------------------------------------------

CACTParser::NumValContext* CACTParser::PrimaryNumValContext::numVal() {
  return getRuleContext<CACTParser::NumValContext>(0);
}

CACTParser::PrimaryNumValContext::PrimaryNumValContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::PrimaryNumValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryNumVal(this);
}
void CACTParser::PrimaryNumValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryNumVal(this);
}
CACTParser::PrimaryExpContext* CACTParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 32, CACTParser::RulePrimaryExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(223);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__10: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryExpExpContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(217);
        match(CACTParser::T__10);
        setState(218);
        exp();
        setState(219);
        match(CACTParser::T__11);
        break;
      }

      case CACTParser::Ident: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryExpRValContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(221);
        rVal();
        break;
      }

      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryNumValContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(222);
        numVal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::UnaryExpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryExp;
}

void CACTParser::UnaryExpContext::copyFrom(UnaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- UnaryExpFuncContext ------------------------------------------------------------------

CACTParser::FuncValContext* CACTParser::UnaryExpFuncContext::funcVal() {
  return getRuleContext<CACTParser::FuncValContext>(0);
}

CACTParser::UnaryExpFuncContext::UnaryExpFuncContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::UnaryExpFuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpFunc(this);
}
void CACTParser::UnaryExpFuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpFunc(this);
}
//----------------- UnaryExpUnaryOpContext ------------------------------------------------------------------

CACTParser::UnaryOpContext* CACTParser::UnaryExpUnaryOpContext::unaryOp() {
  return getRuleContext<CACTParser::UnaryOpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::UnaryExpUnaryOpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::UnaryExpUnaryOpContext::UnaryExpUnaryOpContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::UnaryExpUnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpUnaryOp(this);
}
void CACTParser::UnaryExpUnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpUnaryOp(this);
}
//----------------- UnaryExpPrimaryExpContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext* CACTParser::UnaryExpPrimaryExpContext::primaryExp() {
  return getRuleContext<CACTParser::PrimaryExpContext>(0);
}

CACTParser::UnaryExpPrimaryExpContext::UnaryExpPrimaryExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::UnaryExpPrimaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpPrimaryExp(this);
}
void CACTParser::UnaryExpPrimaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpPrimaryExp(this);
}
CACTParser::UnaryExpContext* CACTParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 34, CACTParser::RuleUnaryExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(230);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryExpPrimaryExpContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(225);
      primaryExp();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryExpFuncContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(226);
      funcVal();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryExpUnaryOpContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(227);
      unaryOp();
      setState(228);
      unaryExp();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpContext ------------------------------------------------------------------

CACTParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::UnaryOpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryOp;
}

void CACTParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}

void CACTParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}

CACTParser::UnaryOpContext* CACTParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 36, CACTParser::RuleUnaryOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__21)
      | (1ULL << CACTParser::T__22)
      | (1ULL << CACTParser::T__23))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::MulExpContext::getRuleIndex() const {
  return CACTParser::RuleMulExp;
}

void CACTParser::MulExpContext::copyFrom(MulExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- MulExpMulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext* CACTParser::MulExpMulExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::MulOpContext* CACTParser::MulExpMulExpContext::mulOp() {
  return getRuleContext<CACTParser::MulOpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::MulExpMulExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::MulExpMulExpContext::MulExpMulExpContext(MulExpContext *ctx) { copyFrom(ctx); }

void CACTParser::MulExpMulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExpMulExp(this);
}
void CACTParser::MulExpMulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExpMulExp(this);
}
//----------------- MulExpUnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext* CACTParser::MulExpUnaryExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::MulExpUnaryExpContext::MulExpUnaryExpContext(MulExpContext *ctx) { copyFrom(ctx); }

void CACTParser::MulExpUnaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExpUnaryExp(this);
}
void CACTParser::MulExpUnaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExpUnaryExp(this);
}

CACTParser::MulExpContext* CACTParser::mulExp() {
   return mulExp(0);
}

CACTParser::MulExpContext* CACTParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  CACTParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, CACTParser::RuleMulExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<MulExpUnaryExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(235);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(243);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MulExpMulExpContext>(_tracker.createInstance<MulExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleMulExp);
        setState(237);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(238);
        mulOp();
        setState(239);
        unaryExp(); 
      }
      setState(245);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MulOpContext ------------------------------------------------------------------

CACTParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::MulOpContext::getRuleIndex() const {
  return CACTParser::RuleMulOp;
}

void CACTParser::MulOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulOp(this);
}

void CACTParser::MulOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulOp(this);
}

CACTParser::MulOpContext* CACTParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 40, CACTParser::RuleMulOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__24)
      | (1ULL << CACTParser::T__25)
      | (1ULL << CACTParser::T__26))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::AddExpContext::getRuleIndex() const {
  return CACTParser::RuleAddExp;
}

void CACTParser::AddExpContext::copyFrom(AddExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- AddExpAddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::AddExpAddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::AddOpContext* CACTParser::AddExpAddExpContext::addOp() {
  return getRuleContext<CACTParser::AddOpContext>(0);
}

CACTParser::MulExpContext* CACTParser::AddExpAddExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::AddExpAddExpContext::AddExpAddExpContext(AddExpContext *ctx) { copyFrom(ctx); }

void CACTParser::AddExpAddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpAddExp(this);
}
void CACTParser::AddExpAddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpAddExp(this);
}
//----------------- AddExpMulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext* CACTParser::AddExpMulExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::AddExpMulExpContext::AddExpMulExpContext(AddExpContext *ctx) { copyFrom(ctx); }

void CACTParser::AddExpMulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpMulExp(this);
}
void CACTParser::AddExpMulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpMulExp(this);
}

CACTParser::AddExpContext* CACTParser::addExp() {
   return addExp(0);
}

CACTParser::AddExpContext* CACTParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  CACTParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, CACTParser::RuleAddExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<AddExpMulExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(249);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(257);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<AddExpAddExpContext>(_tracker.createInstance<AddExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleAddExp);
        setState(251);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(252);
        addOp();
        setState(253);
        mulExp(0); 
      }
      setState(259);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AddOpContext ------------------------------------------------------------------

CACTParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::AddOpContext::getRuleIndex() const {
  return CACTParser::RuleAddOp;
}

void CACTParser::AddOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddOp(this);
}

void CACTParser::AddOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddOp(this);
}

CACTParser::AddOpContext* CACTParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 44, CACTParser::RuleAddOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    _la = _input->LA(1);
    if (!(_la == CACTParser::T__21

    || _la == CACTParser::T__22)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::RelExpContext::getRuleIndex() const {
  return CACTParser::RuleRelExp;
}

void CACTParser::RelExpContext::copyFrom(RelExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- RelExpRelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext* CACTParser::RelExpRelExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::RelOpContext* CACTParser::RelExpRelExpContext::relOp() {
  return getRuleContext<CACTParser::RelOpContext>(0);
}

CACTParser::AddExpContext* CACTParser::RelExpRelExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::RelExpRelExpContext::RelExpRelExpContext(RelExpContext *ctx) { copyFrom(ctx); }

void CACTParser::RelExpRelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExpRelExp(this);
}
void CACTParser::RelExpRelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExpRelExp(this);
}
//----------------- RelExpAddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::RelExpAddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::RelExpAddExpContext::RelExpAddExpContext(RelExpContext *ctx) { copyFrom(ctx); }

void CACTParser::RelExpAddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExpAddExp(this);
}
void CACTParser::RelExpAddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExpAddExp(this);
}
//----------------- RelExpBoolConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::RelExpBoolConstContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::RelExpBoolConstContext::RelExpBoolConstContext(RelExpContext *ctx) { copyFrom(ctx); }

void CACTParser::RelExpBoolConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExpBoolConst(this);
}
void CACTParser::RelExpBoolConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExpBoolConst(this);
}

CACTParser::RelExpContext* CACTParser::relExp() {
   return relExp(0);
}

CACTParser::RelExpContext* CACTParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  CACTParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, CACTParser::RuleRelExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(265);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__10:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::T__23:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = _tracker.createInstance<RelExpAddExpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(263);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = _tracker.createInstance<RelExpBoolConstContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(264);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(273);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<RelExpRelExpContext>(_tracker.createInstance<RelExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleRelExp);
        setState(267);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(268);
        relOp();
        setState(269);
        addExp(0); 
      }
      setState(275);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

CACTParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::RelOpContext::getRuleIndex() const {
  return CACTParser::RuleRelOp;
}

void CACTParser::RelOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelOp(this);
}

void CACTParser::RelOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelOp(this);
}

CACTParser::RelOpContext* CACTParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 48, CACTParser::RuleRelOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(276);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__27)
      | (1ULL << CACTParser::T__28)
      | (1ULL << CACTParser::T__29)
      | (1ULL << CACTParser::T__30))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::EqExpContext::getRuleIndex() const {
  return CACTParser::RuleEqExp;
}

void CACTParser::EqExpContext::copyFrom(EqExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- EqExpRelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext* CACTParser::EqExpRelExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::EqExpRelExpContext::EqExpRelExpContext(EqExpContext *ctx) { copyFrom(ctx); }

void CACTParser::EqExpRelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExpRelExp(this);
}
void CACTParser::EqExpRelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExpRelExp(this);
}
//----------------- EqExpEqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext* CACTParser::EqExpEqExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::EqOpContext* CACTParser::EqExpEqExpContext::eqOp() {
  return getRuleContext<CACTParser::EqOpContext>(0);
}

CACTParser::RelExpContext* CACTParser::EqExpEqExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::EqExpEqExpContext::EqExpEqExpContext(EqExpContext *ctx) { copyFrom(ctx); }

void CACTParser::EqExpEqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExpEqExp(this);
}
void CACTParser::EqExpEqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExpEqExp(this);
}

CACTParser::EqExpContext* CACTParser::eqExp() {
   return eqExp(0);
}

CACTParser::EqExpContext* CACTParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  CACTParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, CACTParser::RuleEqExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<EqExpRelExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(279);
    relExp(0);
    _ctx->stop = _input->LT(-1);
    setState(287);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<EqExpEqExpContext>(_tracker.createInstance<EqExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleEqExp);
        setState(281);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(282);
        eqOp();
        setState(283);
        relExp(0); 
      }
      setState(289);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqOpContext ------------------------------------------------------------------

CACTParser::EqOpContext::EqOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::EqOpContext::getRuleIndex() const {
  return CACTParser::RuleEqOp;
}

void CACTParser::EqOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqOp(this);
}

void CACTParser::EqOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqOp(this);
}

CACTParser::EqOpContext* CACTParser::eqOp() {
  EqOpContext *_localctx = _tracker.createInstance<EqOpContext>(_ctx, getState());
  enterRule(_localctx, 52, CACTParser::RuleEqOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    _la = _input->LA(1);
    if (!(_la == CACTParser::T__31

    || _la == CACTParser::T__32)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::LAndExpContext::getRuleIndex() const {
  return CACTParser::RuleLAndExp;
}

void CACTParser::LAndExpContext::copyFrom(LAndExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- LAndExpLAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext* CACTParser::LAndExpLAndExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::EqExpContext* CACTParser::LAndExpLAndExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::LAndExpLAndExpContext::LAndExpLAndExpContext(LAndExpContext *ctx) { copyFrom(ctx); }

void CACTParser::LAndExpLAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExpLAndExp(this);
}
void CACTParser::LAndExpLAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExpLAndExp(this);
}
//----------------- LAndExpEqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext* CACTParser::LAndExpEqExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::LAndExpEqExpContext::LAndExpEqExpContext(LAndExpContext *ctx) { copyFrom(ctx); }

void CACTParser::LAndExpEqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExpEqExp(this);
}
void CACTParser::LAndExpEqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExpEqExp(this);
}

CACTParser::LAndExpContext* CACTParser::lAndExp() {
   return lAndExp(0);
}

CACTParser::LAndExpContext* CACTParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  CACTParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, CACTParser::RuleLAndExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LAndExpEqExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(293);
    eqExp(0);
    _ctx->stop = _input->LT(-1);
    setState(300);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LAndExpLAndExpContext>(_tracker.createInstance<LAndExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLAndExp);
        setState(295);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(296);
        match(CACTParser::T__33);
        setState(297);
        eqExp(0); 
      }
      setState(302);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::LOrExpContext::getRuleIndex() const {
  return CACTParser::RuleLOrExp;
}

void CACTParser::LOrExpContext::copyFrom(LOrExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- LOrExpLAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext* CACTParser::LOrExpLAndExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LOrExpLAndExpContext::LOrExpLAndExpContext(LOrExpContext *ctx) { copyFrom(ctx); }

void CACTParser::LOrExpLAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExpLAndExp(this);
}
void CACTParser::LOrExpLAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExpLAndExp(this);
}
//----------------- LOrExpLOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext* CACTParser::LOrExpLOrExpContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}

CACTParser::LAndExpContext* CACTParser::LOrExpLOrExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LOrExpLOrExpContext::LOrExpLOrExpContext(LOrExpContext *ctx) { copyFrom(ctx); }

void CACTParser::LOrExpLOrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExpLOrExp(this);
}
void CACTParser::LOrExpLOrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExpLOrExp(this);
}

CACTParser::LOrExpContext* CACTParser::lOrExp() {
   return lOrExp(0);
}

CACTParser::LOrExpContext* CACTParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  CACTParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, CACTParser::RuleLOrExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LOrExpLAndExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(304);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(311);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LOrExpLOrExpContext>(_tracker.createInstance<LOrExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLOrExp);
        setState(306);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(307);
        match(CACTParser::T__34);
        setState(308);
        lAndExp(0); 
      }
      setState(313);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstArrExpContext ------------------------------------------------------------------

CACTParser::ConstArrExpContext::ConstArrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::ConstExpContext *> CACTParser::ConstArrExpContext::constExp() {
  return getRuleContexts<CACTParser::ConstExpContext>();
}

CACTParser::ConstExpContext* CACTParser::ConstArrExpContext::constExp(size_t i) {
  return getRuleContext<CACTParser::ConstExpContext>(i);
}


size_t CACTParser::ConstArrExpContext::getRuleIndex() const {
  return CACTParser::RuleConstArrExp;
}

void CACTParser::ConstArrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstArrExp(this);
}

void CACTParser::ConstArrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstArrExp(this);
}

CACTParser::ConstArrExpContext* CACTParser::constArrExp() {
  ConstArrExpContext *_localctx = _tracker.createInstance<ConstArrExpContext>(_ctx, getState());
  enterRule(_localctx, 58, CACTParser::RuleConstArrExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    match(CACTParser::T__13);
    setState(323);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::BoolConst)
      | (1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::FloatConst)
      | (1ULL << CACTParser::DoubleConst))) != 0)) {
      setState(315);
      constExp();
      setState(320);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CACTParser::T__5) {
        setState(316);
        match(CACTParser::T__5);
        setState(317);
        constExp();
        setState(322);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(325);
    match(CACTParser::T__14);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

CACTParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstExpContext::getRuleIndex() const {
  return CACTParser::RuleConstExp;
}

void CACTParser::ConstExpContext::copyFrom(ConstExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- ConstExpNumValContext ------------------------------------------------------------------

CACTParser::NumValContext* CACTParser::ConstExpNumValContext::numVal() {
  return getRuleContext<CACTParser::NumValContext>(0);
}

CACTParser::ConstExpNumValContext::ConstExpNumValContext(ConstExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstExpNumValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExpNumVal(this);
}
void CACTParser::ConstExpNumValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExpNumVal(this);
}
//----------------- ConstExpBoolValContext ------------------------------------------------------------------

CACTParser::BoolValContext* CACTParser::ConstExpBoolValContext::boolVal() {
  return getRuleContext<CACTParser::BoolValContext>(0);
}

CACTParser::ConstExpBoolValContext::ConstExpBoolValContext(ConstExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstExpBoolValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExpBoolVal(this);
}
void CACTParser::ConstExpBoolValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExpBoolVal(this);
}
CACTParser::ConstExpContext* CACTParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 60, CACTParser::RuleConstExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(329);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpNumValContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(327);
        numVal();
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpBoolValContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(328);
        boolVal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumValContext ------------------------------------------------------------------

CACTParser::NumValContext::NumValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::NumValContext::getRuleIndex() const {
  return CACTParser::RuleNumVal;
}

void CACTParser::NumValContext::copyFrom(NumValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- NumValDoubleConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::NumValDoubleConstContext::DoubleConst() {
  return getToken(CACTParser::DoubleConst, 0);
}

CACTParser::NumValDoubleConstContext::NumValDoubleConstContext(NumValContext *ctx) { copyFrom(ctx); }

void CACTParser::NumValDoubleConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumValDoubleConst(this);
}
void CACTParser::NumValDoubleConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumValDoubleConst(this);
}
//----------------- NumValIntConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::NumValIntConstContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::NumValIntConstContext::NumValIntConstContext(NumValContext *ctx) { copyFrom(ctx); }

void CACTParser::NumValIntConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumValIntConst(this);
}
void CACTParser::NumValIntConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumValIntConst(this);
}
//----------------- NumValFloatConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::NumValFloatConstContext::FloatConst() {
  return getToken(CACTParser::FloatConst, 0);
}

CACTParser::NumValFloatConstContext::NumValFloatConstContext(NumValContext *ctx) { copyFrom(ctx); }

void CACTParser::NumValFloatConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumValFloatConst(this);
}
void CACTParser::NumValFloatConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumValFloatConst(this);
}
CACTParser::NumValContext* CACTParser::numVal() {
  NumValContext *_localctx = _tracker.createInstance<NumValContext>(_ctx, getState());
  enterRule(_localctx, 62, CACTParser::RuleNumVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(334);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst: {
        _localctx = dynamic_cast<NumValContext *>(_tracker.createInstance<CACTParser::NumValIntConstContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(331);
        match(CACTParser::IntConst);
        break;
      }

      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<NumValContext *>(_tracker.createInstance<CACTParser::NumValDoubleConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(332);
        match(CACTParser::DoubleConst);
        break;
      }

      case CACTParser::FloatConst: {
        _localctx = dynamic_cast<NumValContext *>(_tracker.createInstance<CACTParser::NumValFloatConstContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(333);
        match(CACTParser::FloatConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolValContext ------------------------------------------------------------------

CACTParser::BoolValContext::BoolValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::BoolValContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}


size_t CACTParser::BoolValContext::getRuleIndex() const {
  return CACTParser::RuleBoolVal;
}

void CACTParser::BoolValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolVal(this);
}

void CACTParser::BoolValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolVal(this);
}

CACTParser::BoolValContext* CACTParser::boolVal() {
  BoolValContext *_localctx = _tracker.createInstance<BoolValContext>(_ctx, getState());
  enterRule(_localctx, 64, CACTParser::RuleBoolVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    match(CACTParser::BoolConst);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

CACTParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::LValContext::getRuleIndex() const {
  return CACTParser::RuleLVal;
}

void CACTParser::LValContext::copyFrom(LValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->index = ctx->index;
  this->thisSymbol = ctx->thisSymbol;
}

//----------------- LValBasicContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::LValBasicContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::LValBasicContext::LValBasicContext(LValContext *ctx) { copyFrom(ctx); }

void CACTParser::LValBasicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLValBasic(this);
}
void CACTParser::LValBasicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLValBasic(this);
}
//----------------- LValIndexedContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::LValIndexedContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ExpContext* CACTParser::LValIndexedContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::LValIndexedContext::LValIndexedContext(LValContext *ctx) { copyFrom(ctx); }

void CACTParser::LValIndexedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLValIndexed(this);
}
void CACTParser::LValIndexedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLValIndexed(this);
}
CACTParser::LValContext* CACTParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 66, CACTParser::RuleLVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(344);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<LValContext *>(_tracker.createInstance<CACTParser::LValBasicContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(338);
      match(CACTParser::Ident);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<LValContext *>(_tracker.createInstance<CACTParser::LValIndexedContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(339);
      match(CACTParser::Ident);
      setState(340);
      match(CACTParser::T__8);
      setState(341);
      exp();
      setState(342);
      match(CACTParser::T__9);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RValContext ------------------------------------------------------------------

CACTParser::RValContext::RValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::RValContext::getRuleIndex() const {
  return CACTParser::RuleRVal;
}

void CACTParser::RValContext::copyFrom(RValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
  this->thisSymbol = ctx->thisSymbol;
}

//----------------- RValBasicContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::RValBasicContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::RValBasicContext::RValBasicContext(RValContext *ctx) { copyFrom(ctx); }

void CACTParser::RValBasicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRValBasic(this);
}
void CACTParser::RValBasicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRValBasic(this);
}
//----------------- RValIndexedContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::RValIndexedContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ExpContext* CACTParser::RValIndexedContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::RValIndexedContext::RValIndexedContext(RValContext *ctx) { copyFrom(ctx); }

void CACTParser::RValIndexedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRValIndexed(this);
}
void CACTParser::RValIndexedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRValIndexed(this);
}
CACTParser::RValContext* CACTParser::rVal() {
  RValContext *_localctx = _tracker.createInstance<RValContext>(_ctx, getState());
  enterRule(_localctx, 68, CACTParser::RuleRVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(352);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<RValContext *>(_tracker.createInstance<CACTParser::RValBasicContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(346);
      match(CACTParser::Ident);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<RValContext *>(_tracker.createInstance<CACTParser::RValIndexedContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(347);
      match(CACTParser::Ident);
      setState(348);
      match(CACTParser::T__8);
      setState(349);
      exp();
      setState(350);
      match(CACTParser::T__9);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncValContext ------------------------------------------------------------------

CACTParser::FuncValContext::FuncValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::FuncValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::FuncRParamsContext* CACTParser::FuncValContext::funcRParams() {
  return getRuleContext<CACTParser::FuncRParamsContext>(0);
}


size_t CACTParser::FuncValContext::getRuleIndex() const {
  return CACTParser::RuleFuncVal;
}

void CACTParser::FuncValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncVal(this);
}

void CACTParser::FuncValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncVal(this);
}

CACTParser::FuncValContext* CACTParser::funcVal() {
  FuncValContext *_localctx = _tracker.createInstance<FuncValContext>(_ctx, getState());
  enterRule(_localctx, 70, CACTParser::RuleFuncVal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(354);
    match(CACTParser::Ident);
    setState(355);
    match(CACTParser::T__10);
    setState(357);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__10)
      | (1ULL << CACTParser::T__21)
      | (1ULL << CACTParser::T__22)
      | (1ULL << CACTParser::T__23)
      | (1ULL << CACTParser::BoolConst)
      | (1ULL << CACTParser::Ident)
      | (1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::FloatConst)
      | (1ULL << CACTParser::DoubleConst))) != 0)) {
      setState(356);
      funcRParams();
    }
    setState(359);
    match(CACTParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

CACTParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::ExpContext *> CACTParser::FuncRParamsContext::exp() {
  return getRuleContexts<CACTParser::ExpContext>();
}

CACTParser::ExpContext* CACTParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<CACTParser::ExpContext>(i);
}


size_t CACTParser::FuncRParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncRParams;
}

void CACTParser::FuncRParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncRParams(this);
}

void CACTParser::FuncRParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncRParams(this);
}

CACTParser::FuncRParamsContext* CACTParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 72, CACTParser::RuleFuncRParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    exp();
    setState(366);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__5) {
      setState(362);
      match(CACTParser::T__5);
      setState(363);
      exp();
      setState(368);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CACTParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 19: return mulExpSempred(dynamic_cast<MulExpContext *>(context), predicateIndex);
    case 21: return addExpSempred(dynamic_cast<AddExpContext *>(context), predicateIndex);
    case 23: return relExpSempred(dynamic_cast<RelExpContext *>(context), predicateIndex);
    case 25: return eqExpSempred(dynamic_cast<EqExpContext *>(context), predicateIndex);
    case 27: return lAndExpSempred(dynamic_cast<LAndExpContext *>(context), predicateIndex);
    case 28: return lOrExpSempred(dynamic_cast<LOrExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CACTParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::relExpSempred(RelExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CACTParser::eqExpSempred(EqExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CACTParser::_decisionToDFA;
atn::PredictionContextCache CACTParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CACTParser::_atn;
std::vector<uint16_t> CACTParser::_serializedATN;

std::vector<std::string> CACTParser::_ruleNames = {
  "compUnit", "bType", "decl", "constDecl", "constDef", "varDecl", "varDef", 
  "funcDef", "funcType", "funcFParams", "funcFParam", "block", "blockItem", 
  "stmt", "exp", "cond", "primaryExp", "unaryExp", "unaryOp", "mulExp", 
  "mulOp", "addExp", "addOp", "relExp", "relOp", "eqExp", "eqOp", "lAndExp", 
  "lOrExp", "constArrExp", "constExp", "numVal", "boolVal", "lVal", "rVal", 
  "funcVal", "funcRParams"
};

std::vector<std::string> CACTParser::_literalNames = {
  "", "'int'", "'bool'", "'double'", "'float'", "'const'", "','", "';'", 
  "'='", "'['", "']'", "'('", "')'", "'void'", "'{'", "'}'", "'if'", "'else'", 
  "'while'", "'break'", "'continue'", "'return'", "'+'", "'-'", "'!'", "'*'", 
  "'/'", "'%'", "'<'", "'>'", "'<='", "'>='", "'=='", "'!='", "'&&'", "'||'"
};

std::vector<std::string> CACTParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "BoolConst", "Ident", "IntConst", "FloatConst", "DoubleConst", "ArraySymbol", 
  "NewLine", "WhiteSpace", "BlockComment", "LineComment"
};

dfa::Vocabulary CACTParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CACTParser::_tokenNames;

CACTParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2f, 0x174, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x4f, 0xa, 
    0x2, 0xc, 0x2, 0xe, 0x2, 0x52, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x5a, 0xa, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x61, 0xa, 0x5, 0xc, 0x5, 
    0xe, 0x5, 0x64, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x71, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 
    0x77, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x7a, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x81, 0xa, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x89, 0xa, 0x8, 
    0x5, 0x8, 0x8b, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 
    0x9, 0x91, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x9b, 0xa, 0xb, 0xc, 0xb, 0xe, 
    0xb, 0x9e, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xa3, 0xa, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xa7, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 
    0xaa, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xb0, 
    0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x5, 0xf, 0xb8, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xc3, 0xa, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xd1, 0xa, 
    0xf, 0x3, 0xf, 0x5, 0xf, 0xd4, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 
    0x10, 0xd8, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xe2, 0xa, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xe9, 0xa, 
    0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0xf4, 0xa, 0x15, 0xc, 0x15, 
    0xe, 0x15, 0xf7, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x102, 
    0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x105, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x10c, 0xa, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x112, 0xa, 0x19, 0xc, 0x19, 
    0xe, 0x19, 0x115, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x120, 
    0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x123, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 
    0x1d, 0x12d, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x130, 0xb, 0x1d, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 
    0x138, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x13b, 0xb, 0x1e, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x141, 0xa, 0x1f, 0xc, 0x1f, 
    0xe, 0x1f, 0x144, 0xb, 0x1f, 0x5, 0x1f, 0x146, 0xa, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x14c, 0xa, 0x20, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x151, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 
    0x23, 0x15b, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x163, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x5, 0x25, 0x168, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x16f, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 
    0x172, 0xb, 0x26, 0x3, 0x26, 0x2, 0x8, 0x28, 0x2c, 0x30, 0x34, 0x38, 
    0x3a, 0x27, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 
    0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 
    0x48, 0x4a, 0x2, 0x9, 0x3, 0x2, 0x3, 0x6, 0x4, 0x2, 0x3, 0x6, 0xf, 0xf, 
    0x3, 0x2, 0x18, 0x1a, 0x3, 0x2, 0x1b, 0x1d, 0x3, 0x2, 0x18, 0x19, 0x3, 
    0x2, 0x1e, 0x21, 0x3, 0x2, 0x22, 0x23, 0x2, 0x17b, 0x2, 0x50, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x55, 0x3, 0x2, 0x2, 0x2, 0x6, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x5b, 0x3, 0x2, 0x2, 0x2, 0xa, 0x70, 0x3, 0x2, 0x2, 0x2, 0xc, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x10, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x95, 0x3, 0x2, 0x2, 0x2, 0x14, 0x97, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x18, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xd3, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x20, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0x24, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x26, 0xea, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0xec, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xf8, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x106, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x32, 0x116, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x118, 0x3, 0x2, 0x2, 0x2, 0x36, 0x124, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x126, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x131, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x13c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x40, 0x150, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x152, 0x3, 0x2, 0x2, 0x2, 0x44, 0x15a, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x162, 0x3, 0x2, 0x2, 0x2, 0x48, 0x164, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4f, 0x5, 0x6, 0x4, 
    0x2, 0x4d, 0x4f, 0x5, 0x10, 0x9, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x52, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 
    0x2, 0x2, 0x3, 0x54, 0x3, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x9, 0x2, 
    0x2, 0x2, 0x56, 0x5, 0x3, 0x2, 0x2, 0x2, 0x57, 0x5a, 0x5, 0x8, 0x5, 
    0x2, 0x58, 0x5a, 0x5, 0xc, 0x7, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x59, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x7, 0x3, 0x2, 0x2, 0x2, 0x5b, 
    0x5c, 0x7, 0x7, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0x4, 0x3, 0x2, 0x5d, 0x62, 
    0x5, 0xa, 0x6, 0x2, 0x5e, 0x5f, 0x7, 0x8, 0x2, 0x2, 0x5f, 0x61, 0x5, 
    0xa, 0x6, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x61, 0x64, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x65, 0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x65, 0x66, 0x7, 0x9, 0x2, 0x2, 0x66, 0x9, 0x3, 0x2, 0x2, 0x2, 0x67, 
    0x68, 0x7, 0x27, 0x2, 0x2, 0x68, 0x69, 0x7, 0xa, 0x2, 0x2, 0x69, 0x71, 
    0x5, 0x3e, 0x20, 0x2, 0x6a, 0x6b, 0x7, 0x27, 0x2, 0x2, 0x6b, 0x6c, 0x7, 
    0xb, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x28, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0xc, 
    0x2, 0x2, 0x6e, 0x6f, 0x7, 0xa, 0x2, 0x2, 0x6f, 0x71, 0x5, 0x3c, 0x1f, 
    0x2, 0x70, 0x67, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6a, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0xb, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x5, 0x4, 0x3, 0x2, 0x73, 
    0x78, 0x5, 0xe, 0x8, 0x2, 0x74, 0x75, 0x7, 0x8, 0x2, 0x2, 0x75, 0x77, 
    0x5, 0xe, 0x8, 0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x77, 0x7a, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 
    0x2, 0x2, 0x79, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x7b, 0x7c, 0x7, 0x9, 0x2, 0x2, 0x7c, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x7d, 0x80, 0x7, 0x27, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0xa, 0x2, 0x2, 0x7f, 
    0x81, 0x5, 0x3e, 0x20, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x7, 
    0x27, 0x2, 0x2, 0x83, 0x84, 0x7, 0xb, 0x2, 0x2, 0x84, 0x85, 0x7, 0x28, 
    0x2, 0x2, 0x85, 0x88, 0x7, 0xc, 0x2, 0x2, 0x86, 0x87, 0x7, 0xa, 0x2, 
    0x2, 0x87, 0x89, 0x5, 0x3c, 0x1f, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x82, 0x3, 0x2, 0x2, 0x2, 0x8b, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x12, 0xa, 0x2, 0x8d, 0x8e, 0x7, 
    0x27, 0x2, 0x2, 0x8e, 0x90, 0x7, 0xd, 0x2, 0x2, 0x8f, 0x91, 0x5, 0x14, 
    0xb, 0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0xe, 0x2, 0x2, 
    0x93, 0x94, 0x5, 0x18, 0xd, 0x2, 0x94, 0x11, 0x3, 0x2, 0x2, 0x2, 0x95, 
    0x96, 0x9, 0x3, 0x2, 0x2, 0x96, 0x13, 0x3, 0x2, 0x2, 0x2, 0x97, 0x9c, 
    0x5, 0x16, 0xc, 0x2, 0x98, 0x99, 0x7, 0x8, 0x2, 0x2, 0x99, 0x9b, 0x5, 
    0x16, 0xc, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9e, 0x3, 0x2, 
    0x2, 0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x9d, 0x15, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 
    0x9f, 0xa0, 0x5, 0x4, 0x3, 0x2, 0xa0, 0xa2, 0x7, 0x27, 0x2, 0x2, 0xa1, 
    0xa3, 0x7, 0x2b, 0x2, 0x2, 0xa2, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 
    0x3, 0x2, 0x2, 0x2, 0xa3, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa8, 0x7, 
    0x10, 0x2, 0x2, 0xa5, 0xa7, 0x5, 0x1a, 0xe, 0x2, 0xa6, 0xa5, 0x3, 0x2, 
    0x2, 0x2, 0xa7, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 
    0x2, 0xa8, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xab, 0x3, 0x2, 0x2, 0x2, 
    0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x7, 0x11, 0x2, 0x2, 0xac, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0xad, 0xb0, 0x5, 0x6, 0x4, 0x2, 0xae, 0xb0, 
    0x5, 0x1c, 0xf, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xae, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x5, 0x44, 
    0x23, 0x2, 0xb2, 0xb3, 0x7, 0xa, 0x2, 0x2, 0xb3, 0xb4, 0x5, 0x1e, 0x10, 
    0x2, 0xb4, 0xb5, 0x7, 0x9, 0x2, 0x2, 0xb5, 0xd4, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0xb8, 0x5, 0x1e, 0x10, 0x2, 0xb7, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb7, 
    0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xd4, 
    0x7, 0x9, 0x2, 0x2, 0xba, 0xd4, 0x5, 0x18, 0xd, 0x2, 0xbb, 0xbc, 0x7, 
    0x12, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0xd, 0x2, 0x2, 0xbd, 0xbe, 0x5, 0x20, 
    0x11, 0x2, 0xbe, 0xbf, 0x7, 0xe, 0x2, 0x2, 0xbf, 0xc2, 0x5, 0x1c, 0xf, 
    0x2, 0xc0, 0xc1, 0x7, 0x13, 0x2, 0x2, 0xc1, 0xc3, 0x5, 0x1c, 0xf, 0x2, 
    0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 
    0xd4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0x14, 0x2, 0x2, 0xc5, 0xc6, 
    0x7, 0xd, 0x2, 0x2, 0xc6, 0xc7, 0x5, 0x20, 0x11, 0x2, 0xc7, 0xc8, 0x7, 
    0xe, 0x2, 0x2, 0xc8, 0xc9, 0x5, 0x1c, 0xf, 0x2, 0xc9, 0xd4, 0x3, 0x2, 
    0x2, 0x2, 0xca, 0xcb, 0x7, 0x15, 0x2, 0x2, 0xcb, 0xd4, 0x7, 0x9, 0x2, 
    0x2, 0xcc, 0xcd, 0x7, 0x16, 0x2, 0x2, 0xcd, 0xd4, 0x7, 0x9, 0x2, 0x2, 
    0xce, 0xd0, 0x7, 0x17, 0x2, 0x2, 0xcf, 0xd1, 0x5, 0x1e, 0x10, 0x2, 0xd0, 
    0xcf, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 
    0x3, 0x2, 0x2, 0x2, 0xd2, 0xd4, 0x7, 0x9, 0x2, 0x2, 0xd3, 0xb1, 0x3, 
    0x2, 0x2, 0x2, 0xd3, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xba, 0x3, 0x2, 
    0x2, 0x2, 0xd3, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xc4, 0x3, 0x2, 0x2, 
    0x2, 0xd3, 0xca, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xcc, 0x3, 0x2, 0x2, 0x2, 
    0xd3, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xd5, 
    0xd8, 0x5, 0x2c, 0x17, 0x2, 0xd6, 0xd8, 0x7, 0x26, 0x2, 0x2, 0xd7, 0xd5, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xd9, 0xda, 0x5, 0x3a, 0x1e, 0x2, 0xda, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0xdb, 0xdc, 0x7, 0xd, 0x2, 0x2, 0xdc, 0xdd, 0x5, 0x1e, 0x10, 
    0x2, 0xdd, 0xde, 0x7, 0xe, 0x2, 0x2, 0xde, 0xe2, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0xe2, 0x5, 0x46, 0x24, 0x2, 0xe0, 0xe2, 0x5, 0x40, 0x21, 0x2, 
    0xe1, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe1, 
    0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0x23, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe9, 
    0x5, 0x22, 0x12, 0x2, 0xe4, 0xe9, 0x5, 0x48, 0x25, 0x2, 0xe5, 0xe6, 
    0x5, 0x26, 0x14, 0x2, 0xe6, 0xe7, 0x5, 0x24, 0x13, 0x2, 0xe7, 0xe9, 
    0x3, 0x2, 0x2, 0x2, 0xe8, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe4, 0x3, 
    0x2, 0x2, 0x2, 0xe8, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe9, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0xea, 0xeb, 0x9, 0x4, 0x2, 0x2, 0xeb, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0xec, 0xed, 0x8, 0x15, 0x1, 0x2, 0xed, 0xee, 0x5, 0x24, 0x13, 0x2, 
    0xee, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0xc, 0x3, 0x2, 0x2, 0xf0, 
    0xf1, 0x5, 0x2a, 0x16, 0x2, 0xf1, 0xf2, 0x5, 0x24, 0x13, 0x2, 0xf2, 
    0xf4, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf7, 
    0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0x29, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 
    0x2, 0x2, 0xf8, 0xf9, 0x9, 0x5, 0x2, 0x2, 0xf9, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0xfa, 0xfb, 0x8, 0x17, 0x1, 0x2, 0xfb, 0xfc, 0x5, 0x28, 0x15, 0x2, 
    0xfc, 0x103, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0xc, 0x3, 0x2, 0x2, 0xfe, 
    0xff, 0x5, 0x2e, 0x18, 0x2, 0xff, 0x100, 0x5, 0x28, 0x15, 0x2, 0x100, 
    0x102, 0x3, 0x2, 0x2, 0x2, 0x101, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x102, 0x105, 
    0x3, 0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 
    0x3, 0x2, 0x2, 0x2, 0x104, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x105, 0x103, 0x3, 
    0x2, 0x2, 0x2, 0x106, 0x107, 0x9, 0x6, 0x2, 0x2, 0x107, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x108, 0x109, 0x8, 0x19, 0x1, 0x2, 0x109, 0x10c, 0x5, 0x2c, 
    0x17, 0x2, 0x10a, 0x10c, 0x7, 0x26, 0x2, 0x2, 0x10b, 0x108, 0x3, 0x2, 
    0x2, 0x2, 0x10b, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x10d, 0x10e, 0xc, 0x4, 0x2, 0x2, 0x10e, 0x10f, 0x5, 0x32, 
    0x1a, 0x2, 0x10f, 0x110, 0x5, 0x2c, 0x17, 0x2, 0x110, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x111, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x112, 0x115, 0x3, 0x2, 
    0x2, 0x2, 0x113, 0x111, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 0x2, 
    0x2, 0x2, 0x114, 0x31, 0x3, 0x2, 0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x117, 0x9, 0x7, 0x2, 0x2, 0x117, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x118, 0x119, 0x8, 0x1b, 0x1, 0x2, 0x119, 0x11a, 0x5, 0x30, 0x19, 0x2, 
    0x11a, 0x121, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0xc, 0x3, 0x2, 0x2, 
    0x11c, 0x11d, 0x5, 0x36, 0x1c, 0x2, 0x11d, 0x11e, 0x5, 0x30, 0x19, 0x2, 
    0x11e, 0x120, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11b, 0x3, 0x2, 0x2, 0x2, 
    0x120, 0x123, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 
    0x121, 0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x35, 0x3, 0x2, 0x2, 0x2, 0x123, 
    0x121, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x9, 0x8, 0x2, 0x2, 0x125, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x8, 0x1d, 0x1, 0x2, 0x127, 
    0x128, 0x5, 0x34, 0x1b, 0x2, 0x128, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x129, 
    0x12a, 0xc, 0x3, 0x2, 0x2, 0x12a, 0x12b, 0x7, 0x24, 0x2, 0x2, 0x12b, 
    0x12d, 0x5, 0x34, 0x1b, 0x2, 0x12c, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12d, 
    0x130, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0x12f, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x39, 0x3, 0x2, 0x2, 0x2, 0x130, 0x12e, 
    0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x8, 0x1e, 0x1, 0x2, 0x132, 0x133, 
    0x5, 0x38, 0x1d, 0x2, 0x133, 0x139, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 
    0xc, 0x3, 0x2, 0x2, 0x135, 0x136, 0x7, 0x25, 0x2, 0x2, 0x136, 0x138, 
    0x5, 0x38, 0x1d, 0x2, 0x137, 0x134, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13b, 
    0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 
    0x3, 0x2, 0x2, 0x2, 0x13a, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 0x3, 
    0x2, 0x2, 0x2, 0x13c, 0x145, 0x7, 0x10, 0x2, 0x2, 0x13d, 0x142, 0x5, 
    0x3e, 0x20, 0x2, 0x13e, 0x13f, 0x7, 0x8, 0x2, 0x2, 0x13f, 0x141, 0x5, 
    0x3e, 0x20, 0x2, 0x140, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x141, 0x144, 0x3, 
    0x2, 0x2, 0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 
    0x2, 0x2, 0x2, 0x143, 0x146, 0x3, 0x2, 0x2, 0x2, 0x144, 0x142, 0x3, 
    0x2, 0x2, 0x2, 0x145, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x3, 
    0x2, 0x2, 0x2, 0x146, 0x147, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0x7, 
    0x11, 0x2, 0x2, 0x148, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14c, 0x5, 
    0x40, 0x21, 0x2, 0x14a, 0x14c, 0x5, 0x42, 0x22, 0x2, 0x14b, 0x149, 0x3, 
    0x2, 0x2, 0x2, 0x14b, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x14d, 0x151, 0x7, 0x28, 0x2, 0x2, 0x14e, 0x151, 0x7, 0x2a, 
    0x2, 0x2, 0x14f, 0x151, 0x7, 0x29, 0x2, 0x2, 0x150, 0x14d, 0x3, 0x2, 
    0x2, 0x2, 0x150, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x150, 0x14f, 0x3, 0x2, 
    0x2, 0x2, 0x151, 0x41, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x7, 0x26, 
    0x2, 0x2, 0x153, 0x43, 0x3, 0x2, 0x2, 0x2, 0x154, 0x15b, 0x7, 0x27, 
    0x2, 0x2, 0x155, 0x156, 0x7, 0x27, 0x2, 0x2, 0x156, 0x157, 0x7, 0xb, 
    0x2, 0x2, 0x157, 0x158, 0x5, 0x1e, 0x10, 0x2, 0x158, 0x159, 0x7, 0xc, 
    0x2, 0x2, 0x159, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x154, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x155, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x45, 0x3, 0x2, 0x2, 
    0x2, 0x15c, 0x163, 0x7, 0x27, 0x2, 0x2, 0x15d, 0x15e, 0x7, 0x27, 0x2, 
    0x2, 0x15e, 0x15f, 0x7, 0xb, 0x2, 0x2, 0x15f, 0x160, 0x5, 0x1e, 0x10, 
    0x2, 0x160, 0x161, 0x7, 0xc, 0x2, 0x2, 0x161, 0x163, 0x3, 0x2, 0x2, 
    0x2, 0x162, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x162, 0x15d, 0x3, 0x2, 0x2, 
    0x2, 0x163, 0x47, 0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 0x7, 0x27, 0x2, 
    0x2, 0x165, 0x167, 0x7, 0xd, 0x2, 0x2, 0x166, 0x168, 0x5, 0x4a, 0x26, 
    0x2, 0x167, 0x166, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x3, 0x2, 0x2, 
    0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x7, 0xe, 0x2, 
    0x2, 0x16a, 0x49, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x170, 0x5, 0x1e, 0x10, 
    0x2, 0x16c, 0x16d, 0x7, 0x8, 0x2, 0x2, 0x16d, 0x16f, 0x5, 0x1e, 0x10, 
    0x2, 0x16e, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x172, 0x3, 0x2, 0x2, 
    0x2, 0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x3, 0x2, 0x2, 
    0x2, 0x171, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x172, 0x170, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x4e, 0x50, 0x59, 0x62, 0x70, 0x78, 0x80, 0x88, 0x8a, 0x90, 0x9c, 
    0xa2, 0xa8, 0xaf, 0xb7, 0xc2, 0xd0, 0xd3, 0xd7, 0xe1, 0xe8, 0xf5, 0x103, 
    0x10b, 0x113, 0x121, 0x12e, 0x139, 0x142, 0x145, 0x14b, 0x150, 0x15a, 
    0x162, 0x167, 0x170, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CACTParser::Initializer CACTParser::_init;
