#include <iostream>
#include <string>

#include "antlr4-runtime.h"
#include "../grammar/CACTLexer.h"
#include "../grammar/CACTParser.h"
#include "../grammar/CACTBaseListener.h"

#include "semanticAnalysis.h"
#include "symbolTable.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::string sourceName = argv[1];
    size_t lastIndex = sourceName.find_last_of("."); 
    std::string rawName = sourceName.substr(0, lastIndex); 
    std::string asmName = rawName + std::string(".s");

    std::ifstream sourceStream;
    sourceStream.open(sourceName);

    ANTLRInputStream input(sourceStream);
    CACTLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CACTParser parser(&tokens);

    tree::ParseTree *tree = parser.compUnit();

    if (lexer.getNumberOfSyntaxErrors() > 0) {
        std::cout << "Error: There is " << lexer.getNumberOfSyntaxErrors() << " syntax errors reported by lexer." << std::endl;
        return 1;
    }
    if (parser.getNumberOfSyntaxErrors() > 0) {
        std::cout << "Error: There is " << parser.getNumberOfSyntaxErrors() << " syntax errors reported by parser." << std::endl;
        return 1;
    }

    // std::cout << "debug: hello" << std::endl;

    // std::cout << "------------------------- AST ------------------------" << std::endl;
    // std::cout << tree->toStringTree(&parser) << std::endl;
    // std::cout << "========================= AST ========================" << std::endl;

    BlockInfo globalBlockInfo(nullptr);
    IRProgram ir(sourceName);
    IRGenerator irGen(&ir);
    SemanticAnalysis listener(&globalBlockInfo, &irGen);

    try {
        tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    } catch(const std::exception& excp) {
        std::cerr << "Semantic Error: " << excp.what() << std::endl;
		return 1;
    }

    ir.print();

    TargetCodeList targetCode;
    ir.targetGen(&targetCode);

    std::ofstream asmStream;
    asmStream.open(asmName);
    asmStream << targetCode;

    return 0;
}
