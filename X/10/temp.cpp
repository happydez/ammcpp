#include "utils.h"
#include <string>
#include <iomanip>
using namespace std;

double mathfunc(double t, double a0, double a1, double a2) {
    return a0 + a1 * t + a2 * t * t;
}

void ShowVec(double* vec, int n) {
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    double tvec[] = {1., 5., 10., 15., 20., 40.};
    double Tvec[] = {300., 297., 297., 300., 301., 305.};
 
    double* X1 = SelectedPointsMethod(tvec, Tvec); // 300.023 -0.0267206 0.00377868 
    double* X2 = AverageMethod(tvec, Tvec); // 298.774 -0.125983 0.00800562 
    double* X3 = LeastSquaresMethod(tvec, Tvec); // 298.418 -0.0164703 0.00467606

    cout << "\nSelectedPointsMethod Xvec:" << endl;
    ShowVec(X1, 3);
    
	cout << "\nAverageMethod Xvec:" << endl;
    ShowVec(X2, 3);

	cout << "\nLeastSquaresMethod Xvec:" << endl;
    ShowVec(X3, 3);

    cout << endl;

    double d1, d2, d3;
    d1 = d2 = d3 = 0.0;

    cout << string(58, '-') << endl;
    cout << " i  |   x   |  f(x) |  SPoints  |  Average  | LSquares   |" << endl;
    cout << string(58, '-') << endl;
    for (int i = 0; i < 6; i++) {
        d1 += abs(mathfunc(tvec[i], X1[0], X1[1],X1[2]) - Tvec[i]);
        d2 += abs(mathfunc(tvec[i], X2[0], X2[1],X2[2]) - Tvec[i]);
        d3 += abs(mathfunc(tvec[i], X3[0], X3[1],X3[2]) - Tvec[i]);

        cout << setw(3) << i + 1 << " | " << setw(5) << tvec[i] << " | " << setw(5) << Tvec[i] << " | ";
        cout << setw(9) << mathfunc(tvec[i], X1[0], X1[1], X1[2]) << " | ";
        cout << setw(9) << mathfunc(tvec[i], X2[0], X2[1], X2[2]) << " | ";
        cout << setw(10) << mathfunc(tvec[i],  X3[0], X3[1], X3[2]) << " | ";
        cout << endl;
    }

    d2 = d2 /(6. * abs(Tvec[5] - Tvec[1])) * 100;
    d3 = d3 /(6. * abs(Tvec[5] - Tvec[1])) * 100; 
    d1 = d1 /(6. * abs(Tvec[5] - Tvec[1])) * 100;                                                                                         
    d2 -= 10.0; d3 -= 10.0; d1 -= 10.0;

    cout << string(58, '-') << endl;
    cout << " Delta" << setw(25) << d1 << " " << setw(10) << d2 << " " << setw(12) << d3;
    cout << endl << endl;


    return 0;
}