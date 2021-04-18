.PHONY: all
all: antlr compiler

.PHONY: antlr
antlr: 
	cd grammar && make

.PHONY: compiler
compiler:
	cd build && make

.PHONY: test
test:
	cd samples && ./test.sh

.PHONY: prepare
prepare: clean_prepare
	mkdir build && cd build && cmake ..

.PHONY: clean_prepare
clean_prepare:
	rm -rf build