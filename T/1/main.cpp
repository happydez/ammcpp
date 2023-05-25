#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double MathFunc(double x, double t) {
    return 0.1 * x * x + 4 * t - 1;
}

typedef double (*mathfunc)(double, double);

double Eiler(double& x0, double& t0, double dt, mathfunc mf, int i) {
    double x = x0;
    double t = t0;

    if (i != 0) {
        do {
            x = x + dt * mf(x, t);
            t = t + dt;
        } while (t < t0 + dt * i);
    }

    return x;
}

double EilerRecursion(double& x0, double& t0, double dt, mathfunc mf, int i) {
    if (i == 0) {
        return x0;
    }

    double t = t0 + dt * (i - 1);
    double x = EilerRecursion(x0, t0, dt, mf, i - 1);

    return x + dt * mf(x, t);
}

double ModifyEiler(double& x0, double& t0, double dt, mathfunc mf, int i) {
    double x = x0;
    double t = t0;

    if (i != 0)
	{
		do
		{
			x = x + dt * mf(x + (dt/2) * mf(x, t), t + dt/2);
			t = t + dt;

		} while (t < (t0 + dt * i));
	}

	return x;
}


double ModifyEilerRecursion(double& x0, double& t0, double dt, mathfunc mf, int i)
{
	if (i == 0)
	{
		return x0;
	}
	else
	{
		double t = t0 + dt * (i - 1);
		double x = ModifyEilerRecursion(x0, t0, dt, mf, i - 1);

		return x + dt * mf(x + (dt / 2) * mf(x, t), t + dt / 2);
	}
}

double EilerKoshi(double& x0, double& t0, double dt, mathfunc mf, int i)
{
	double x = x0;
	double t = t0;

	if (i != 0)
	{
		do
		{
			x = x + (dt/2) * (mf(x, t) + mf(x + dt * mf(x, t), t + dt));
			t = t + dt;

		} while (t < (t0 + dt * i));
	}

	return x;
}


double EilerKoshiRecursion(double& x0, double& t0, double dt, mathfunc mf, int i)
{
	if (i == 0)
	{
		return x0;
	}
	else
	{
		double t = t0 + dt * (i - 1);
		double x = EilerKoshiRecursion(x0, t0, dt, mf, i - 1);

		return x + (dt / 2) * (mf(x, t) + mf(x + dt * mf(x, t), t + dt));
	}
}

double RyngeKytt(double& x0, double& t0, double dt, mathfunc mf, int i)
{
	double x = x0;
	double t = t0;
	double k1 = 0, k2 = 0, k3 = 0, k4 = 0;


	if (i != 0)
	{
		do
		{
			k1 = dt * mf(x, t);
			k2 = dt * mf(x + k1 / 2, t + dt / 2);
			k3 = dt * mf(x + k2 / 2, t + dt / 2);
			k4 = dt * mf(x + k3, t + dt);

			x = x + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
			t = t + dt;

		} while (t < (t0 + dt * i));
	}
	return x;
}

double RyngeKyttRecursion(double& x0, double& t0, double dt, mathfunc mf, int i) 
{
	double k1 = 0, k2 = 0, k3 = 0, k4 = 0;

	if (i == 0)
	{
		return x0;
	}
	else
	{
		double t = t0 + dt * (i - 1);
		double x = RyngeKyttRecursion(x0, t0, dt, mf, i - 1);

		k1 = dt * mf(x, t);
		k2 = dt * mf(x + k1 / 2, t + dt / 2);
		k3 = dt * mf(x + k2 / 2, t + dt / 2);
		k4 = dt * mf(x + k3, t + dt);

		return x + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
	}
}

int main() 
{
	setlocale(LC_ALL, "ru");

	double t0 = 0.0, tk = 1.0;
	double x0 = 4.0, n = 0;

	for (double dt = 0.1; dt >= 0.001; dt *= 0.1) 
	{
        cout << "\n dt = " << dt << endl;

		cout << " " << setw(3) << left << "i" << " " << setw(10) << "| dt" << " " << setw(13) 
            << "| Eiler"       << " " << setw(21) <<  "| EilerRecursion"       << setw(16)
			<< "| ModifyEiler" << " " << setw(25) <<  "| ModifyEilerRecursion" << setw(14)
			<< "| EilerKoshi " << " " << setw(24) <<  "| EilerKoshiRecursion"  << setw(12)
			<< "| RyngeKytt "  << " " << setw(15) << " | RyngeKyttRecursion"   << endl;

        cout << string(166, '-') << endl;

		for (int i = 0; i < 3 + (tk - t0)/dt/100; i++) 
		{
			cout << " " << setw(3) << left << i << " | " << setw(8) << (t0 + i * dt)
				<< " | " << setw(11) << Eiler(x0, t0, dt, MathFunc, i)
				<< " | " << setw(18) << EilerRecursion(x0, t0, dt, MathFunc, i) 

				<< " | " << setw(14) << ModifyEiler(x0, t0, dt, MathFunc, i)
				<< " | " << setw(22) << ModifyEilerRecursion(x0, t0, dt, MathFunc, i) 

				<< " | " << setw(12) << EilerKoshi(x0, t0, dt, MathFunc, i) 
				<< " | " << setw(21) << EilerKoshiRecursion(x0, t0, dt, MathFunc, i) 

				<< " | " << setw(11) << RyngeKytt(x0, t0, dt, MathFunc, i)
				<< " | " << setw(14) << RyngeKyttRecursion(x0, t0, dt, MathFunc, i) << endl;
		}
		cout << string(166, '-') << endl;
	}

	return 0;
}