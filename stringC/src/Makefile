C_FILES = tests.c danya_c_sharp_func.c danya_common_func.c danya_sprintf.c danya_sscanf.c danya_string.c danya_strtold.c
LIB_OBJ_DIR = ./objectFiles
TESTS_DIR = ./tests
GCOV_REPORT_DIR = gcov_report
FILES_TO_MOVE_LIB = danya_c_sharp_func.o danya_common_func.o danya_sprintf.o danya_sscanf.o danya_string.o danya_strtold.o
FILES_TO_MOVE_TEST = run_tests
FILES_TO_MOVE_GCOV1 = coverage_report.css coverage_report.functions.html coverage_report.html coverage_report.danya_c_sharp_func.c.7c9c83c178273815c27322b32e50badf.html coverage_report.danya_common_func.c.55af8f175cb41857e2ceed4efb1b2469.html 
FILES_TO_MOVE_GCOV2 = coverage_report.danya_sprintf.c.88087e6175c6c90eefc27ce45d75e9fb.html coverage_report.danya_sscanf.c.e40d0abff80ce8928148c8efaef7871e.html coverage_report.danya_string.c.fc595b680dd553e5f244de553cdc5ea6.html
FILES_TO_MOVE_GCOV3 = coverage_report.danya_strtold.c.10d2cf9ce9434ac783c2917b650ccd6a.html
FILES_TO_MOVE_GCOV4 = run_tests-danya_c_sharp_func.gcda run_tests-danya_c_sharp_func.gcno run_tests-danya_common_func.gcda run_tests-danya_common_func.gcno run_tests-danya_sprintf.gcda run_tests-danya_sprintf.gcno
FILES_TO_MOVE_GCOV5 = run_tests-danya_sscanf.gcda run_tests-danya_sscanf.gcno run_tests-danya_string.gcda run_tests-danya_string.gcno run_tests-danya_strtold.gcda run_tests-danya_strtold.gcno run_tests


all: danya_string.a


danya_string.a:
	gcc -Wall -Werror -Wextra -c danya_c_sharp_func.c -o danya_c_sharp_func.o
	gcc -Wall -Werror -Wextra -c danya_common_func.c -o danya_common_func.o
	gcc -Wall -Werror -Wextra -c danya_sprintf.c -o danya_sprintf.o
	gcc -Wall -Werror -Wextra -c danya_sscanf.c -o danya_sscanf.o
	gcc -Wall -Werror -Wextra -c danya_string.c -o danya_string.o
	gcc -Wall -Werror -Wextra -c danya_strtold.c -o danya_strtold.o
	@mv $(FILES_TO_MOVE_LIB) $(LIB_OBJ_DIR)
	ar r danya_string.a $(LIB_OBJ_DIR)/*.o


test:
	gcc -Wall -Werror -Wextra $(C_FILES) -lcheck -lm -lsubunit -o run_tests
	@mv $(FILES_TO_MOVE_TEST) $(TESTS_DIR)


gcov_report: test
	gcc -Wall -Werror -Wextra $(C_FILES) -lcheck -lm -lsubunit -fprofile-arcs -ftest-coverage -o run_tests
	./run_tests
	rm -f run_tests-tests.gcda run_tests-tests.gcno
	gcovr -r . --html --html-details -o coverage_report.html
	@mv $(FILES_TO_MOVE_GCOV1) $(GCOV_REPORT_DIR)
	@mv $(FILES_TO_MOVE_GCOV2) $(GCOV_REPORT_DIR)
	@mv $(FILES_TO_MOVE_GCOV3) $(GCOV_REPORT_DIR)
	@mv $(FILES_TO_MOVE_GCOV4) $(GCOV_REPORT_DIR)
	@mv $(FILES_TO_MOVE_GCOV5) $(GCOV_REPORT_DIR)


clean:
	rm -f *.a
	rm -f *.o *.css *.html *.gcda *.gcno run_tests
	rm -f $(LIB_OBJ_DIR)/*.o
	rm -f ./$(GCOV_REPORT_DIR)/*.css
	rm -f ./$(GCOV_REPORT_DIR)/c*.html
	rm -f ./$(GCOV_REPORT_DIR)/*.gcda
	rm -f ./$(GCOV_REPORT_DIR)/*.gcno
	rm -f ./$(GCOV_REPORT_DIR)/run_tests
	rm -f $(TESTS_DIR)/run_tests
