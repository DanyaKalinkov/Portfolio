LIB_OBJ_DIR = ./objectFiles
TESTS_DIR = ./tests
GCOV_REPORT_DIR = gcov_report
FILES_TO_MOVE_LIB = danya_additional.o danya_decimal.o
FILES_TO_MOVE_TEST = run_tests
FILES_TO_MOVE_GCOV = coverage_report.css coverage_report.functions.html coverage_report.html coverage_report.danya_decimal.c.5ec9689b4f1b5b52e5de6868910810db.html run_tests run_tests-danya_decimal.gcda run_tests-danya_decimal.gcno


all: danya_decimal.a


danya_decimal.a:
	gcc -Wall -Werror -Wextra -c danya_additional.c -o danya_additional.o
	gcc -Wall -Werror -Wextra -c danya_decimal.c -o danya_decimal.o
	@mv $(FILES_TO_MOVE_LIB) $(LIB_OBJ_DIR)
	ar r danya_decimal.a $(LIB_OBJ_DIR)/*.o


test:
	gcc -Wall -Werror -Wextra tests.c danya_decimal.c danya_additional.c -o run_tests -lcheck -lm -lsubunit
	@mv $(FILES_TO_MOVE_TEST) $(TESTS_DIR)


gcov_report: test
	gcc -Wall -Werror -Wextra tests.c danya_decimal.c danya_additional.c -lcheck -lm -lsubunit -fprofile-arcs -ftest-coverage -o run_tests
	./run_tests
	rm -f run_tests-danya_additional.gcda run_tests-danya_additional.gcno
	rm -f run_tests-tests.gcda run_tests-tests.gcno
	gcovr -r . --html --html-details -o coverage_report.html
	@mv $(FILES_TO_MOVE_GCOV) $(GCOV_REPORT_DIR)


clean:
	rm -f *.a
	rm -f $(LIB_OBJ_DIR)/*.o
	rm -f ./$(GCOV_REPORT_DIR)/*.css
	rm -f ./$(GCOV_REPORT_DIR)/c*.html
	rm -f ./$(GCOV_REPORT_DIR)/*.gcda
	rm -f ./$(GCOV_REPORT_DIR)/*.gcno
	rm -f ./$(GCOV_REPORT_DIR)/run_tests
	rm -f $(TESTS_DIR)/run_tests
