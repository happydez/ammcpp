#include <iostream>
#include <cmath>
using namespace std;

double Solve() {
    return ((15 + sqrt(8)) / (sqrt(15) + 8)) + ((6 + sqrt(12)) / (sqrt(6) + 12)) + ((7 + sqrt(21)) + (sqrt(7) + 21));
}

int main() {

    double x = Solve();
    cout << "x = " << x << endl;

    return 0;
}