#include "nums.h"

std::string to_n(int num, int base) 
{
    int k;
    std::string res = "";
    std::string nums_16[6] = { "A", "B", "C", "D", "E", "F" };

    while (num != 0)
    {
        k = num % base;

        if (k >= 10)
        {
            res = nums_16[k % 10] + res;
        }
        else
        {
            res = std::to_string(k) + res;
        }

        num = (int)(num / base);
    }

    return res;
}