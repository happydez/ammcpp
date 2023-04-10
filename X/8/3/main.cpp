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

// x = (4 * log(x) + 5) / 3;

double MathFunc(double x)
{
    // x - m * f(x)
    // x = x - m(3 * x - 4 * log(x) - 5)
    // x'= 3 - 4/x
    // x = x - 0.1 * (3 * x - 4 * log(x) - 5) = 0
    //return x - 0.5 * (3. * x - 4.0 * log(x) - 5.0);
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

// Unworkable func
Answ Solver(double a, double b, double eps, double(*MathFunc)(double)) {

    int i = 0;
    double x = 0;
    double xk = a;
    
    x = MathFunc(xk);

    while (fabs(x - xk) > eps)
    {
        x = MathFunc(xk);
        xk = x;
        i++;
    }

    return Answ{i, x};
}

int main() {

    //auto answ = Solver_2(2., 4., 0.001, MathFunc);
    auto answ = Solver_2(2., 4., 0.001, MathFunc);

    cout << "N = " << answ.N << endl;
    cout << "x = " << answ.x << endl;

    cout << "f(x) ~ " << MathF(answ.x) << endl;

    return 0;
}