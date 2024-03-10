cat tests/generator_test03.in | xargs java GenPoints
# cat tests/generator_test01.in | xargs java GenPoints > tests/generator_test01.out > tests/searcher_test01.in
# cat tests/generator_test02.in | xargs java GenPoints > tests/generator_test02.out > tests/searcher_test02.in
# cat tests/generator_test03.in | xargs java GenPoints > tests/generator_test03.out > tests/searcher_test03.in
# cat tests/generator_test04.in | xargs java GenPoints > tests/generator_test04.out > tests/searcher_test04.in
# cat tests/generator_test05.in | xargs java GenPoints > tests/generator_test05.out > tests/searcher_test05.in

# cat tests/searcher_test01.in | ./smallest_triangle
# cat tests/searcher_test02.in | ./smallest_triangle
# cat tests/searcher_test03.in | ./smallest_triangle
# cat tests/searcher_test04.in | ./smallest_triangle
# cat tests/searcher_test05.in | ./smallest_triangle