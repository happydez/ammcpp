#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
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

bool CreateFile(string path) {
    ofstream file(path);

    if (!file.is_open()) {
        return false;
    }

    file.close();
    return true;
}

bool OpenFile(string path) {
    ifstream file(path);

    if (!file.is_open()) {
        return false;
    }

    file.close();
    return true;
}

bool AddToFile(string path, string data) {
    if (path == "") {
        return false;
    }

    fstream file(path);

    string line;
    string buffer;
    while (getline(file, line)) {
        buffer += line + "\n";
    }

    file.close();
    file.open(path, ios::out);

    file << data + "\n" + buffer;
    file.close();

    return true;
}

bool DeleteFromFile(string path, float points) {
    if (path == "") {
        return false;
    }

    fstream file(path);
    vector<SportCommand> cmds;

    while (!file.eof())
    {
        SportCommand cmd;
        file >> cmd.Name;
        file >> cmd.City;
        file >> cmd.Players;
        file >> cmd.Points;

        if (cmd.Points >= points) {
            cmds.push_back(cmd);
        }
    }
    file.close();

    file.open(path, ios::out);
    for (int i = 0; i < cmds.size(); i++) {
        file << cmds[i].String() << endl;
    }

    file.close();
    return true;
}

bool ShowFile(string path) {
    if (path == "") {
        return false;
    }

    fstream file(path);

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
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