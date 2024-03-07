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
	# commands that are needed to build both your program (no execution)


generator: $(generator_JAVA)
	$(JAVA) $(generator_JAVA)
	# commands to build the Generator program (no execution)
	# use only a single file: GenPoints.java or gen_points.py


searcher: $(SEARCHER_SOURCE)
	${CC} ${SEARCHER_SOURCE} ${CFLAGS} ${SEARCHER_BINARY} ${LDFLAGS}
	# gcc smallest_triangle.c -o smallest_triangle -lm
	# commands to build the Searcher program
	# use only a single file: smallest_triangle.c

sample: $(IN) $(generator_binary) $(SEARCHER_BINARY) $(generator_output)
	cat $(IN) | xargs java $(generator_binary) > $(generator_output)
	cat $(generator_output) | $(SEARCHER_BINARY)
	# execute Generator program with arguments -N=20 -mindist=2 rseed=3 and pipe the result to Searcher program


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

