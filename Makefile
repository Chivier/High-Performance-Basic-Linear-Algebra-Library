CC=g++
CCFLAGS =-O3 -std=c++17 -g -c
# CC = g++
# CCFLAGS = -O3 -g -fopenmp
BUILD_DIR = ./build
INC_DIR = ./inc
TEST_DIR = ./test

DEPS = $(INC_DIR)/hipala_matrix.h $(INC_DIR)/hipala_vector.h
OBJ =  test1.o hipala_matrix.o hipala_vector.o

.PONEY: clean clear

test1: $(OBJ)
	$(CC)  -o $(BUILD_DIR)/test1 $(OBJ) 
	#rm -rf *.o $(BUILD_DIR)/*.o

test1.o: $(TEST_DIR)/test1.cpp $(INC_DIR)/hipala_matrix.h $(INC_DIR)/hipala_vector.h
	$(CC) $(CCFLAGS) $(TEST_DIR)/test1.cpp -I$(INC_DIR)

hipala_matrix.o: $(INC_DIR)/hipala_matrix.cpp $(INC_DIR)/hipala_matrix.h
	$(CC) $(CCFLAGS) $(INC_DIR)/hipala_matrix.cpp  -I$(INC_DIR) 

hipala_vector.o: $(INC_DIR)/hipala_vector.cpp $(INC_DIR)/hipala_vector.h
	$(CC) $(CCFLAGS) $(INC_DIR)/hipala_vector.cpp -I$(INC_DIR) 
	
clean:
	rm -rf *.o $(BUILD_DIR)/*.o

clear:
	rm -rf *.o  $(BUILD_DIR)/*.o $(BUILD_DIR)/test*