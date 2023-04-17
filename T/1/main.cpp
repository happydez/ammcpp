#include <iostream>
#include <io.h>
#include <fcntl.h>

using namespace std;

int main() {

    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << L"Hello, ❤\n";

    return 0;
}

