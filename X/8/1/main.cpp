#include <iostream>

using namespace std;

int     ArrayAvg(int* arr, int n);
float   ArrayAvg(float* arr, int n);
double  ArrayAvg(double* arr, int n);

int main() {

    int* nums = new int[9]{-1, 0, -2, 0, -3, 0, -4, 0, -5};

    cout << "Result: " << ArrayAvg(nums, 9) << endl;

    return 0;
}

int ArrayAvg(int* arr, int n) {
    int c = 0;
    int avg = 0;

    for (int i = 0; i < n; i++) {
        if (~i & 1) {
            if (arr[i] < 0) {
                c++;
                avg = avg + arr[i];
            }
        }
    }

    if (c == 0) return 0;

    return (int)(avg / c);
}

float ArrayAvg(float* arr, int n) {
    int c = 0;
    float avg = 0;

    for (int i = 0; i < n; i++) {
        if (~i & 1) {
            if (arr[i] < 0) {
                c++;
                avg = avg + arr[i];
            }
        }
    }

    if (c == 0) return 0;

    return (float)(avg / c);
}

double ArrayAvg(double* arr, int n) {
    int c = 0;
    double avg = 0;

    for (int i = 0; i < n; i++) {
        if (~i & 1) {
            if (arr[i] < 0) {
                c++;
                avg = avg + arr[i];
            }
        }
    }

    if (c == 0) return 0;

    return (double)(avg / c);
}