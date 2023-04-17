#ifndef _UTILS_
#include "utils.h"
#endif

int FindDetermenant(double** a, int n) {
    if (n == 1) {
        return a[0][0];
    }
    else if (n == 2) {
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    }
    else {
        int d = 0;
        for (int k = 0; k < n; k++) {
            auto m = new double*[n-1];

            for (int i = 0; i < n - 1; i++) {
                    m[i] = new double[n - 1];
            }

            for (int i = 1; i < n; i++) {
                int t = 0;                
                for (int j = 0; j < n; j++) {
                    if (j == k) continue;
                    m[i-1][t] = a[i][j];
                    t++;
                }
            }
            d += pow(-1, k + 2) * a[0][k] * FindDetermenant(m, n - 1);
            for (int z = 0; z < n-1; z++) {
                delete [] m[z];
            }
            delete [] m;
        }
        return d;
    }
}

double* KramerMethod(double** m, double* vec, int n) {
    double det = FindDetermenant(m, n);
    double* res = new double[n];

    auto temp = new double*[n];
    for (int i = 0; i < 3; i++) {
        temp[i] = new double[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int q = 0; q < n; q++) {
                temp[j][q] = m[j][q];
            }
        }

        for (int j = 0; j < n; j++) {
            temp[j][i] = vec[j];
        }

        res[i] = FindDetermenant(temp, 3) / det;
    }

    for (int i = 0; i < n; i++) {
        delete[] temp[i];
    }
    delete [] temp;

    return res;
}

void ShowArr(double* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void ShowArr(double** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}