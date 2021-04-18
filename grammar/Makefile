ANTLR4 = java -Xmx500M -cp "/home/comiler1/lib/antlr-4.8-complete.jar:${CLASSPATH}" org.antlr.v4.Tool 
GRUN = java -Xmx500M -cp "/usr/local/lib/antlr-4.9-complete.jar:${CLASSPATH}" org.antlr.v4.gui.TestRig
GRAMMER_FILE = CACT.g4

all: CACT.g4
	@echo "Generating lexer and parser code..."
	@echo "antlr4 -Dlanguage=Cpp ${GRAMMER_FILE}"
	@${ANTLR4} -Dlanguage=Cpp ${GRAMMER_FILE}

.PHONY : all

clean:
	

.PHONY : clean