#include <iostream>
#include <cmath>

using namespace std;

int      FindDetermenant(double** m, int n);
void     MatrixTranspose(double**& matrix, int& m, int& n);
bool     IsValidIndexes(int m, int n);
double** AlgbMatrix(double** matrix, int n, int m);
void     MatrixMultiply(double** matrix, int n, int m, int delta);
double** MatrixMultiply(double** matrixA, int mA, int nA, double** matrixB, int mB, int nB);
void     InverseMatrix(double** matrix, int n, int m);

void ShowArr(double* a, int n, int m);
void ShowArr(double** a, int n, int m);