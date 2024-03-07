# Makefile for Assignment 1
CC=gcc
CFLAGS=-o
LDFLAGS=-lm
SEARCHER_SOURCE=smallest_triangle.c
SEARCHER_BINARY=smallest_triangle
JAVA=javac
IN=tests/generator_test01.in

generator_JAVA = GenPoints.java
generator_output = generator_test01.output
generator_binary = GenPoints

# non dependency commands for this Makefile
# .PHONY: build
# .PHONY: generator
# .PHONY: searcher
# .PHONY: sample
# .PHONY: test
# .PHONY: clean

# default rule
build: generator searcher


generator: $(generator_JAVA)
	$(JAVA) $(generator_JAVA)


searcher: $(SEARCHER_SOURCE)
	${CC} ${SEARCHER_SOURCE} ${CFLAGS} ${SEARCHER_BINARY} ${LDFLAGS}

sample: $(IN) $(generator_binary) $(SEARCHER_BINARY) $(generator_output)
	cat $(IN) | xargs java $(generator_binary) > $(generator_output)
	cat $(generator_output) | $(SEARCHER_BINARY)


test:
	# execute all tests
	#  Generator self test - with argsets
	#  Searcher self test
	#  Generator and Searcher end to end tests - with argsets
	# using a test.sh script (any supported scripting language on Ed) is encouraged
	chmod u+x test.sh
	./test.sh 

clean:
	# delete any unwanted build or editing files (not your source files!)
	rm generator_binary

