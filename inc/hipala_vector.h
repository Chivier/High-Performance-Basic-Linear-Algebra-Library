#ifndef HIPALA_VECTOR_H
#define HIPALA_VECTOR_H

#include <stdlib.h>
#include <string.h>
#include <iostream>

#define HIPALA_VECTOR_MAX_SIZE 2000


template <class T>
class Hipala_Vector_Type {
private:
	int len;
	T *num;
public:
	Hipala_Vector_Type() : len(0), num(NULL) {}
	Hipala_Vector_Type(int num_len) : len(num_len) {
		// std::cout << "len = " << len << std::endl;
		num = new T[num_len];
		// std::cout << "Alloc size = " << sizeof(*num);
	}
	
	/*
	Hipala_Vector_Type(int Error_info) {
		if(Error == -1)
			len = -1, num = NULL;
	}*/
	
	// ~Hipala_Vector_Type() {
    //     delete[](num);
    // }
    void operator=(Hipala_Vector_Type<T> other);
    Hipala_Vector_Type<T> operator+(Hipala_Vector_Type<T> other);
    Hipala_Vector_Type<T> operator-(Hipala_Vector_Type<T> other);
    T operator*(Hipala_Vector_Type<T> other);
    
    inline int show_len();
    
	void input_vec();
	void output_vec();
	
	T element(int lenid);
	T modify(int lenid, T mod);
};

template <class T>
int Hipala_Vector_Type<T>::show_len() {
    return len;
}

template <class T>
T Hipala_Vector_Type<T>::element(int lenid) {
    return num[lenid];
}

template <class T>
T Hipala_Vector_Type<T>::modify(int lenid, T mod) {
    num[lenid] = mod;
    // puts("modified");
    // printf("num[%d] modified to ", lenid);
    // std::cout << num[lenid] << std::endl;
    return mod;
}

template <class T>
void Hipala_Vector_Type<T>::input_vec() {
    T temp;
    for (int loop = 0; loop < this->len; loop++) {
        std::cin >> temp;
        this->modify(loop, temp);
    }
}

template <class T>
void Hipala_Vector_Type<T>::output_vec() {
    for (int loop = 0; loop < this->len; loop++) {
        std::cout << "   " << this->element(loop);
    }
    std::cout << std::endl;
}


template <class T>
void Hipala_Vector_Type<T>::operator=(Hipala_Vector_Type<T> other) {
	this->len = other.len;
	for(int loop = 0;loop < other.len; loop++){
		this->modify(loop, other.element(loop));
	}
} 

template <class T>
Hipala_Vector_Type<T> Hipala_Vector_Type<T>::operator+(Hipala_Vector_Type<T> other) {
    if (len != other.len) {
        Hipala_Vector_Type<T> Error(-1);
        return Error;
    }
    
    Hipala_Vector_Type<T> Vecc(len);

    for (int loop = 0; loop < len; loop++) {
        Vecc.modify(loop, this->element(loop) + other.element(loop));
    }
    return Vecc;
}

template <class T>
Hipala_Vector_Type<T> Hipala_Vector_Type<T>::operator-(Hipala_Vector_Type<T> other) {
    if (len != other.len) {
        Hipala_Vector_Type<T> Error(-1);
        return Error;
    }
    
    Hipala_Vector_Type<T> Vecc(len);

    for (int loop = 0; loop < len; loop++) {
        Vecc.modify(loop, this->element(loop) - other.element(loop));
    }
    return Vecc;
}

template <class T>
T Hipala_Vector_Type<T>::operator*(Hipala_Vector_Type<T> other) {
	if (len != other.len) {
        Hipala_Vector_Type<T> Error(-1);
        return Error;
    }
    
	T result;
	
	result = this->element(0) * other.element(0);
	for(int loop = 1; loop < len; loop++){
		result+=this->element(loop) * other.element(loop);
	}
	return result;
}
#endif
