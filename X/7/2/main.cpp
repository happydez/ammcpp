#include <iostream>

using namespace std;

int ManyParams(int n, int params[])
{
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (~params[i] & 1)
        {
            c++;
        }
    }

    return c;
}

int main()
{

    cout << "#1 Result: " << ManyParams(10, new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << endl;
    cout << "#2 Result: " << ManyParams(8, new int[8]{2, 2, 2, 8, 10, 10, 10, 22}) << endl;

    return 0;
}