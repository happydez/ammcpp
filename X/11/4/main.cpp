#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

struct SportCommand {
    string Name;
    string City;
    int Players;
    float Points;

    SportCommand()
    {
        this->Name = "";
        this->City = "";
        this->Players = 0;
        this->Points = 0.;
    }

    SportCommand(string name, string city, int players, float points)
    {
        this->Name = name;
        this->City = city;
        this->Players = players;
        this->Points = points;
    }

    string String()
    {
        return this->Name + " " + this->City + " " + to_string(this->Players) + " " + to_string(this->Points);
    }
};

SportCommand StringToSportCommand(string data) {
    int next = 0;

    string name = data.substr(next, data.find_first_of(' ', next));
    next = data.find_first_of(' ', next) + 1;

    string city = data.substr(next, data.find_first_of(' ', next) - next);
    next = data.find_first_of(' ', next) + 1;

    int players = stoi(data.substr(next, data.find_first_of(' ', next) - next));
    next = data.find_first_of(' ', next) + 1;

    float points = stof(data.substr(next));

    return SportCommand(name, city, players, points);
}

enum Menu {Create, Open, Delete, Add, Show, Exit};

Menu ShowMenu() {
    cout << endl;
    cout << "1. Create" << endl;
    cout << "2. Open" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Add" << endl;
    cout << "5. Show" << endl;
    cout << "Press other num to exit";

    int n;
    cout << ">> "; cin >> n;

    switch (n)
    {
    case 1: return Create;
    case 2: return Open;
    case 3: return Delete;
    case 4: return Add;
    case 5: return Show;
    default: return Exit;
    }
}

int BinFileSize(FILE* fstream) {
    if (fstream == NULL) return -1;

    int n = 0;
    char temp;
    while (!feof(fstream)) {
        fscanf(fstream, "%c", &temp);
        n++;
    }

    return n - 1;
}

bool CreateFile(string path) {
    FILE* f = fopen(path.c_str(), "ab");

    if (f == NULL) {
        return false;
    }
    fclose(f);

    return true;
}

bool OpenFile(string path) {
    FILE* f = fopen(path.c_str(), "rb");

    if (f == NULL) {
        return false;
    }
    fclose(f);

    return true;
}

bool ShowFile(string path) {
    if (path == "") {
        return false;
    }

    int blen = BinFileSize(fopen(path.c_str(), "rb"));

    FILE* f = fopen(path.c_str(), "rb");

    if (f == NULL) {
        return false;
    }

    if (blen == 0) {
        return true;
    }

    char tmp;
    for (int i = 0; i < blen; i++) {
        cout << (char)fgetc(f);
    }

    cout << endl;

    fclose(f);
    return true;
}

bool AddToFile(string path, string data) {
    if (path == "") {
        return false;
    }

    int blen = BinFileSize(fopen(path.c_str(), "rb"));

    FILE* f = fopen(path.c_str(), "rb");

    if (f == NULL) {
        return false;
    }

    string buffer = "";
    if (blen > 0) {
        char str[512];

        while (!feof(f)) {
            fgets(str, 512, f);
            buffer += string(str);
        }

        buffer = data + "\n" + buffer;
    } else {
        buffer = data;
    }

    fclose(f);

    f = fopen(path.c_str(), "wb");

    if (f == NULL) {
        return false;
    }

    cout << "buffer = " << buffer << endl;

    fputs(buffer.c_str(), f);
    fclose(f);

    return true;
}

bool DeleteFromFile(string path, float points) {
    if (path == "") {
        return false;
    }

    int blen = BinFileSize(fopen(path.c_str(), "rb"));

    FILE* f = fopen(path.c_str(), "rb");

    if (f == NULL) {
        return false;
    }

    if (blen == 0) {
        fclose(f);
        return true;
    }

    char str[256];
    vector<SportCommand> cmds;
    while (!feof(f)) {
        fgets(str, 256, f);
        cmds.push_back(StringToSportCommand(string(str)));
    }

    string buffer;
    for (int i = 0; i < cmds.size(); i++) {
        if (cmds[i].Points >= points) {
            if (i == cmds.size() - 1) {
                buffer += cmds[i].String();
            } else {
                buffer += cmds[i].String();
            }
        }
    }
    fclose(f);

    f = fopen(path.c_str(), "wb");

    if (f == NULL) {
        return false;
    }

    fputs(buffer.c_str(), f);
    fclose(f);

    return true;
}

int main() {

    Menu cmd = Exit;
    string openPath = "";

    do {
        cmd = ShowMenu();

        switch (cmd)
        {
        case Create: {
            system("cls");

            string path;
            cout << "input file name >> "; cin >> path;

            if (CreateFile(path)) {
                cout << "OK!" << endl;
            } else {
                cout << "Error!" << endl;
                return -1;
            }

            break;
        }
        case Open: {
            system("cls");

            string path;
            cout << "input file name to open >> "; cin >> path;

            if (OpenFile(path)) {
                cout << "OK!" << endl;
                openPath = path;
            } else {
                cout << "Error!" << endl;
                return -1;
            }

            break;
        }
        case Add: {
            system("cls");

            int n;
            cout << "Commands to add? >> "; cin >> n;
            if (n <= 0) {
                cout << "invalid n" << endl;
                return -1;
            }

            for (int i = 0; i < n; i++) {
                system("cls");
                SportCommand sc;
                cout << "Name >> "; cin >> sc.Name;
                cout << "City >> "; cin >> sc.City;
                cout << "Players >> "; cin >> sc.Players;
                cout << "Points >> "; cin >> sc.Points;
                if (!AddToFile(openPath, sc.String())) {
                    cout << "file doesn't open" << endl;
                    return -1;
                }
            }
            system("cls");

            break;
        }
        case Delete: {
            system("cls");

            float points;
            cout << "input filter point value >> "; cin >> points;

            if (points < 0.) {
                cout << "invalid point value" << endl;
                return -1;
            }

            if (!DeleteFromFile(openPath, points)) {
                cout << "file doesn't open" << endl;
                return -1;
            }

            break;
        }
        case Show: {
            system("cls");

            if (!ShowFile(openPath)) {
                cout << "file doesn't open" << endl;
                return -1;
            }

            break;
        }
        default:
            break;
        }

    } while (cmd != Exit);

    return 0;
}