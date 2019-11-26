#ifndef HIPALA_MAXTRIX_H
#define HIPALA_MAXTRIX_H

#include <stdlib.h>
#include <string.h>

#define HIPALA_MATRIX_MAX_SIZE 2000

template <class T>
class Hipala_Matrix_Type {
private:
    int row, col;
    T *num;

public:
    Hipala_Matrix_Type() {
        row = col = 0;
        num = NULL;
    }
    Hipala_Matrix_Type(int num_row, int num_col) {
        row = num_row;
        col = num_col;
        num = (T *)malloc(sizeof(T) * num_row * num_col);
    }

    Hipala_Matrix_Type(int Error_info) {
        if (Error_info == -1)
            row = col = -1, num = NULL;
    }
    ~Hipala_Matrix_Type() {
        free(num);
    }

    void input_mat();
    void output_mat();

    Hipala_Matrix_Type<T> operator+(const Hipala_Matrix_Type<T> other);
    Hipala_Matrix_Type<T> operator-(const Hipala_Matrix_Type<T> other);
    Hipala_Matrix_Type<T> operator*(const Hipala_Matrix_Type<T> other);

    T element(int row, int col);
    int modify(int rowid, int colid, int num);

    Hipala_Matrix_Type<T> sub_mat(int begin_row, int begin_column, int end_row, int end_column);
    double det_val();
};

#endif