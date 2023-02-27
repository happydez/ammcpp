#include <iostream>
#include <cmath>
using namespace std;

double RectangleArea(double a, double b, double u) {
    return a * b * cos(u * M_PI / 180.0);
}

int main() {

    // 4 2 60  = 4
    // 16 4 60 = 32

    double a, b, u, area;
    for (int i = 0; i < 2; i++) {
        cin >> a >> b >> u;
        area = RectangleArea(a, b, u);
        cout << "Area " << i + 1 << " = " << area << endl;
    }

    return 0;
}