#include <iostream>

#include "antlr4-runtime.h"
#include "../grammar/CACTLexer.h"
#include "../grammar/CACTParser.h"
#include "../grammar/CACTBaseListener.h"

#include "semanticAnalysis.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    CACTLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CACTParser parser(&tokens);

    tree::ParseTree *tree = parser.compUnit();

    if (lexer.getNumberOfSyntaxErrors() > 0)
    {
        std::cout << "Error: There is " << lexer.getNumberOfSyntaxErrors() << " syntax errors reported by lexer." << std::endl;
        return 1;
    }
    if (parser.getNumberOfSyntaxErrors() > 0)
    {
        std::cout << "Error: There is " << parser.getNumberOfSyntaxErrors() << " syntax errors reported by parser." << std::endl;
        return 1;
    }

    SemanticAnalysis listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    
    std::cout << "debug: hello" << std::endl;


    std::cout << "-------------------------Print AST:--------------------------" << std::endl;
    std::cout << tree->toStringTree(&parser) << std::endl;

    return 0;
}
