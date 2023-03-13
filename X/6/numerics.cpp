#include "numerics.h"

// N ----> 10
int ToBase10(std::string num, int base)
{
    if ((base <= 1) || (base >= 17))
    {
        throw std::invalid_argument("base must be in range 1 <= base <= 16");
    }
    
    int res = 0;
    int index = num.length() - 1;

    for (int i = 0; i < num.length(); i++)
    {
        res += (int)(num[i] - '0') * std::pow(base, index);
        index--;
    }

    return res;
}