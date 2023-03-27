#include <iostream>
#include <cmath>

using namespace std;

double MathFunc(double x)
{
    return 3 * x - 4 * log(x) - 5;
}

void Solver(int minRange, int maxRange, double(*MathFunc)(double)) {
    
    for (double x = minRange; x <= maxRange; x += 0.010) {
        cout << MathFunc(x) << endl;
    }
}

int main() {

    Solver(2, 4, MathFunc);

    return 0;
}