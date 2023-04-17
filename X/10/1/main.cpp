#include "utils.h"

int main() {

    int n = 3;

    double** matrix = new double*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[n];
    }

    cout << "Input matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << endl;

    double* vec = new double[n];
    cout << "Input vec: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    cout << endl;

    auto result = KramerMethod(matrix, vec, n);
    cout << "Result: ";
    ShowArr(result, n);

    double tmp = 74;
    double res = result[0] + result[1] * tmp + result[2] * tmp * tmp;
    cout << endl;

    cout << "Control temperature: " << tmp << endl;
    cout << "Design resistance: " << res << endl;

    for (int i = 0; i < n; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
    delete [] vec;

    return 0;
}

/*
    auto matrix = new double*[4];
    for (int i = 0; i < 4; i++) {
        matrix[i] = new double[4];
    }

    matrix[0][0] = 6.; matrix[0][1] = 2.; matrix[0][2] = -1.; matrix[0][3] = 1.;
    matrix[1][0] = 0.; matrix[1][1] = 4.; matrix[1][2] = 1.;  matrix[1][3] = 2.;
    matrix[2][0] = 2.; matrix[2][1] = 3.; matrix[2][2] = 4.;  matrix[2][3] = 3.;
    matrix[3][0] = 9.; matrix[3][1] = 8.; matrix[3][2] = 1.;  matrix[3][3] = 3.;

    cout << FindDetermenant(matrix, 4) << endl;

    for (int i = 0; i < 4; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;

*/