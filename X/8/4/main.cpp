#include <iostream>
#include <cmath>

using namespace std;

struct Answer {
    int K;
    double Res;
};

double factorial(int n);
double next(int x, int n);

double Solve(double x);
double Solve(double x, int n);
Answer Solve(double x, double eps);


int main() {

    cout << Solve(0) << endl;
    cout << Solve(0, 100) << endl;

    cout << string(32, '-') << endl;

    auto answ = Solve(3, 0.1);
    cout << "k1 = " << answ.K << endl;
    cout << "answ1 = " << answ.Res << endl;

    cout << string(32, '-') << endl;

    answ = Solve(3, 0.001);
    cout << answ.K << endl;
    cout << answ.Res << endl;

    return 0;
}

double Solve(double x) {
    return pow(M_E, -1 * x * x);
}

double Solve(double x, int n) {
    double res = 0.0;

    for (int i = 0; i < n; i++) {
        res += next(x, i);
    }

    return res;
}

Answer Solve(double x, double eps) {
    int k = 0, i = 0;
    double res = 0.0, nxt = 0.0;

    while (1) {
        nxt = next(x, i);
        res = res + nxt;
        i++;
        k++;

        if (abs(res) <= eps) {
            return Answer{k, res};
        }
    }

    return Answer{k, res};
}

double factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

double next(int x, int n) {
    return (pow(-1, n) * (pow(x, 2 * n))) / factorial(n);
}