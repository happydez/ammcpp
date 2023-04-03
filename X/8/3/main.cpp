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
    // x - m * f(x)
    // x = x - m(3 * x - 4 * log(x) - 5)
    // x'= 3 - 4/x
    // x = x - 0.1 * (3 * x - 4 * log(x) - 5) = 0
    return x - 0.52900 * (3. * x - 4.0 * log(x) - 5.0);
}

Answ Solver(double a, double b, double eps, double(*MathFunc)(double)) {

    int i = 1;
    double x = 0;
    double xk = b;
    
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

    auto answ = Solver(2., 4., 0.0001, MathFunc);

    cout << "N = " << answ.N << endl;
    cout << "x = " << answ.x << endl;

    cout <<MathF(answ.x) << endl;

    return 0;
}