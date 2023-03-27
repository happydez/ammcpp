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


int main() {

    auto res = Solve(0.0005, 0.000001);

    cout << res.K << endl;
    cout << res.Res << endl;

    res = Solve(0.0005, 0.01);
    
    cout << res.K << endl;
    cout << res.Res << endl;

    return 0;
}

double Solve(double x) {
    return pow(M_E, -1 * x * x);
}

double Solve(double x, int n) {
    double res = 0.0;

    for (int i = 0; i < n; i++) {
        res = res + ((-1 * x * x) / (i + 1));
    }

    return res;
}

Answer Solve(double x, double eps) {
    int k = 0, i = 0;
    double res = 0.0;

    while (1) {
        if (abs(res + ((-1 * x * x) / (i + 1))) > eps) {
            break;
        }

        res = res + ((-1 * x * x) / (i + 1));
        i++;
        k++;
    }

    return Answer{k, res};
}