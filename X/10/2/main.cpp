#include "utils.h"

void Chosen(const float w[],const float u[],float *res) {
	float** matr = new float* [2];
	for (int i = 0; i < 2; i++) {
		matr[i] = new float[2];
	}
	float quv[2];
	for (int i = 0; i < 2; i++) {
		quv[i] = u[i] * 6 * w[i];
	}
	matr[0][0] = 6 * w[0];
	matr[1][0] = 6 * w[1];
	matr[0][1] = d;
	matr[1][1] = d;
	Cramer(matr, quv, res);
	//cout << res[0] << " " << res[1] << endl;;
	
}

void Mid(const float w[],const float u[], float *res) {
	float** matr = new float* [2];
	for (int i = 0; i < 2; i++) {
		matr[i] = new float[2];
	}
	matr[0][0] = 3;
	matr[1][0] = 3;
	matr[0][1] = matr[1][1] = 0;
	float quv[2];
	quv[0] = quv[1] = 0;
	for (int i = 0; i < 3; i++) {
		matr[0][1] += d / (6 * w[i]);
		matr[1][1] += d / (6 * w[3+i]);
		quv[0] += u[i]; //cout << " " << u[i];
		quv[1] += u[3 + i]; 
		//cout << endl;
	}
	//cout << quv[0] <<" " << quv[1] << endl;
	//ShowMatr(matr, 2, 2);
	Cramer(matr, quv, res);
}

void Quad(const float w[], const float u[], float* res) {
	float** matr = new float* [2];
	for (int i = 0; i < 2; i++) {
		matr[i] = new float[2];
	}
	float quv[2];
	quv[0] = quv[1] = 0;
	matr[0][0] = matr[1][0] = matr[0][1] = matr[1][1] = 0;
	for (int i = 0; i < 7; i++) {
		matr[0][0] ++;
		matr[0][1] += d / (6 * w[i]);
		matr[1][0] += d / (6 * w[i]);
		matr[1][1] += pow(d / (6 * w[i]), 2);
		quv[0] += u[i];
		quv[1] += u[i] * d / (6 * w[i]);
	}
	Cramer(matr, quv, res);
}

int main() {

    auto m = new double*[3];
    for (int i = 0; i < 3; i++) {
        m[i] = new double[3];
        for (int j = 0; j < 3; j++) {
            cin >> m[i][j];
        }
    }

    // 3 2 -4
    // 2 -3 1
    // -1 5 -3

    int n = 3;
    InverseMatrix(m, n, n);
    ShowArr(m, n, n);

    for (int i = 0; i < 3; i++) {
        delete [] m[i];
    }
    delete [] m;

    return 0;
}