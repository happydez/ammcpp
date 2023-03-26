#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Является ли символ 16-м числом A, B, C, D, E, F
int Is_base_16(char num);

// Из 10 в N систему счисления
string to_n(int num, int base);

// Из N в 10 систему счисления
int to_10(string num, int base);

int main()
{
    string num16 = "1AFF";
    cout << "In 16 base: " << num16 << endl;

    int num10 = to_10(num16, 16);
    cout << "In 10 base: " << num10 << endl;

    string num8 = to_n(num10, 8);
    cout << "In 8 base: " << num8 << endl;

    return 0;
}

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

string to_n(int num, int base) 
{
    int k;
    string res = "";
    string nums_16[6] = { "A", "B", "C", "D", "E", "F" };

    while (num != 0)
    {
        k = num % base;

        if (k >= 10)
        {
            res = nums_16[k % 10] + res;
        }
        else
        {
            res = to_string(k) + res;
        }

        num = (int)(num / base);
    }

    return res;
}