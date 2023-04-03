#include <iostream>
#include <cmath>
using namespace std;

double Solve(double x, int n) {
    if (n <= 3) {
        return pow(2, x) / sin(x);
    }
    return (pow(2, x) / sin(x)) + Solve(x, n - 1);
}

double Solve_WithoutRec(double x, int n) {
    double sum = 0.0;

    for (int i = 3; i <= n; i++) {
        sum += (pow(2, x) / sin(x));
    }

    return sum;
}

int main() {

    cout << Solve(1, 8) << endl;
    cout << Solve_WithoutRec(1, 8) << endl;

    return 0;
}