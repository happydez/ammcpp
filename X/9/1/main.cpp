#include <iostream>
using namespace std;

double Solve(int n) {
    if (n == 0) {
        return 5.0;
    }
    return 0.2 + Solve(n - 1);
}

double SolveIter(int n) {
    double res = 5.0;

    for (int i = 0; i < n; i++) {
        res += 0.2;
    }

    return res;
}

int main() {

    cout << SolveIter(4) << endl;

    // 

    return 0;
}