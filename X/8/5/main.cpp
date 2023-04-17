#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double PI = 3.14;
const double EPS = 0.001;

double A = 0.5, f0 = 0.0, k = 0.09, m = 1.0;

// 1. Метод половинного деления;
// 2. Метод Ньютона
// 3. Метод итераций

struct Answ {
    int Iters;
    double Result;
};

double SolveFunc(double t);
double SolveFuncD1(double t);
double SolveFuncD2(double t);
double IterSolveFunc(double t);

Answ IterSolve(double t0, double t1, double eps, double(*SolveFunc)(double));
Answ NewtonSolve(double t0, double t1, double eps, double(*SolveFunc)(double));
Answ HalfDivision(double t0, double t1, double eps, double(*SolveFunc)(double));

inline void line() { cout << string(32, '-') << endl; };

int main() {

    auto answ = IterSolve(9.5, 12, EPS, IterSolveFunc);
    cout << "Iter method: i = " << answ.Iters << ", result = " << answ.Result << endl;
    cout << "f(x) ~ " << SolveFunc(answ.Result) << endl;
    line();

    answ = NewtonSolve(9.5, 12, EPS, SolveFunc);
    cout << "Newton method: i = " << answ.Iters << ", result = " << answ.Result << endl;
    cout << "f(x) ~ " << SolveFunc(answ.Result) << endl;
    line();

    answ = HalfDivision(9.5, 12, EPS, SolveFunc);
    cout << "HalfDiv method: i = " << answ.Iters << ", result = " << answ.Result << endl;
    cout << "f(x) ~ " << SolveFunc(answ.Result) << endl;
    line();

    return 0;
}

double IterSolveFunc(double t) {
    return t + A * sin(sqrt(k / m) * t + f0);
}

double SolveFunc(double t) {
    return A * sin(sqrt(k / m) * t + f0);
}

double SolveFuncD1(double t) {
    return (3 * cos(0.3 * t)) / 20.;
}

double SolveFuncD2(double t) {
    return -1 * ((9 * sin(0.3 * t)) / 200.);
}

Answ IterSolve(double t0, double t1, double eps, double(*SolveFunc)(double)) {
    int i = 1;
    double xt = t1;
    double x = SolveFunc(xt);

    while (fabs(x - xt) > eps) {
        xt = x;
        i++;
        x = SolveFunc(xt);
    }

    return Answ{i, x};
}

Answ NewtonSolve(double t0, double t1, double eps, double(*SolveFunc)(double)) {
    int i = 1;
    double t = 0.0;

    double fD = SolveFuncD1(t0);
    double sD = SolveFuncD2(t0);
    
    t = (fD * sD > 0) ? t0 : t1;

    double h = 0.;

    do {
        h = -1 * SolveFunc(t) / fD;
        t += h;
        i++;
    } while (fabs(h) > eps);

    return Answ{i, t};
}

Answ HalfDivision(double t0, double t1, double eps, double(*SolveFunc)(double)) {
    int i = 1;
    double t = 0.0;

    do {
        t = (t0 + t1) / 2.0;

        if (SolveFunc(t) * SolveFunc(t0) < 0) {
            t1 = t;
        } else {
            t0 = t;
        }

        if (fabs(t1 - t0) <= 2 * eps) {
            break;
        }

        i++;
    } while(1);

    return Answ{i, t};
}