#pragma

#include "../grammar/CACTBaseListener.h"

class SemanticAnalysis : public CACTBaseListener
{
private:
    /* data */
public:
    SemanticAnalysis(/* args */){}
    ~SemanticAnalysis(){}


    void enterCompUnit(CACTParser::CompUnitContext * /*ctx*/) override { }
    void exitCompUnit(CACTParser::CompUnitContext * /*ctx*/) override { }

    void enterDecl(CACTParser::DeclContext * /*ctx*/) override { }
    void exitDecl(CACTParser::DeclContext * /*ctx*/) override { }

    void enterConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override;
    void exitConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override;

    void enterBType(CACTParser::BTypeContext * /*ctx*/) override { }
    void exitBType(CACTParser::BTypeContext * /*ctx*/) override { }

    void enterConstDef(CACTParser::ConstDefContext * /*ctx*/) override { }
    void exitConstDef(CACTParser::ConstDefContext * /*ctx*/) override { }

    void enterConstInitVal(CACTParser::ConstInitValContext * /*ctx*/) override { }
    void exitConstInitVal(CACTParser::ConstInitValContext * /*ctx*/) override { }

    void enterVarDecl(CACTParser::VarDeclContext * /*ctx*/) override;
    void exitVarDecl(CACTParser::VarDeclContext * /*ctx*/) override;

    void enterVarDef(CACTParser::VarDefContext * /*ctx*/) override { }
    void exitVarDef(CACTParser::VarDefContext * /*ctx*/) override { }

    void enterConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override { }
    void exitConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override;

    void enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override { }
    void exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override { }

    void enterNumber(CACTParser::NumberContext * /*ctx*/) override { }
    void exitNumber(CACTParser::NumberContext * /*ctx*/) override { }


    void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
    void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
    void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
    void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }
};
