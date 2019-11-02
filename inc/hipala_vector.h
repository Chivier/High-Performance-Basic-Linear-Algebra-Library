#pragma once

#include <stdlib.h>
#include <string.h>

#define HIPALA_VECTOR_MAX_SIZE 2000

typedef struct Hipala_Matrix_Type {
    int len;
    double num[HIPALA_VECTOR_MAX_SIZE];

    Hipala_Matrix_Type() {
        len = 0;
        memset(num, 0, sizeof(num));
    }
} Mat_;

Mat_ operator+(Mat_ Mat_a, Mat_ Mat_b) {
}

Mat_ operator-(Mat_ Mat_a, Mat_ Mat_b) {
}

Mat_ operator*(Mat_ Mat_a, Mat_ Mat_b) {
}
