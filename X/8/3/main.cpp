#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double MathFunc(double x)
{
    return 3 * x - 4 * log(x) - 5;
}

void Solver(int minRange, int maxRange, double(*MathFunc)(double)) {
    
    for (double x = minRange; x <= maxRange; x += 0.0001) {
        if (x >= 3.2300) {
            if (MathFunc(x) <= 0.001) {
                cout << "x = " << fixed << setprecision(4) << x << endl;
                cout << "f(x) = " << MathFunc(x) << endl;
                break;
            }
        }
    }
}

int main() {

    Solver(2, 4, MathFunc);

    return 0;
}