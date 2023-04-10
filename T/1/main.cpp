#include <iostream>
#include <ctime>

using namespace std;

int str_equals(int** a, const int m, const int n)
{
    int i, j, count, line = -1, maxcount = 0;
    for (i = 0; i < m; i++)
    {
        count = 0;
        for (j = 0; j <= n - 2; j++)
        {
            if (*(*(a + i) + j) == *(*(a + i) + j + 1))
            {
                count++;
            }
            else
            {
                if (count > maxcount)
                {
                    maxcount = count;
                    line = i;
                }
                count = 0;
            }
        }
        if (count > maxcount)
        {
            maxcount = count;
            line = i;
        }
    }
    return line;
}

int main() {
    
    return 0;
}