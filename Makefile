# Makefile for Assignment 1
CC=gcc
CFLAGS=-o
LDFLAGS=-lm
SEARCHER_SOURCE=smallest_triangle.c
SEARCHER_BINARY=smallest_triangle
JAVA=javac
IN=tests/generator_test01.in
GENERATOR_JAVA = GenPoints.java
GENERATOR_OUTPUT = generator_test01.output
GENERATOR_BINARY = GenPoints
TEST_SCRIPT = test.sh


build: generator searcher


generator:$(GENERATOR_JAVA)
	$(JAVA) $(GENERATOR_JAVA)


searcher: $(SEARCHER_SOURCE)
	${CC} ${SEARCHER_SOURCE} ${CFLAGS} ${SEARCHER_BINARY} ${LDFLAGS}


test:$(GENERATOR_BINARY) $(SEARCHER_BINARY)
	chmod u+x $(TEST_SCRIPT)
	./$(TEST_SCRIPT) 

clean:
	rm &(GENERATOR_BINARY) &(SEARCHER_BINARY)

