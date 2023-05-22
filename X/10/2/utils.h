#include <iostream>
#include <cmath>

using namespace std;

int      FindDetermenant(double** m, int n);
void     MatrixTranspose(double**& matrix, int& m, int& n);
bool     IsValidIndexes(int m, int n);
double** AlgbMatrix(double** matrix, int n, int m);
void     MatrixMultiply(double** matrix, int n, int m, double delta);
double** MatrixMultiply(double** matrixA, int mA, int nA, double** matrixB, int mB, int nB);
double** InverseMatrix(double** matrix, int n, int m, double** vec);

double** AverageMethod(double* tvec, double* Tvec, int vlen);
double** LeastSquaresMethod(double* tvec, double* Tvec, int vlen);
double** SelectedPointsMethod(double t1, double t2, double t3, double T1, double T2, double T3);

void ShowArr(double* a, int n, int m);
void ShowArr(double** a, int n, int m, bool we);