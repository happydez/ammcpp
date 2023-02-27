#include <iostream>
#include <ctime>
using namespace std;

int SumAtAboveZeroRows(int** m, int n) {
    if (m == nullptr) {
        return 0;
    }

    int sum, temp;
    sum = 0;

    for (int i = 0; i < n; i++) {
        if (m[i] == nullptr) {
            continue;
        }
        temp = 0;
        for (int j = 0; j < n; j++) {
            if (m[i][j] < 0) {
                temp = 0;
                break;
            }
            temp += m[i][j];
        }
        sum += temp;
    }

    return sum;
}

int MainDiagonalSum(int**m, int n) {
    if (m == nullptr) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (m[i] == nullptr) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (i == j) {
                sum += m[i][j];
            }
        }
    }

    return sum;
}

int OtherDiagonalSum(int**m, int n) {
    if (m == nullptr) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (m[i] == nullptr) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (j == (n - i - 1)) {
                sum += m[i][j];
            }
        }
    }

    return sum;
}

int MinSumBetweenDiagonals(int**m, int n) {
    return m == nullptr ? 0 : min(MainDiagonalSum(m, n), OtherDiagonalSum(m, n));
}

int main() {

    srand(time(0));

    int n;
    cout << "Enter size of matrix >> "; cin >> n;

    // 7 8 2  -1
    // 1 2 3  4
    // 4 3 -2 10
    // 1 1 1  1

    // output:
    // 14 6

    cout << "Fill matrix:" << endl;
    int **m = new int*[n];
    for (int i = 0; i < n; i++) {
        m[i] = new int[n];
        for (int j = 0; j < n; j++) {
            //m[i][j] = rand() % 23 - 11;
            cin >> m[i][j];
        }
    }

    int sum = SumAtAboveZeroRows(m, n);
    int min = MinSumBetweenDiagonals(m, n);

    cout << "1. Sum at rows without negative numbers = " << sum << endl;
    cout << "2. Min sum between diagonals = " << min << endl;

    for (int i = 0; i < n; i++) {
        delete [] m[i];
    }

    delete [] m;

    return 0;
}