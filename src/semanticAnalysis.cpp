#include "semanticAnalysis.h"

void SemanticAnalysis::enterConstDecl(CACTParser::ConstDeclContext * ctx)
{}
void SemanticAnalysis::exitConstDecl(CACTParser::ConstDeclContext * ctx)
{
    std::cout << "const variable define: " << std::endl;
    for(const auto & const_def : ctx->constDef())
    {
        std::cout << "\tname: " << const_def->Ident()->getText().c_str() \
                << " type: " << ctx->bType()->getText().c_str() << std::endl;
    }
}

void SemanticAnalysis::enterVarDecl(CACTParser::VarDeclContext * ctx)
{}
void SemanticAnalysis::exitVarDecl(CACTParser::VarDeclContext * ctx)
{
    std::cout << "variable define: " << std::endl;
    for(const auto & var_def : ctx->varDef())
    {
        std::cout << "\tname: " << var_def->Ident()->getText().c_str() \
                << " type: " << ctx->bType()->getText().c_str() << std::endl;
    }
}

void SemanticAnalysis::exitConstExpNumber(CACTParser::ConstExpNumberContext * ctx)
{
    ctx->basic_or_array_and_type = ctx->number()->basic_or_array_and_type;
}

