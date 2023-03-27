#include <iostream>

using namespace std;

template <class TValue>
TValue ArrayAvg(TValue* arr, int n);

int main() {

    int* nums = new int[9]{-1, 0, -2, 0, -3, 0, -4, 0, -5};

    cout << "Result: " << ArrayAvg<int>(nums, 9) << endl;

    return 0;
}

template <class TValue>
TValue ArrayAvg(TValue* arr, int n) {
    int c = 0;
    TValue avg = 0;

    for (int i = 0; i < n; i++) {
        if (~i & 1) {
            if (arr[i] < 0) {
                c++;
                avg = avg + arr[i];
            }
        }
    }

    if (c == 0) return 0;

    return (TValue)(avg / c);
}
