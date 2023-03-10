#ifndef AMM
#include "lib/amm.h"
#endif

amm::Student::Student(int id, std::string name, std::string surname, Marks marks, Bonus bonus) {
    this->_id       = id;
    this->_name     = name;
    this->_surname  = surname;
    this->_marks    = marks;
    this->_bonus    = bonus;
}