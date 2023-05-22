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
    FILE* f = fopen(path.c_str(), "a");

    if (f == NULL) {
        return false;
    }
    fclose(f);

    return true;
}

bool OpenFile(string path) {
    FILE* f = fopen(path.c_str(), "r");

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

    FILE* f = fopen(path.c_str(), "r");

    if (f == NULL) {
        return false;
    }

    if (BinFileSize(f) == 0) {
        return true;
    }

    char temp;
    while (!feof(f)) {
        fscanf(f, "%c", &temp);
        cout << temp;
    }
    cout << endl;

    fclose(f);
    return true;
}

bool AddToFile(string path, string data) {
    if (path == "") {
        return false;
    }

    FILE* f = fopen(path.c_str(), "r");

    if (f == NULL) {
        return false;
    }

    string buffer = "";
    if (BinFileSize(f) > 0) {
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

    f = fopen(path.c_str(), "w+");

    if (f == NULL) {
        return false;
    }

    fputs(buffer.c_str(), f);
    fclose(f);

    return true;
}

bool DeleteFromFile(string path, float points) {
    if (path == "") {
        return false;
    }

    FILE* f = fopen(path.c_str(), "r+");

    if (f == NULL) {
        return false;
    }

    if (BinFileSize(f) == 0) {
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
    for (auto cmd : cmds) {
        if (cmd.Points >= points) {
            buffer += cmd.String() + "\n";
        }
    }
    fclose(f);

    f = fopen(path.c_str(), "w+");

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
            system("clear");

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
            system("clear");

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
            system("clear");

            int n;
            cout << "Commands to add? >> "; cin >> n;
            if (n <= 0) {
                cout << "invalid n" << endl;
                return -1;
            }

            for (int i = 0; i < n; i++) {
                system("clear");
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
            system("clear");

            break;
        }
        case Delete: {
            system("clear");

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
            system("clear");

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