CC=g++
CCFLAGS =-O3 -std=c++17 -g -c

BUILD_DIR = ./build
INC_DIR = ./inc
TEST_DIR = ./test

LIBS = -lm -ldl
DEPS = $(INC_DIR)/hipala_matrix.h $(INC_DIR)/hipala_vector.h
OBJ = $(BUILD_DIR)/hipala_matrix.o  $(BUILD_DIR)/test1.o 

.PONEY: clean clear

test1: $(OBJ) 
	$(CC) $(OBJ) -o $(BUILD_DIR)/test1 -L. -I${INC_DIR}

# hipala_vector.o: $(INC_DIR)/hipala_vector.cpp $(INC_DIR)/hipala_vector.h
# 	$(CC) $(CCFLAGS) $(INC_DIR)/hipala_vector.cpp -I$(INC_DIR) 

$(BUILD_DIR)/test1.o: $(TEST_DIR)/test1.cpp $(INC_DIR)/hipala_matrix.h
	$(CC) $(CCFLAGS) $(TEST_DIR)/test1.cpp -I${INC_DIR} -o $(BUILD_DIR)/test1.o 

$(BUILD_DIR)/hipala_matrix.o: $(INC_DIR)/hipala_matrix.cpp $(INC_DIR)/hipala_matrix.h
	$(CC) $(CCFLAGS) $(INC_DIR)/hipala_matrix.cpp -o $(BUILD_DIR)/hipala_matrix.o

all:test1

clean:
	rm -rf *.o $(BUILD_DIR)/*.o
	rm -rf $(BUILD_DIR)/test*
