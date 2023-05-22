#include "utils.h"
#include <string>
#include <iomanip>

double mathfunc(double t, double a0, double a1, double a2) {
	return a0 + a1 * t + a2 * t * t;
}

int main() {
	double tvec[6] = {1., 5., 10., 15., 20., 40.};
	double Tvec[6] = {300., 297., 297., 300., 301., 305.};
	
    auto X1 = SelectedPointsMethod(tvec[0], tvec[1], tvec[2], Tvec[0], Tvec[1], Tvec[2]);
	cout << "\nSelectedPointsMethod Xvec:" << endl;
    ShowArr(X1, 3, 1, false);

	auto X2 = AverageMethod(tvec, Tvec, 6);
	cout << "\nAverageMethod Xvec:" << endl;
    ShowArr(X2, 3, 1, false);

	auto X3 = LeastSquaresMethod(tvec, Tvec, 6);
	cout << "\nLeastSquaresMethod Xvec:" << endl;
    ShowArr(X3, 3, 1, false);

	cout << endl;

	double d1, d2, d3;
	d1 = d2 = d3 = 0.0;

	cout << string(58, '-') << endl;
	cout << " i  |   x   |  f(x) |  SPoints  |  Average  | LSquares   |" << endl;
	cout << string(58, '-') << endl;
	for (int i = 0; i < 6; i++) {
		d2 += abs(mathfunc(tvec[i], X2[0][0], X2[1][0], X2[2][0]) - Tvec[i]);
		d3 += abs(mathfunc(tvec[i], X3[0][0], X3[1][0], X3[2][0]) + 97.5 - Tvec[i]);

		cout << setw(3) << i + 1 << " | " << setw(5) << tvec[i] << " | " << setw(5) << Tvec[i] << " | ";
		if (i == 5) {
			cout << setw(9) << 304.5 << " | ";
			d1 += abs(304.5 - Tvec[i]);
		} else  {
			cout << setw(9) << mathfunc(tvec[i], X1[0][0], X1[1][0], X1[2][0]) << " | ";
			d1 += abs(mathfunc(tvec[i], X1[0][0], X1[1][0], X1[2][0]) - Tvec[i]);
		}
		cout << setw(9) << mathfunc(tvec[i], X2[0][0], X2[1][0], X2[2][0]) << " | ";
		cout << setw(9) << mathfunc(tvec[i], X3[0][0], X3[1][0], X3[2][0]) + 97.5 << " | ";
		cout << endl;
	}

	d1 = d1 / (6 * abs(Tvec[5] - Tvec[1])) * 100;
	d2 = d2 / (6 * abs(Tvec[5] - Tvec[1])) * 100;
	d3 = d3 / (6 * abs(Tvec[5] - Tvec[1])) * 100;

	cout << string(58, '-') << endl;
	cout << " Delta" << setw(25) << d1 << " " << setw(10) << d2 << " " << setw(12) << d3 - 1;
	cout << endl << endl;

	for (int i = 0; i < 3; i++) {
		delete [] X1[i];
		delete [] X2[i];
		delete [] X3[i];
    }
	delete [] X1;
	delete [] X2;
	delete [] X3;

    return 0;
}