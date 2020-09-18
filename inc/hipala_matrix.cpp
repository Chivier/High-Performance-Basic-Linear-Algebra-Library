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

//todo create a mind map to avoid reviewing code!
Hipala_Matrix_Type<int> transpose_int_mat(Hipala_Matrix_Type<int> M)
    {
        Hipala_Matrix_Type<int> M_(M.show_row(),M.show_col());
        for(int i=0;i<M.show_row(); ++i)
            for(int j=0;j<M.show_col(); ++j)
                {
                    M_.modify(i,j,M.element(j,i));
                }
        return M_;
    }