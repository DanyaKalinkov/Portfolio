OBJ_DIR = object
OBJ_LIB = library


all: danya_decimal.a


danya_decimal.a:
	gcc -c danya_additional.c -o $(OBJ_DIR)/danya_additional.o
	gcc -c danya_decimal.c -o $(OBJ_DIR)/danya_decimal.o
	ar r $(OBJ_LIB)/danya_additional.a $(OBJ_DIR)/*.o


clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OBJ_LIB)/*.a