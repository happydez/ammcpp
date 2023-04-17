#include <iostream>
#include <cmath>

using namespace std;

struct Answer {
    int K;
    double Res;
};

double Solve(double x);
double Solve(double x, int n);
Answer Solve(double x, double eps);


//     const int MaxIter = 500; // максимально допустимое кол-во итераций
//     double x, eps;
//     double ch, y;

//     cout << "x >> "; cin >> x;
//     cout << "eps >> "; cin >> eps;

//     bool done = true;
//     ch = 1; y = ch; // первый член ряда и начальное значение суммы

//     for (int n = 0; fabs(ch) > eps; n++) {
//         ch = ch * ((-1 * x * x) / (n + 1)); // очередной член ряда
//         y += ch; // добавление члена ряда к сумме
//         if (n > MaxIter) {
//             cout << endl << "The row diverges" << endl;
//             done = false;
//             break;
//         }
//     }

//     if (done) {
//         cout << "f(x) = " << y << ", for x = " << x << endl;
//     }

//     cout << Solve(2.5) << endl;

void line() {
    cout << string(32, '-') << endl;
}

int main() {

    // x = 2.5
    // eps = 0.0001

    int n = 50;

    double x = 2.5;
    double eps_1 = 0.00001;
    double eps_2 = 0.0000001;

    cout << "x = 2.5" << endl;
    cout << "eps_1 = 0.01" << endl;
    cout << "eps_2 = 0.0001" << endl;

    line();

    cout << "1. Lib function = " << Solve(x) << endl;

    line();

    cout << "2. Teylor function = " << Solve(x, n) << endl;

    line();

    auto res1 = Solve(x, eps_1);
    auto res2 = Solve(x, eps_2);

    cout << "3. Eps function with eps_1 = " << res1.Res << " / K = " << res1.K << endl;
    cout << "3. Eps function with eps_2 = " << res2.Res << " / K = " << res2.K << endl;

    return 0;
}

double Solve(double x) {
    return pow(M_E, -1 * x * x);
}

double Solve(double x, int n) {
    double ch, y;
    ch = 1; y = ch;

    for (int i = 0; i < n; i++) {
        ch = ch * ((-1 * x * x) / (i + 1)); // очередной член ряда
        y += ch; // добавление члена ряда к сумме
    }

    return y;
}

Answer Solve(double x, double eps) {
    int k = 0;
    double ch, y;
    ch = 1; y = ch;

    for (int n = 0; fabs(ch) > eps; n++) {
        k++;
        ch = ch * ((-1 * x * x) / (n + 1)); // очередной член ряда
        y += ch; // добавление члена ряда к сумме
    }

    return Answer{k, y};
}