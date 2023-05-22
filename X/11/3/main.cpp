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

int BinFileLines(string path) {
    if (path == "") {
        return -1;
    }

    fstream file(path, ios::binary | ios::in | ios::out);

    file.seekg(0, ios::end);
    int len = file.tellg();
    int size = sizeof(char);
    file.seekg(0);

    int k = 0;
    char tmp;
    for (int i = 0; i < len; i++) {
        file.read((char*)&tmp, sizeof(tmp));
        if (tmp == '\n') k++;
    }

    file.close();
    return k + 1;
}

bool CreateFile(string path) {
    ofstream file(path, ios::binary);

    if (!file.is_open()) {
        return false;
    }

    file.close();
    return true;
}

bool OpenFile(string path) {
    ifstream file(path, ios::binary);

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

    fstream file(path, ios::binary | ios::in | ios::out);

    file.seekg(0, ios::end);
    int len = file.tellg();
    file.seekg(0);

    char tmp;
    string cmd = "";
    string buffer = "";

    for (int i = 0; i < len; i++) {
        file.read((char*)&tmp, sizeof(tmp));
        buffer.push_back(tmp);
    }

    file.close();

    file.open(path, ios::binary | ios::in | ios::out);

    file.clear();
    file.seekp(0L, ios::end);
    file.seekg(0L, ios::beg);

    for (int i = 0; i < data.length(); i++) {
        file.write((char*)&data[i], sizeof(data[i]));
    }

    char nw = '\n';
    file.write((char*)&nw, sizeof(nw));

    for (int i = 0; i < buffer.length(); i++) {
        file.write((char*)&buffer[i], sizeof(buffer[i]));
    }

    file.close();

    return true;
}

bool DeleteFromFile(string path, float points) {
    if (path == "") {
        return false;
    }

    fstream file(path, ios::binary | ios::in | ios::out);

    file.seekg(0, ios::end);
    int len = file.tellg();
    file.seekg(0);

    char tmp;
    string cmd = "";
    string buffer = "";

    vector<SportCommand> cmds;

    for (int i = 0; i < len; i++) {
        file.read((char*)&tmp, sizeof(tmp));
        buffer.push_back(tmp);
        
        if (tmp == '\n') {
            cmds.push_back(StringToSportCommand(buffer));
            buffer = "";
        }
    }
    file.close();

    fstream f(path, ios::out);

    for (int i = 0; i < cmds.size(); i++) {
        if (cmds[i].Points >= points) {
            auto cs = cmds[i].String();
            for (int i = 0; i < cs.length(); i++) {
                f.write((char*)&cs[i], sizeof(cs[i]));
            }
            if (i != cmds.size() - 1) {
                char nw = '\n';
                f.write((char*)&nw, sizeof(nw));
            }
        }
    }
    f.close();

    return true;
}

bool ShowFile(string path) {
    if (path == "") {
        return false;
    }

    fstream file(path, ios::binary | ios::in | ios::out);

    file.seekg(0, ios::end);
    int len = file.tellg();
    int size = sizeof(char);
    file.seekg(0);

    char tmp;
    for (int i = 0; i < len; i++) {
        file.read((char*)&tmp, sizeof(tmp));
        cout << tmp;
    }

    cout << endl;

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