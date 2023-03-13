#include "nums.h"

using namespace std;

int Is_base_16(char num)
{
    if (num == 'A') return 10;
    if (num == 'B') return 11;
    if (num == 'C') return 12;
    if (num == 'D') return 13;
    if (num == 'E') return 14;
    if (num == 'F') return 15;

    return -1;
}

int to_10(string num, int base)
{
    int t;
    int res = 0;
    int id = num.length() - 1;

    for (int i = 0; i < num.length(); i++)
    {
        if ((t = Is_base_16(num[i])) != -1)
        {
            res += t * pow(base, id);
        }
        else
        {
            res += (int)(num[i] - '0') * pow(base, id);
        }
        id--;
    }

    return res;
}

int main()
{
    std::string num16 = "1AFF";
    cout << "In 16 base: " << num16 << endl;

    int num10 = to_10(num16, 16);
    cout << "In 10 base: " << num10 << endl;

    std::string num8 = to_n(num10, 8);
    cout << "In 8 base: " << num8 << endl;

    return 0;
}