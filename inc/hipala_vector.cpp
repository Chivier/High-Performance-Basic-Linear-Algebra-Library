#include "hipala_vector.h"
Hipala_Vector_Type<int> input_int_vec(int len) {
    Hipala_Vector_Type<int> V(len);
    for (int i = 0; i < V.show_len(); ++i)
	{
            int tmp;
            std::cin >> tmp;
            V.modify(i, tmp);
        }
    return V;
}

void output_int_vec(Hipala_Vector_Type<int> V) {
    for (int i = 0; i < V.show_len(); ++i) {
            std::cout << V.element(i) << "  ";
    }
    std::cout << std::endl;
}
