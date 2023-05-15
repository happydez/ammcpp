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

void MatrixTranspose(double**& matrix, int& m, int& n) {
	if (IsValidIndexes(m, n) && (matrix != nullptr)) {
		auto newMatrix = new double*[n];
		
		for (int i = 0; i < n; i++) {
			newMatrix[i] = new double[m];
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				newMatrix[j][i] = matrix[i][j];
			}
		}

		int t = m;
		m = n;
		n = t;

		for (int i = 0; i < m; i++) {
			delete[] matrix[i];
		}

		delete[] matrix;

		matrix = newMatrix;
	}
}

double** AlgbMatrix(double** matrix, int n, int m) {
    auto algb = new double*[m];
    for (int i = 0; i < n; i++) {
        algb[i] = new double[m];
        
    }
}

double** MatrixMultiply(double** matrixA, int mA, int nA, double** matrixB, int mB, int nB) {
	if (IsValidIndexes(mA, nA) && IsValidIndexes(mB, nB) && (nA == mB) && (matrixA != nullptr) && (matrixB != nullptr)) {
		auto matrixC = new double*[mA];

		for (int i = 0; i < mA; i++) {
			matrixC[i] = new double[nB];
		}

		for (int i = 0; i < mA; i++) {
			for (int j = 0; j < nB; j++) {
				matrixC[i][j] = 0;
				for (int k = 0; k < nA; k++) {
					matrixC[i][j] += (matrixA[i][k] * matrixB[k][j]);
				}
			}
		}

		return matrixC;
	}

	return nullptr;
}

bool IsValidIndexes(int m, int n) {

	return (m <= 0 || n <= 0) ? false : true;
}

void ShowArr(double* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void ShowArr(double** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}