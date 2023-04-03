#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int IsBase16(char num);
int ToBase10(string num, int base);
string ToBaseN(int num, int base) ;


int main() {

    // A^2 + 3*B + B^2
    // A in 8 base
    // B in 3 base
    // Answer in 7 base

    // input: 57 122
    // output: 10301 / 2549

    string A, B;
    cout << "Enter A >> "; cin >> A;
    cout << "Enter B >> "; cin >> B;

    int result = ToBase10(A, 8) * ToBase10(A, 8) + ToBase10(B, 3) * 3 + ToBase10(B, 3) * ToBase10(B, 3);
    cout << "Result in 7 base = " << ToBaseN(result, 7) << endl;
    cout << "Result in 10 base = " << result << endl;

    return 0;
}

int IsBase16(char num)
{
    if (num == 'A') return 10;
    if (num == 'B') return 11;
    if (num == 'C') return 12;
    if (num == 'D') return 13;
    if (num == 'E') return 14;
    if (num == 'F') return 15;

    return -1;
}

int ToBase10(string num, int base)
{
    int t;
    int res = 0;
    int id = num.length() - 1;

    for (int i = 0; i < num.length(); i++)
    {
        if ((t = IsBase16(num[i])) != -1)
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

string ToBaseN(int num, int base) 
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