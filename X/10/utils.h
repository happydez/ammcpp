#include <iostream>
#include <cmath>

using namespace std;

long long FindDetermenant(double** m, long long n);
void      MatrixTranspose(double**& matrix, long long& m, long long& n);
bool      IsValidIndexes(long long m, long long n);
double**  AlgbMatrix(double** matrix, long long n, long long m);
void      MatrixMultiply(double** matrix, long long n, long long m, double delta);
double**  MatrixMultiply(double** matrixA, long long mA, long long nA, double** matrixB, long long mB, long long nB);
double*   InverseMatrix(double** matrix, long long n, long long m, double** vec, bool f);

double*  AverageMethod(double* A, double* B);
double*  LeastSquaresMethod(double* A, double* B);
double*  SelectedPointsMethod(double* A, double* B);

void ShowArr(double* a, long long n, long long m);
void ShowArr(double** a, long long n, long long m, bool we);