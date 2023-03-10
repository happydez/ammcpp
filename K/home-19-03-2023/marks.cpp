#ifndef AMM
#include "lib/amm.h"
#endif

// BONUS
amm::Bonus::Bonus() {
    this->_attestat = 0;
    this->_gto      = 0;
    this->_other    = 0;
}

amm::Bonus::Bonus(int att, int gto, int oth) {
    this->_attestat = att >= 0 ? att : 0;
    this->_gto      = gto >= 0 ? gto : 0;
    this->_other    = oth >= 0 ? oth : 0; 
}

int amm::Bonus::GetAttestat() {
    return this->_attestat;
}

int amm::Bonus::GetGto() {
    return this->_gto;
}

int amm::Bonus::GetOther() {
    return this->_other;
}

int amm::Bonus::All() {
    return this->GetAttestat() + this->GetGto() + this->GetOther();
}

// MARKS
amm::Marks::Marks() {
    this->_russian      = 0;
    this->_math         = 0;
    this->_informatics  = 0;
    this->_physics      = 0;
    this->_obsh         = 0;
}

amm::Marks::Marks(int ru, int ma, int inf, int phy, int obsh) {
    this->_russian      = ru;
    this->_math         = ma;
    this->_informatics  = inf;
    this->_physics      = phy;
    this->_obsh         = obsh;

    _ok = IsValidMark(_russian) && IsValidMark(_math) && IsValidMark(_physics) && IsValidMark(_informatics) && IsValidMark(_obsh);
}

int amm::Marks::GetRussian() {
    return this->_russian;
}

int amm::Marks::GetMath() {
    return this->_math;
}

int amm::Marks::GetPhysics() {
    return this->_physics;
}

int amm::Marks::GetInformatics() {
    return this->_informatics;
}

int amm::Marks::GetObsh() {
    return this->_obsh;
}

bool amm::Marks::IsValid() {
    return this->_ok;
}

bool amm::Marks::IsValidMark(int mark) {
    return (0 <= mark) && (mark <= 100);
}