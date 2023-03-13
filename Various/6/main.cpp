#include "nums.h"

using namespace std;

int to_10(string num, int base)
{
    int res = 0;
    int id = num.length() - 1;

    for (int i = 0; i < num.length(); i++)
    {
        res += (int)(num[i] - '0') * pow(base, index);
        id--;
    }

    return res;
}

int main()
{
    int num16 = 0x1AFF;
    cout << "In 16 base: " << num16 << endl;

    int num10 = to_10("1AFF", 16);
    cout << "In 10 base: " << num10 << endl;

    int num8 = to_n(num10, 8);
    cout << "In 8 base: " << num8 << endl;

    return 0;
}