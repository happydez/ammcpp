#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Answ {
    int N;
    double x;
};

double MathF(double x) {
    return 3 * x - 4 * log(x) - 5;
}

double MathFunc(double x)
{
    return (4. * log(x) + 5.) / 3.;
}

Answ Solver_2(double a, double b, double eps, double(*MathFunc)(double)) {
    int i = 1;
    double xk = b;
    double x = MathFunc(xk);

    while (fabs(x - xk) > eps) {
        xk = x;
        i++;
        x = MathFunc(xk);
    }

    return Answ{i, x};
}

int main() {

    auto answ = Solver_2(2., 4., 0.001, MathFunc);
    cout << "N = " << answ.N << endl;
    cout << "x = " << answ.x << endl;

    cout << "f(x) ~ " << MathF(answ.x) << endl;

    cout << string(32, '-') << endl;

    answ = Solver_2(2., 4., 0.00001, MathFunc);

    cout << "N = " << answ.N << endl;
    cout << "x = " << answ.x << endl;

    cout << "f(x) ~ " << MathF(answ.x) << endl;

    return 0;
}