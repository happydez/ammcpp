#define _UTILS_

#include <iostream>
#include <cmath>

using namespace std;

int FindDetermenant(double** m, int n);
void MatrixTranspose(double**& matrix, int& m, int& n);
bool IsValidIndexes(int m, int n);

void ShowArr(double* a, int n, int m);
void ShowArr(double** a, int n, int m);