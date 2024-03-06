# Makefile for Assignment 1
CC=gcc
CFLAGS=-O2 -Wall -Werror -Wno-unused-result -std=c99
LDFLAGS=-lm
SEARCHER_SOURCE=smallest_triangle.c
SEARCHER_BINARY=smallest_triangle
JAVA=javac
IN=tests/generator_test01.in

generator = GenPoints.java
generator_binary = GenPoints

# non dependency commands for this Makefile
.PHONY: build
.PHONY: generator
.PHONY: searcher
.PHONY: sample
.PHONY: test
.PHONY: clean

# default rule
build: generator searcher
	# commands that are needed to build both your program (no execution)
	echo "TODO"

generator: $(generator)
	javac GenPoints.java
	# commands to build the Generator program (no execution)
	# use only a single file: GenPoints.java or gen_points.py
	echo "TODO"

searcher: $(SEARCHER_SOURCE)
	${CC} ${CFLAGS} ${SEARCHER_BINARY} ${SEARCHER_SOURCE} ${LDFLAGS}
	# commands to build the Searcher program
	# use only a single file: smallest_triangle.c

sample:
	$(JAVA) $(generator) -arg1 -arg2 -arg3 < &(IN) | ./$(SEARCHER_BINARY)
	# execute Generator program with arguments -N=20 -mindist=2 rseed=3 and pipe the result to Searcher program
	echo "TODO"

test:
	# execute all tests
	#  Generator self test - with argsets
	#  Searcher self test
	#  Generator and Searcher end to end tests - with argsets
	# using a test.sh script (any supported scripting language on Ed) is encouraged
	echo "TODO"
	chmod u+x test.sh
	./test.sh 

clean:
	# delete any unwanted build or editing files (not your source files!)
	rm generator_binary
	echo "TODO"

