#define _UTILS_

#include <iostream>
#include <cmath>

using namespace std;

/// @param(m) - матрица
/// @param(n) - size
int FindDetermenant(double** m, int n);

/// @param(m) - матрица
/// @param(vec) - вектор свободных коэф
double* KramerMethod(double** m, double* vec, int n);

void ShowArr(double* a, int n);
void ShowArr(double** a, int n);