#include <iostream>
#include <ctype.h>
#include <ctime>
#include <string>
using namespace std;

bool isNumber(const string&, int&);
void cmdInfo();
double* allocateArrayMemory(int);
void initArray(double*, int);
void showArray(double*, int);
void deleteArrayMemory(double*);

enum State {
    UNDEFINED,
    ALLOCATED, 
    INITIALIZED,
    DELETED,
};

void lastCMD(State);

int main() {
    srand(time(0));

    int n;
    string num;
    bool f = true;
    cout << "Enter array size: ";
    do {
        getline(cin, num);
        if (isNumber(num, n) && n > 0) {
            f = false;
        } else {
            cout << "invalid array size. try again." << endl;
        }
    } while(f);
    
    int cmd;
    double *a = nullptr;
    cmdInfo();
    State state = UNDEFINED;
    do {
        cin >> cmd;
        switch (cmd)
        {
        case 1:
            if ((state == UNDEFINED) || (state == DELETED)) {
                a = allocateArrayMemory(n);
                state = ALLOCATED;
            } else {
                cout << "array is already defined" << endl;
            }
            break;
        case 2:
            if ((state == UNDEFINED) || (state == DELETED)) {
                cout << "allocate the memory first" << endl;
            } else {
                initArray(a, n);
                state = INITIALIZED;
            }
            break;
        case 3:
            if (state != INITIALIZED) {
                cout << "your array is empty or deleted" << endl;
            } else {
                showArray(a, n);
                state = INITIALIZED;
            }
            break;
        case 4:
            if ((state == DELETED) || (state == UNDEFINED)) {
                cout << "array already deleted or undefined" << endl;
            } else {
                deleteArrayMemory(a);
                state = DELETED;
            }
            break;
        case 5:
            lastCMD(state);
            break;
        case 6:
            if ((state != DELETED) && (state != UNDEFINED)) {
                deleteArrayMemory(a);
            }
            cout << "exit" << endl;
            return 0;
        default:
            f = !f;
            cout << "invalid cmd. try again" << endl;
            break;
        }
    } while(!f);

    return 0;
}

bool isNumber(const string& s, int& out) {
    int value;
    int result = sscanf(s.c_str(), "%d", &value);
    out = value;
    return (result != EOF && result != 0);
}

void cmdInfo() {
    cout << "1. Allocate memory for the array\n";
    cout << "2. Initializing an array with random numbers\n";
    cout << "3. Show the array in the console\n";
    cout << "4. Delete array\n";
    cout << "5. Last command used\n";
    cout << "6. Exit\n";
}

// 1
double* allocateArrayMemory(int n) {
    return new double[n];
}

// 2
void initArray(double* a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10 + 1;
    }
}

// 3
void showArray(double* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// 4
void deleteArrayMemory(double* a) {
    delete [] a;
}

void lastCMD(State state) {
    switch (state)
    {
    case UNDEFINED:
        cout << "you have not used any of the commands" << endl;
        break;
    case ALLOCATED:
        cout << "1 - allocated" << endl;
        break;
    case INITIALIZED:
        cout << "2 - initialized" << endl;
        break;
    case DELETED:
        cout << "4 - deleted" << endl;
        break;
    default:
        cout << "3 - showed" << endl;
        break;
    }
}