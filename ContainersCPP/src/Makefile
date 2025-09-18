MAIN_FLAGS = -Wall -Werror -Wextra -std=c++20
TESTS_FLAGS = -lgtest -lgtest_main -lm -lstdc++


all: clean
	gcc $(MAIN_FLAGS) test/*.cpp $(TESTS_FLAGS) -o test/run_tests_containers.out


rebuild: clean
	gcc $(MAIN_FLAGS) test/*.cpp $(TESTS_FLAGS) -o test/run_tests_containers


clean:
	rm -f test/*.out
