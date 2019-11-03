CC=g++
CCFLAGS =-O3 -std=c++17 -g
# CC = g++
# CCFLAGS = -O3 -g -fopenmp
BUILD_DIR = ./build
INC_DIR = ./inc
TEST_DIR = ./test/test1

DEPS = hipala_matrix.h hipala_vector.h
OBJ =  hipala_matrix.o hipala_vector.o

.PONEY: clean

test1: $(INC_DIR)/hipala_matrix.h $(INC_DIR)/hipala_vector.h
	$(CC) $(CCFLAGS) -c $(TEST_DIR)/test1.cpp -o $(BUILD_DIR)/test1.o $<

hipala_matrix.o: $(INC_DIR)/hipala_matrix.h
	$(CC) $(CCFLAGS) $(INC_DIR)/hipala_matrix.cpp -o $(BUILD_DIR)/hipala_matrix.o -I$(INC_DIR)/hipala_matrix.h  $<

hipala_vector.o: $(INC_DIR)/hipala_vector.h
	$(CC) $(CCFLAGS) $(INC_DIR)/hipala_vector.cpp -o $(BUILD_DIR)/hipala_vector.o -I$(INC_DIR)/hipala_vector.h  $<
# time_test.o: time_test.h headers.h
# 	$(CC) $(CCFLAGS) -c time_test.cpp $<
# test_generate.o: test_generate.h headers.h
# 	$(CC) $(CCFLAGS) -c test_generate.cpp $<

clean:
	rm -rf *.o $(BUILD_DIR)/*.o