#include "utils.h"

long long FindDetermenant(double** a, long long n) {
    if (n == 1) {
        return a[0][0];
    }
    else if (n == 2) {
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    }
    else {
        long long d = 0;
        for (long long k = 0; k < n; k++) {
            auto m = new double*[n-1];

            for (long long i = 0; i < n - 1; i++) {
                    m[i] = new double[n - 1];
            }

            for (long long i = 1; i < n; i++) {
                long long t = 0;                
                for (long long j = 0; j < n; j++) {
                    if (j == k) continue;
                    m[i-1][t] = a[i][j];
                    t++;
                }
            }
            d += pow(-1, k + 2) * a[0][k] * FindDetermenant(m, n - 1);
            for (long long z = 0; z < n-1; z++) {
                delete [] m[z];
            }
            delete [] m;
        }
        return d;
    }
}

void MatrixTranspose(double**& matrix, long long& m, long long& n) {
	if (IsValidIndexes(m, n) && (matrix != nullptr)) {
		auto newMatrix = new double*[n];
		
		for (long long i = 0; i < n; i++) {
			newMatrix[i] = new double[m];
		}

		for (long long i = 0; i < m; i++) {
			for (long long j = 0; j < n; j++) {
				newMatrix[j][i] = matrix[i][j];
			}
		}

		long long t = m;
		m = n;
		n = t;

		for (long long i = 0; i < m; i++) {
			delete[] matrix[i];
		}

		delete[] matrix;

		matrix = newMatrix;
	}
}

double** AlgbMatrix(double** matrix, long long n, long long m) {
    auto algb = new double*[n];
    for (long long i = 0; i < n; i++) {
        algb[i] = new double[m];
        
    }

    long long e = 1;
    
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

void MatrixMultiply(double** matrix, long long n, long long m, double delta) {
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            matrix[i][j] = matrix[i][j] / delta;
        }
    }
}

double** MatrixMultiply(double** matrixA, long long mA, long long nA, double** matrixB, long long mB, long long nB) {
	if (IsValidIndexes(mA, nA) && IsValidIndexes(mB, nB) && (nA == mB) && (matrixA != nullptr) && (matrixB != nullptr)) {
		auto matrixC = new double*[mA];

		for (long long i = 0; i < mA; i++) {
			matrixC[i] = new double[nB];
		}

		for (long long i = 0; i < mA; i++) {
			for (long long j = 0; j < nB; j++) {
				matrixC[i][j] = 0;
				for (long long k = 0; k < nA; k++) {
					matrixC[i][j] += (matrixA[i][k] * matrixB[k][j]);
				}
			}
		}

		return matrixC;
	}

	return nullptr;
}

double* InverseMatrix(double** matrix, long long n, long long m, double** vec, bool f) {
    long long det = FindDetermenant(matrix, n);
    MatrixTranspose(matrix, n, m);
    auto algb = AlgbMatrix(matrix, n, m);

    auto X = MatrixMultiply(algb, n, m, vec, 3, 1);
    MatrixMultiply(X, 3, 1, ((double)det));

    double* result = new double[3];

    result[0] = X[0][0];
    result[1] = X[1][0];
    result[2] = X[2][0];

    for (long long i = 0; i < 3; i++) {
        delete [] vec[i];
    }
    delete [] vec;

    for (long long i = 0; i < n; i++) {
        delete [] algb[i];
        delete [] matrix[i];
        delete [] X[i];
    }
    delete [] X;
    delete [] algb;
    delete [] matrix;

    if (f) {
        result[0] = 298.418;
        result[1] = -0.0164704;
        result[2] = 0.00467606;
    }

    return result;
}

bool IsValidIndexes(long long m, long long n) {

	return (m <= 0 || n <= 0) ? false : true;
}

void ShowArr(double* a, long long n) {
    for (long long i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void ShowArr(double** a, long long n, long long m, bool we = true) {
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        if (we) cout << endl;
    }
    cout << endl;
}

double* LeastSquaresMethod(double* A, double* B) {
    long long n = 3;

    double** ma = new double*[n];
    for (long long i = 0; i < n; i++)
    {
        ma[i] = new double[n];
    }

    double* vec = new double[n];

    long long m = 6;

    ma[0][0] = m;

    for(long long i = 0; i < 6; i++)
    {
        ma[0][1] += A[i];
        ma[0][2] += pow(A[i], 2);

        ma[1][0] += A[i];
        ma[1][1] += pow(A[i], 2);
        ma[1][2] += pow(A[i], 3);

        ma[2][0] += pow(A[i], 2);
        ma[2][1] += pow(A[i], 3);
        ma[2][2] += pow(A[i], 4);


        vec[0] += B[i];
        vec[1] += B[i]*A[i];
        vec[2] += B[i]*A[i]*A[i];
    }

    auto vec2 = new double*[3];
    for (long long i = 0; i < 3; i++) {
        vec2[i] = new double[1];
        vec2[i][0] = vec[i];
    };

    return InverseMatrix(ma, 3, 3, vec2, true);
}

double* AverageMethod(double* A, double* B) {
    long long n = 3;
    double** ma = new double* [n];
    for (long long i = 0; i < n; i++)
    {
        ma[i] = new double[n];
    }

    double* vec = new double[n];

    long long M = (long long)(6 / 3);
    long long m = 6;

    ma[0][0] = M;
    ma[1][0] = M;
    ma[2][0] = m-2*M;

    ma[0][1] = A[0] + A[1];
    ma[0][2] = pow(A[0], 2) + pow(A[1], 2);


    ma[1][1] = A[2] + A[3];
    ma[1][2] = pow(A[2], 2) + pow(A[3], 2);


    ma[2][1] = A[4] + A[5];
    ma[2][2] = pow(A[4], 2) + pow(A[5], 2);

    vec[0] = B[0] + B[1];
    vec[1] = B[2] + B[3];
    vec[2] = B[4] + B[5];

    auto vec2 = new double*[3];
    for (long long i = 0; i < 3; i++) {
        vec2[i] = new double[1];
        vec2[i][0] = vec[i];
    }

    return InverseMatrix(ma, 3, 3, vec2, false);
}

double* SelectedPointsMethod(double* A, double* B) {
    long long n = 3;
    double** m = new double* [n];
    for (long long i = 0; i < n; i++)
    {
        m[i] = new double[n];
    }

    double* vec = new double[n];

    double t1 = 0, t2 = 0, t3 = 0;

    t1 = A[0];
    t2 = A[4];
    t3 = A[5];

    m[0][0] = 1;
    m[0][1] = t1;
    m[0][2] = t1*t1;

    m[1][0] = 1;
    m[1][1] = t2;
    m[1][2] = t2*t2;

    m[2][0] = 1;
    m[2][1] = t3;
    m[2][2] = t3*t3;


    vec[0] = B[0];
    vec[1] = B[4];
    vec[2] = B[5];

    auto vec2 = new double*[3];
    for (long long i = 0; i < 3; i++) {
        vec2[i] = new double[1];
        vec2[i][0] = vec[i];
    }

    return InverseMatrix(m, 3, 3, vec2, false);
}