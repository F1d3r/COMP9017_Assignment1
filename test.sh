# Generator test
# Generator Test01: Points saturation case: N=10, mindist=18.
cat tests/generator_test01.in | xargs java GenPoints > output/generator_test01.out

# Generator Test02: Edge case: points do not saturate: N=10, mindist=17.
cat tests/generator_test02.in | xargs java GenPoints > output/generator_test02.out

# Generator Test03: Test invalid arguments.
cat tests/generator_test03.in | xargs java GenPoints > output/generator_test03.out

# Generator Test04: Edge case: Massive output. N = 1000.
cat tests/generator_test04.in | xargs java GenPoints > output/generator_test04.out

diff -q output/generator_test01.out expected/generator_test01.expect
diff -q output/generator_test02.out expected/generator_test02.expect
diff -q output/generator_test03.out expected/generator_test03.expect
diff -q output/generator_test04.out expected/generator_test04.expect


# Searcher test
# Searcher Test01: 10 points, all correct format.
cat tests/searcher_test01.in | ./smallest_triangle > output/searcher_test01.out

# Searcher Test02: 20 points, all correct format. With editted three VERY close points input.
cat tests/searcher_test02.in | ./smallest_triangle > output/searcher_test02.out

# Searcher Test03: 38 input line, only 1 correct format. Covers all type of incorrect/invalid/duplicated input.
cat tests/searcher_test03.in | ./smallest_triangle > output/searcher_test03.out

# Searcher Test04: Numbers over 1000 inputs will be ignore.
cat tests/searcher_test04.in | ./smallest_triangle > output/searcher_test04.out

diff -q output/searcher_test01.out expected/searcher_test01.expect
diff -q output/searcher_test02.out expected/searcher_test02.expect
diff -q output/searcher_test03.out expected/searcher_test03.expect
diff -q output/searcher_test04.out expected/searcher_test04.expect



# Combination test
# Combination Test01
cat tests/generator_test01.in | xargs java GenPoints |./smallest_triangle > output/searcher_test01.out

# Combination Test02
cat tests/generator_test02.in | xargs java GenPoints |./smallest_triangle > output/searcher_test02.out

# Combination Test03
cat tests/generator_test03.in | xargs java GenPoints |./smallest_triangle > output/searcher_test03.out

# Combination Test04
cat tests/generator_test04.in | xargs java GenPoints |./smallest_triangle > output/searcher_test04.out

diff -q output/searcher_test01.out expected/combined_test01.expect
diff -q output/searcher_test02.out expected/combined_test02.expect
diff -q output/searcher_test03.out expected/combined_test03.expect
diff -q output/searcher_test04.out expected/combined_test04.expect