#ifndef HIPALA_MAXTRIX_H
#define HIPALA_MAXTRIX_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

#define HIPALA_MATRIX_MAX_SIZE 2000

// * This is an example about some modern developing method
// * Here is how I work with `class`
// * As for template, you can visit: https://www.runoob.com/cplusplus/cpp-templates.html
// * to learn more about it.
template <class T>
class Hipala_Matrix_Type {
private:
    // * private means We cannot use these part directly in the program
    // * In another word, a.row or a.num is forbidden in our program
    int row, col;
    T *num;

public:
    // * Construct function
    Hipala_Matrix_Type() : row(0), col(0), num(NULL) {}
    Hipala_Matrix_Type(int num_row, int num_col) : row(num_row), col(num_col) {
        // std::cout << "row = " << row << std::endl;
        // std::cout << "col = " << col << std::endl;
        // * This deals the same as `malloc`
        num = new T[num_row * num_col];
        // std::cout << "Alloc size = " << sizeof(*num);
        // puts("");
    }

    Hipala_Matrix_Type(int Error_info) {
        if (Error_info == -1)
            row = col = -1, num = NULL;
    }

    // ~Hipala_Matrix_Type() {
    //     delete[](num);
    // }
    void operator=(Hipala_Matrix_Type<T> other);
    Hipala_Matrix_Type<T> operator+(Hipala_Matrix_Type<T> other);
    Hipala_Matrix_Type<T> operator-(Hipala_Matrix_Type<T> other);
    Hipala_Matrix_Type<T> operator*(Hipala_Matrix_Type<T> other);

    // * inline can make simple program faster
    inline int show_row();
    inline int show_col();

    void input_mat();
    void output_mat();

    T element(int row, int col);
    T modify(int rowid, int colid, T num);

    Hipala_Matrix_Type<T> sub_mat(int begin_row, int begin_column, int end_row, int end_column);
    double det_val();
};

// * Method name: show_row
// * Function:
// * show the row of the matrix
// * Input: None
// * Output: the row number of this matrix
template <class T>
int Hipala_Matrix_Type<T>::show_row() {
    return row;
}

// * Method name: show_col
// * Function:
// * show the col of the matrix
// * Input: None
// * Output: the col number of this matrix
template <class T>
int Hipala_Matrix_Type<T>::show_col() {
    return col;
}

// * Method name: element
// * Function:
// * show the certain element of the matrix
// * Input:
// * rowid - the row number we require to attach element
// * colid - the column number we require to attach element
// * Output:
// * the element we wanna to attach
template <class T>
T Hipala_Matrix_Type<T>::element(int rowid, int colid) {
    return num[rowid * (col) + colid];
}

// * Method name: modify
// * Function:
// * modify a specific element in the matrix
// * Input:
// * rowid - the row index we want to modify
// * colid - the column index we want to modify
// * mod - the new element
// * Output:
// * the new element
template <class T>
T Hipala_Matrix_Type<T>::modify(int rowid, int colid, T mod) {
    num[rowid * (col) + colid] = mod;
    // puts("modied");
    // printf("num[%d][%d] modified to ", rowid, colid);
    // std::cout << num[rowid * (col) + colid] << std::endl;
    return mod;
}

// * Method name: input_mat
// * Function:
// * read the matrix
// * Input:
// * None
// * Output:
// * None
template <class T>
void Hipala_Matrix_Type<T>::input_mat() {
    T temp;
    for (int rowloop = 0; rowloop < this->row; rowloop++)
        for (int colloop = 0; colloop < this->col; colloop++) {
            std::cin >> temp;
            this->modify(rowloop, colloop, temp);
        }
}

// * Method name: output_mat
// * Function:
// * print the matrix
// * Input:
// * None
// * Output:
// * None
template <class T>
void Hipala_Matrix_Type<T>::output_mat() {
    for (int rowloop = 0; rowloop < this->row; rowloop++) {
        for (int colloop = 0; colloop < this->col; colloop++) {
            std::cout << "   " << this->element(rowloop, colloop);
        }
        std::cout << std::endl;
    }
}

// * Operation overlading: =
// * Function:
// * get a new matrix from right of `=`
template <class T>
void Hipala_Matrix_Type<T>::operator=(Hipala_Matrix_Type<T> other) {
    if (row < other.row || col < other.col) {
        Hipala_Matrix_Type<T> Error(-1);
        row = col = -1;
        return;
	}
    for (int rowloop = 0; rowloop < other.row; ++rowloop)
        for (int colloop = 0; colloop < other.col; ++colloop) {
            this->modify(rowloop, colloop, other.element(rowloop, colloop));
        }
}

// * Operation overlading: +
// * Function:
// * add two matrix
template <class T>
Hipala_Matrix_Type<T> Hipala_Matrix_Type<T>::operator+(Hipala_Matrix_Type<T> other) {
    if (row != other.row || col != other.col) {
        Hipala_Matrix_Type<T> Error(-1);
        return Error;
    }

    Hipala_Matrix_Type<T> Matc(row, col);

    for (int rowloop = 0; rowloop < row; rowloop++) {
        for (int colloop = 0; colloop < col; colloop++) {
            Matc.modify(rowloop, colloop, this->element(rowloop, colloop) + other.element(rowloop, colloop));
        }
    }
    return Matc;
}

template <class T>
Hipala_Matrix_Type<T> Hipala_Matrix_Type<T>::operator-(Hipala_Matrix_Type<T> other) {
	// todo
	if (row != other.row || col != other.col) {
        Hipala_Matrix_Type<T> Error(-1);
        return Error;
    }
    
    Hipala_Matrix_Type<T> Matc(row,col);
    
    for (int rowloop = 0; rowloop < row; rowloop++) {
        for (int colloop = 0; colloop < col; colloop++) {
            Matc.modify(rowloop, colloop, this->element(rowloop, colloop) - other.element(rowloop, colloop));
        }
    }
    return Matc;
}

template <class T>
Hipala_Matrix_Type<T> Hipala_Matrix_Type<T>::operator*(Hipala_Matrix_Type<T> other) {
    // todo
    if (col != other.row) {
        Hipala_Matrix_Type<T> Error(-1);
        return Error;
    }
    
    T temp;
    Hipala_Matrix_Type<T> Matc(row,other.col);
    
    for(int rowloop = 0;rowloop < row; rowloop++)
    	for(int colloop = 0; colloop < other.col; colloop++){
    		temp=element(rowloop, 0) * other.element(0, colloop);
    		for(int __loop = 1; __loop < col; __loop++)
    			temp+=element(rowloop, __loop) * other.element(__loop, colloop);
    		Matc.modify(rowloop, colloop, temp);
		}
    return Matc;
}

Hipala_Matrix_Type<int> input_int_mat(int row, int col);
void output_int_mat(Hipala_Matrix_Type<int> M);

#endif
