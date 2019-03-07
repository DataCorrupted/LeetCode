CFLAGS=-std=c++14 -Wall -Wextra -Wunreachable-code -Werror
INCLUDE=-I./src/ -I./util/ 
DEBUG=-DDEBUG
PREFIX=../bin/

all: main test

main: main.cpp
	clang++ -fsanitize=address $(CFLAGS) $(INCLUDE) $(DEBUG) $< -o $(PREFIX)$@

PHONY.: test
test: main
	@echo "\nCompilation done, testing main... \n"
	@../bin/main
	@echo "\nTesting done. \n"