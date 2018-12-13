CFLAGS=-std=c++14 -Wall -Wextra -Wunreachable-code -Werror
INCLUDE=-I./src/ -I./util/
DEBUG=-DDEBUG
PREFIX=../bin/

all: debug main test

debug: debug.cpp
	g++ $(CFLAGS) $(INCLUDE) $(DEBUG) $< -o $(PREFIX)$@

main: main.cpp
	g++ $(CFLAGS) $(INCLUDE) $(DEBUG) $< -o $(PREFIX)$@

PHONY.: test
test: debug main
	@echo "\nCompilation done, testing main... \n"
	@../bin/main
	@echo "\nTesting done. \n"