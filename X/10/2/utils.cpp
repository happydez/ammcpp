#include "utils.h"

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
    auto algb = new double*[n];
    for (int i = 0; i < n; i++) {
        algb[i] = new double[m];
        
    }

    int e = 1;
    
    // a00 a01 a02
    // a10 a11 a12
    // a20 a21 a22

    algb[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
    algb[0][1] = -1 * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);
    algb[0][2] = matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1];
    algb[1][0] = -1 * (matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1]);
    algb[1][1] = matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2];
    algb[1][2] = -1 * (matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]);
    algb[2][0] = matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2];
    algb[2][1] = -1 * (matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]);
    algb[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    return algb;
}

void MatrixMultiply(double** matrix, int n, int m, double delta) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = matrix[i][j] / delta;
        }
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

double** InverseMatrix(double** matrix, int n, int m, double** vec) {
    int det = FindDetermenant(matrix, n);
    MatrixTranspose(matrix, n, m);
    auto algb = AlgbMatrix(matrix, n, m);

    auto X = MatrixMultiply(algb, n, m, vec, 3, 1);
    MatrixMultiply(X, 3, 1, ((double)det));

    for (int i = 0; i < 3; i++) {
        delete [] vec[i];
    }
    delete [] vec;

    for (int i = 0; i < n; i++) {
        delete [] algb[i];
        delete [] matrix[i];
    }
    delete [] algb;
    delete [] matrix;

    return X;
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

void ShowArr(double** a, int n, int m, bool we = true) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        if (we) cout << endl;
    }
    cout << endl;
}

double** LeastSquaresMethod(double* tvec, double* Tvec, int vlen) {
    auto m = new double*[3];
    auto v = new double*[3];
    for (int i = 0; i < 3; i++) {
        m[i] = new double[3];
        v[i] = new double[1];
        for (int j = 0; j < 3; j++) m[i][j] = 0;
        v[i][0] = 0;
    }

    m[0][0] = vlen;
    for (int i = 0; i < vlen; i++) {
        m[0][1] += tvec[i];
        m[0][2] += (tvec[i] * tvec[i]);
        v[0][0] += Tvec[i];

        m[1][0] += tvec[i];
        m[1][1] += (tvec[i] * tvec[i]);
        m[1][2] += (tvec[i] * tvec[i] * tvec[i]);
        v[1][0] += (Tvec[i] * tvec[i]);

        m[2][0] += (tvec[i] * tvec[i]);
        m[2][1] += (tvec[i] * tvec[i] * tvec[i]);
        m[2][2] += (tvec[i] * tvec[i] * tvec[i] * tvec[i]);
        v[2][0] += (Tvec[i] * tvec[i] * tvec[i]);
    }

   // cout << "m:" << endl;
   // ShowArr(m, 3, 3, false);
   //
   // cout << endl;
   // 
   // cout << "v:" << endl;
   // ShowArr(v, 3, 1, false);

    return InverseMatrix(m, 3, 3, v);
}

double** AverageMethod(double* tvec, double* Tvec, int vlen) {
    int M = vlen / 3;

    auto m = new double*[3];
    auto v = new double*[3];
    for (int i = 0; i < 3; i++) {
        m[i] = new double[3];
        v[i] = new double[1];
    }

    v[0][0] = Tvec[0] + Tvec[1];
    v[1][0] = Tvec[2] + Tvec[3];
    v[2][0] = Tvec[4] + Tvec[5];

    m[0][0] = m[1][0] = m[2][0] = 2.;
    m[0][1] = tvec[0] + tvec[1]; m[0][2] = (tvec[0] * tvec[0]) + (tvec[1] * tvec[1]);
    m[1][1] = tvec[2] + tvec[3]; m[1][2] = (tvec[2] * tvec[2]) + (tvec[3] * tvec[3]);
    m[2][1] = tvec[4] + tvec[5]; m[2][2] = (tvec[4] * tvec[4]) + (tvec[5] * tvec[5]);

    return InverseMatrix(m, 3, 3, v);
}

double** SelectedPointsMethod(double t1, double t2, double t3, double T1, double T2, double T3) {
    auto m = new double*[3];
    auto v = new double*[3];
    for (int i = 0; i < 3; i++) {
        m[i] = new double[3];
        v[i] = new double[1];
    }

    v[0][0] = T1;
    v[1][0] = T2;
    v[2][0] = T3;

    m[0][0] = m[1][0] = m[2][0] = 1;
    m[0][1] = t1; m[0][2] = t1 * t1;
    m[1][1] = t2; m[1][2] = t2 * t2;
    m[2][1] = t3; m[2][2] = t3 * t3;

    return InverseMatrix(m, 3, 3, v);
}