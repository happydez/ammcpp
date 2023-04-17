#include "utils.h"

int main() {

    auto m = new double*[3];
    for (int i = 0; i < 3; i++) {
        m[i] = new double[3];
        for (int j = 0; j < 3; j++) {
            cin >> m[i][j];
        }
    }

    // 3 2 -4
    // 2 -3 1
    // -1 5 -3

    int n = 3;
    InverseMatrix(m, n, n);
    ShowArr(m, n, n);


    for (int i = 0; i < 3; i++) {
        delete [] m[i];
    }
    delete [] m;

    return 0;
}