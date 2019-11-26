#include "hipala_matrix.h"
#include "hipala_vector.h"
#include <iostream>

using namespace std;

Hipala_Matrix_Type<int> a(3, 3);
Hipala_Matrix_Type<int> b(3, 3);

int main() {
    freopen("intput.txt", "r", stdin);
    a.input_mat();
    b.input_mat();

    cout << "a = \n";
    a.output_mat();
    cout << "b = \n";
    b.output_mat();
    Hipala_Matrix_Type<int> c(3, 3);
    c = a + b;
    c.output_mat();
}