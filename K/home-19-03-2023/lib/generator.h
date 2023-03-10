#include <vector>

#ifndef AMM
#include "amm.h"
#endif

namespace amm {
    class Generator
    {
    private:
        static std::string _m_names[];
        static std::string _m_surnames[];
        static std::string _g_names[];
        static std::string _g_surnames[];

    public:
        static std::vector<Student> Generate(int);

        static Marks RandomMarks();
        static Bonus RandomBonus();

        static std::string RandomManName();
        static std::string RandomManSurname();
        static std::string RandomGirlName();
        static std::string RandomGirlSurname();
    };
}