# Optimize, turn on additional warnings
CFLAGS=-O0 -g -ggdb -Wall -Wextra

DEBUGCFLAGS=

.PHONY: all
all: imageGenerator
imageGenerator: BinFun.h BinFun.cpp ConfigParser.h ConfigParser.cpp ConstFun.h Function.h FunctionGenerator.h FunctionGenerator.cpp FunctionParts.h generators.h generators.cpp lodepng.h main.h main.cpp UnaryFunction.h UnaryFunction.cpp
	g++ $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f imageGenerator
