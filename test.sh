cat tests/generator_test01.in | xargs java GenPoints | diff tests/generator_test01.expected -
cat tests/generator_test01.in | xargs java GenPoints | ./smallest_triangle