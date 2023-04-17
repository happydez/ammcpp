#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int sum(const int* mas, const int n);
void print(const int* mas, const int n);
int const n = 5;

int main() {

    int marks[n] = {3, 4, 5, 4, 4};
    cout << "sum: " << sum(marks, n) << endl;
    print(marks, n);

    return 0;
}

int sum(const int* mas, const int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += mas[i];
    }
    return s;
}

void print(const int* mas, const int n) {
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
    cout << "\n";
}
