CFLAGS=-std=c++14 -Wall -Wextra -Wunreachable-code -Werror
FILE_PREFIX=./src
INCLUDE=-I./${FILE_PREFIX}/solutions/ -I./${FILE_PREFIX}/util/ 
BIN_PREFIX=./target/bin/

ifeq ($(OS),Windows_NT)
	CXX=g++
	SANITIZERS=
else
	#Linux stuff
	CXX=clang++
	SANITIZERS=-fsanitize=address -fsanitize=undefined
endif

all: main test

main: ./${FILE_PREFIX}/main.cpp
	$(CXX) $(SANITIZERS) $(CFLAGS) $(INCLUDE) $< -o $(BIN_PREFIX)$@

PHONY.: test
test: main
	@echo
	@echo "Compilation done, testing main..."
	@echo
	@${BIN_PREFIX}/main
	@echo
	@echo "Testing done. "
	@echo