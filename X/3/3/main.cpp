#include <iostream>
#include <cmath>
using namespace std;

void AreaVolume(double d, double h, double &area, double *volume) {
    area = M_PI * (d / 2) * (d / 2);
    *volume = area * h;
}

int main() {

    double d, h, area, vloume;
    area = vloume = 0;

    for (int i = 0; i < 2; i++) {
        cin >> d >> h;
        if (d == 0.0) {
            cout << "d equal 0. it's invalid!" << endl;
            return -1;
        }
        AreaVolume(d, h, area, &vloume);
        cout << "Area = " << area << endl;
        cout << "Volume = " << vloume << endl;
    }

    return 0;
}