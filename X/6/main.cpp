#include "numerics.h"

std::string ToBaseN(int num, int base) 
{
    if ((base <= 1) || (base >= 17))
    {
        throw std::invalid_argument("base must be in range 1 <= base <= 16");
    }

    int ost;
    std::string res = "";
    std::string base16[6] = { "A", "B", "C", "D", "E", "F" };

    while (num != 0)
    {
        ost = num % base;

        if (ost >= 10)
        {
            res = base16[ost % 10] + res;
        }
        else
        {
            res = std::to_string(ost) + res;
        }

        num = (int)(num / base);
    }

    return res;
}

int main() {

    int to10 = ToBase10("1234", 5);
    std::string to3 = ToBaseN(to10, 3);

    std::cout << to10 << std::endl; // 194
    std::cout << to3 << std::endl; // 21012

    std::string to16 = ToBaseN(255, 16);
    std::cout << to16 << std::endl;

    return 0;
}