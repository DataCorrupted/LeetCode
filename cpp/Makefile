CFLAGS=-std=c++14 -Wall -Wextra -Wunreachable-code -Werror
INCLUDE=-I./src/ -I./util/ 
DEBUG=-DDEBUG
PREFIX=./target/bin/

ifeq ($(OS),Windows_NT)
	CXX=g++
	SANITIZERS=
else
	#Linux stuff
	CXX=clang++
	SANITIZERS=-fsanitize=address -fsanitize=undefined
endif

all: main test

main: main.cpp
	$(CXX) $(SANITIZERS) $(CFLAGS) $(INCLUDE) $(DEBUG) $< -o $(PREFIX)$@

PHONY.: test
test: main
	@echo
	@echo "Compilation done, testing main..."
	@echo
	@${PREFIX}/main
	@echo
	@echo "Testing done. "
	@echo