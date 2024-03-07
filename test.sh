cat tests/generator_test01.in | xargs java GenPoints > tests/generator_test01.output
cat tests/generator_test01.output | ./smallest_triangle