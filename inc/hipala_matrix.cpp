#include "hipala_matrix.h"
Hipala_Matrix_Type<int> input_int_mat(int row, int col) {
    Hipala_Matrix_Type<int> M(row, col);
    for (int i = 0; i < M.show_row(); ++i)
        for (int j = 0; j < M.show_col(); ++j) {
            int tmp;
            std::cin >> tmp;
            M.modify(i, j, tmp);
        }
    return M;
}

void output_int_mat(Hipala_Matrix_Type<int> M) {
    for (int i = 0; i < M.show_row(); ++i) {
        for (int j = 0; j < M.show_col(); ++j) {
            std::cout << M.element(i, j) << "  ";
        }
        std::cout << std::endl;
    }
}
