#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int InRange(double *slice, int size, double A, double B) {
    if (slice == nullptr) {
        return 0;
    }
    if (A > B) {
        return 0;
    }

    int c = 0;
    for (int i = 0; i < size; i++) {
        if ((A <= slice[i]) && (slice[i] <=B)) {
            c++;
        }
    }

    return c;
}

double SumAfterMax(double *slice, int size) {
    if (slice == nullptr) {
        return 0.0;
    }

    double max, sum;
    max = slice[0], sum = 0.0;

    int q = 0;
    for (int i = 0; i < size; i++) {
        if (slice[i] >= max) {
            max = slice[i];
            q = i;
        }
    }

    if (q == (size - 1)) {
        return 0;
    }

    for (int i = q + 1; i < size; i++) {
        sum += slice[i];
    }

    return sum;
}

void SortAbs(double *slice, int size) {
    if (slice == nullptr || size <= 1) {
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (abs(slice[i]) < abs(slice[j])) {
                swap(slice[i], slice[j]);
            }
        }
    }
}

int main() {

    // 8 | 7 8 10 1 2 3 4 5
    // 5 | -1 -2 -3 -4 -5

    int n;
    cout << "Slice size >> "; cin >> n;

    double *slice = new double[n], A, B;
    
    cout << "Fill slice: ";
    for (int i = 0; i < n; i++) {
        cin >> slice[i];
    }

    cout << string(32, '-') << endl;
    cout << "Input [A, B] range" << endl;
    cout << "A >> "; cin >> A;
    cout << "B >> "; cin >> B;
    cout << string(32, '-') << endl;

    cout << "void   InRange(slice, size, A, B) : " << InRange(slice, n, A, B) << endl;
    cout << "double SumAfterMax(slice, size)   : " << SumAfterMax(slice, n) << endl;
    cout << "void   SortAbs(slice, n)          : ";
    SortAbs(slice, n);
    for (int i = 0; i < n; i++) {
        cout << slice[i] << " ";
    }
    cout << endl;

    delete [] slice;

    return 0;
}