#ifndef AMM
#include "lib/amm.h"
#endif

#include <ctime>

using namespace amm;

int main() {

    #ifdef GENERATOR
    std::srand(time(0));
    #endif

    #ifdef DEBUG
    for (auto s : Generator::Generate(5)) {
        s.String();
    }
    #endif

    return 0;
}
