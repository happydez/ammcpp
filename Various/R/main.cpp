#include <iostream>

using namespace std;

int FirstColumnIndexWithZero(int** a, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j][i] == 0)
            {
                return i;
            }
        }
    }

    return -1;
}

int SumEvenNegatives(int** a, int n, int m)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((a[i][j] % 2 == 0) && (a[i][j] < 0))
            {
                sum += a[i][j];
            }
        }
    }

    return sum;
}

int main()
{
    /*
        input:
        3 3
         1 -2  3
        -1 10  5
        -8  0 -8

        output:
        2 столбец
        -18 сумма
    */

    int n, m, **a;
    cin >> n >> m;

    a = new int*[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "First column with zero: " << FirstColumnIndexWithZero(a, n, m) + 1 << endl;
    cout << "Sum of even negatives nums: " << SumEvenNegatives(a, n, m) << endl;

    return 0;
}