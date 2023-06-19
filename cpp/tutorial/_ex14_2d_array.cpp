#include <iostream>
#include <vector>

using namespace std;

#define tr(c, it) \
        for (typeof(c.begin())it = c.begin(); it != c.end(); it++)

int main(void)
{
    int row_cnt = 3;
    int col_cnt = 4;
    int i, j;


    int **matrix = new int *[row_cnt];
    for (i = 0; i < row_cnt; i++) {
        matrix[i] = new int[col_cnt];
    }

    for (i = 0; i < row_cnt; i++) {
        for (j = 0; j < col_cnt; j++) {
            //cout << "touching ... " << i << ", " << j << endl;
            //*(matrix[i] + j) = (i * col_cnt) + j;
            matrix[i][j] = (i * col_cnt) + j;
            //cout << "............ " << i << ", " << j << endl;
        }
    }

    vector< vector<int> >matrix_i(row_cnt, vector<int>(col_cnt, -1));

    for (i = 0; i < row_cnt; i++) {
        for (j = 0; j < col_cnt; j++) {
            cout << "matrix[" << i << "]";
            cout << "[" << j << "]";
            cout << " = " << matrix[i][j] << endl;
            matrix_i[i][j] = matrix[i][j];
        }
    }

    for (i = 0; i < row_cnt; i++) {
        delete [] matrix[i];
    }

    for (i = 0; i < row_cnt; i++) {
        for (j = 0; j < col_cnt; j++) {
            cout << "matrix_i[" << i << "]";
            cout << "[" << j << "]";
            cout << " = " << matrix_i[i][j] << endl;
        }
    }
    tr(matrix_i, row) {
        tr((*row), element) {
            cout << *element << ", ";
        }
    }
    cout << endl;

    return 0;
}
