# Makefile for Assignment 1
CC = gcc
CFLAGS = -O2 -Wall -Werror -Wno-unused-result -std=c99
LDFLAGS = -lm
J = java
JC = javac


GENERATOR_JAVA = GenPoints.java
GENERATOR_CLASS = GenPoints
SEARCHER_SOURCE = smallest_triangle.c
SEARCHER_BINARY = smallest_triangle
TEST_SCRIPT = test.sh

GENERATOR_INPUTS = tests/generator_test01.in tests/generator_test02.in tests/generator_test03.in tests/generator_test04.in
GENERATOR_OUTPUTS = output/generator_test01.out output/generator_test02.out output/generator_test03.out output/generator_test04.out
SEARCHER_INPUTS = tests/searcher_test01.in tests/searcher_test02.in tests/searcher_test03.in tests/searcher_test04.in
SEARCHER_OUTPUTS = output/searcher_test01.out output/searcher_test02.out output/searcher_test03.out output/searcher_test04.out


# non dependency commands for this Makefile
.PHONY: build
.PHONY: $(GENERATOR_CLASS)
.PHONY: $(SEARCHER_BINARY)
.PHONY: sample
.PHONY: test
.PHONY: clean


build: $(GENERATOR_CLASS) $(SEARCHER_BINARY)


$(GENERATOR_CLASS): $(GENERATOR_JAVA)
	$(JC) $(GENERATOR_JAVA)


$(SEARCHER_BINARY): $(SEARCHER_SOURCE)
	$(CC) ${CFLAGS} $(SEARCHER_SOURCE) -o $(SEARCHER_BINARY) $(LDFLAGS)


sample: $(GENERATOR_CLASS)
	$(J) $(GENERATOR_CLASS) -N=20 -mindist=2 -rseed=3


test:$(GENERATOR_CLASS) $(SEARCHER_BINARY)
	chmod u+x $(TEST_SCRIPT)
	./$(TEST_SCRIPT) 


clean: 
	rm $(SEARCHER_OUTPUTS) $(GENERATOR_OUTPUTS)