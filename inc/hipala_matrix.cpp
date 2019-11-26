#include "hipala_matrix.h"
#include <iostream>
// * This is an example

template <class T>
T Hipala_Matrix_Type<T>::element(int rowid, int colid) {
    return (this->num + rowid * (this->row) + this->col);
}

template <class T>
int Hipala_Matrix_Type<T>::modify(int rowid, int colid, int mod) {
    *(this->num + rowid * (this->row) + this->col) = mod;
    return mod;
}

template <class T>
void Hipala_Matrix_Type<T>::input_mat() {
    T temp;
    for (int rowloop = 0; rowloop < this->row; rowloop++)
        for (int colloop = 0; colloop < this->col; colloop++) {
            std::cin >> temp;
            this->modify(rowloop, colloop, temp);
        }
}

template <class T>
void Hipala_Matrix_Type<T>::output_mat() {
    for (int rowloop = 0; rowloop < this->row; rowloop++) {
        for (int colloop = 0; colloop < this->col; colloop++) {
            std::cout << "   " << this->element(rowloop, colloop);
        }
        std::cout << std::endl;
    }
}

template <class T>
Hipala_Matrix_Type<T> Hipala_Matrix_Type<T>::operator+(const Hipala_Matrix_Type<T> other) {
    if (this->row != other.row || this->col != other.col) {
        Hipala_Matrix_Type<T> Error(-1);
        return Error;
    }

    Hipala_Matrix_Type<T> Matc(this->row, this->col);

    for (int rowloop = 0; rowloop < this->row; rowloop++) {
        for (int colloop = 0; colloop < this->col; colloop++) {
            Matc.modify(rowloop, colloop, this->element(rowloop, colloop) + other.element(rowloop, colloop));
        }
    }
    return Matc;
}

template <class T>
Hipala_Matrix_Type<T> Hipala_Matrix_Type<T>::operator-(const Hipala_Matrix_Type<T> other) {
    Hipala_Matrix_Type<T> Matc;
    return Matc;
}

template <class T>
Hipala_Matrix_Type<T> Hipala_Matrix_Type<T>::operator*(const Hipala_Matrix_Type<T> other) {
    Hipala_Matrix_Type<T> Matc;
    return Matc;
}