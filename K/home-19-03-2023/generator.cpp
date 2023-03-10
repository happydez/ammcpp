#ifndef AMM
#include "lib/amm.h"
#endif

const int NAMES = 10;
const int SURNAMES = 10;

std::string amm::Generator::_m_names[NAMES]       = { "Alexey", "Vladislav", "Sergey", "Denis", "Stepan", "Ilya", "Nikita", "Roman", "Nikolay", "Gleb" };
std::string amm::Generator::_m_surnames[SURNAMES] = { "Ivanov", "Kuznetsov", "Petrov", "Morozov", "Volkov", "Komarov", "Lebedev", "Egorov", "Sergeev", "Andreev" };
std::string amm::Generator::_g_names[NAMES]       = { "Tatyana", "Maria", "Daria", "Viktoria", "Anastasia", "Galina", "Evgenia", "Olga", "Svetlana", "Karina" };
std::string amm::Generator::_g_surnames[SURNAMES] = { "Ivanova", "Kuznetsova", "Petrova", "Morozova", "Volkova", "Komarova", "Lebedeva", "Egorova", "Sergeeva", "Andreeva" };

const int MIN_RU   = 44;
const int MIN_MA   = 33;
const int MIN_PHY  = 36;
const int MIN_INF  = 48;
const int MIN_OBSH = 38;
const int MAX_MARK = 100;

inline int RandomInRang(int min, int max) {
    return rand() % (max - min + 1) + min;
}

amm::Marks amm::Generator::RandomMarks() {

    switch (RandomInRang(0, 2))
    {
    case 0:
        return Marks(RandomInRang(MIN_RU, MAX_MARK), RandomInRang(MIN_MA, MAX_MARK), RandomInRang(MIN_INF, MAX_MARK), 0, 0);
    case 1:
        return Marks(RandomInRang(MIN_RU, MAX_MARK), RandomInRang(MIN_MA, MAX_MARK), 0, RandomInRang(MIN_PHY, MAX_MARK), 0);
    case 2:
        return Marks(RandomInRang(MIN_RU, MAX_MARK), RandomInRang(MIN_MA, MAX_MARK), 0, 0, RandomInRang(MIN_OBSH, MAX_MARK));
    }

    return Marks();
}

amm::Bonus amm::Generator::RandomBonus() {
    return Bonus(RandomInRang(0, 5), RandomInRang(0, 5), RandomInRang(0, 5));
}

std::string amm::Generator::RandomManName() {
    return _m_names[RandomInRang(0, NAMES - 1)];
}

std::string amm::Generator::RandomManSurname() {
    return _m_surnames[RandomInRang(0, SURNAMES - 1)];
}

std::string amm::Generator::RandomGirlName() {
    return _m_names[RandomInRang(0, NAMES - 1)];
}

std::string amm::Generator::RandomGirlSurname() {
    return _m_surnames[RandomInRang(0, SURNAMES - 1)];
}

std::vector<amm::Student> amm::Generator::Generate(int amount) {
    if (amount <= 0) {
        return std::vector<amm::Student>(0);
    }

    std::vector<amm::Student> students;
    students.reserve(amount); // set capacity

    for (int i = 0; i < amount; i++) {
        if (RandomInRang(0, 1)) {
            students.push_back(Student(i + 1, RandomManName(), RandomManSurname(), RandomMarks(), RandomBonus()));
        } else {
            students.push_back(Student(i + 1, RandomGirlName(), RandomGirlSurname(), RandomMarks(), RandomBonus()));
        }
    }

    return students;
}