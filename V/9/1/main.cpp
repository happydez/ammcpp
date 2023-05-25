#include <iostream>
#include <cmath>

using namespace std;

int FirstIter(int n) {
    int res = 1;

    for (int i = 1; i <= n; i++) {
        res += 2;
    }

    return res;
}

int FirstRecursion(int n) {
    if (n == 1) {
        return 3;
    }

    return 2 + FirstRecursion(n - 1);
}

double SecondIter(int n = 30) {
    double y = 0.0;

    for (double x = 3.0; x <= n; x++) {
        y = y + (2 * pow(x, 0.5));
    }

    return y;
}

double SecondRecursion(double n = 30) {
    if (n == 3) {
        return 2 * pow(n, 0.5);
    }

    return (2 * pow(n, 0.5)) + SecondRecursion(n - 1);
}

int main() {

    int n = 5;

    cout << "FirstIter" << endl;
    cout << "n = " << n << ": " << FirstIter(n) << endl << endl;

    cout << "FirstRecursion" << endl;
    cout << "n = " << n << ": " << FirstRecursion(n) << endl << endl;

    cout << string(32, '-') << endl << endl;

    n = 30;

    cout << "SecondIter" << endl;
    cout << "n = " << n << ": " << SecondIter(n) << endl << endl;

    cout << "SecondRecursion" << endl;
    cout << "n = " << n << ": " << SecondRecursion(n) << endl << endl;

    return 0;
}
