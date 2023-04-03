#include <iostream>
using namespace std;

double Solve(int n) {
    if (n == 0) {
        return 5.0;
    }
    return 0.2 + Solve(n - 1);
}

int main() {

    cout << Solve(1) << endl;
    cout << Solve(2) << endl;
    cout << Solve(3) << endl;
    cout << Solve(4) << endl;
    cout << Solve(5) << endl;

    return 0;
}