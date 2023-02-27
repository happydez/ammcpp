#include <iostream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

enum CORRECT {NO, YES};

struct Problem
{
    string prbl;
    int answ;
};

struct Stat
{
    int allProblems;
    int validAnswers;
};

void line(char ch = '-', int c = 32) {
    for (int i = 0; i < c; i++) {
        cout << ch;
    }
    cout << endl;
}

int problemParse(string prbl) {
    if (!prbl.length()) {
        return -1;
    }

    int answ = 1;
    int last, next;
    last = next = 0;

    while(1) {
        next = prbl.find(" * ", next);
        if (next == -1) {
            answ *= atoi(prbl.substr(last, prbl.length() - last).c_str());
            break;
        }

        answ *= atoi(prbl.substr(last, next).c_str());
        next += 3;
        last = next;
    }

    return answ;
}

int main() {

    Problem problems[] =
    {
        Problem{"5 * 2 * 10", 100},
        Problem{"5 * 25 * 5", 625},
        Problem{"2 * 2 * 4", 16},
        Problem{"2 * 10 * 6", 120},
        Problem{"111 * 2 * 4", 888},
        Problem{"2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2", 1024}
    };
    int len = sizeof(problems) / sizeof(Problem);
    
    // testing problem parser
    // cout << problemParse(problems[0].prbl) << endl;

    random_device rd;
    mt19937 g(rd());
    shuffle(begin(problems), end(problems), g);

    Stat stat = {len, 0};
    CORRECT correct = NO;

    cout << "Try to slove all problmes" << endl;
    line();

    int inp;
    for (int i = 0; i < len; i++) {
        cout << i + 1 << ". " << problems[i].prbl << " = ";
        cin >> inp;

        if (inp == problems[i].answ) {
            correct = YES;
        } else {
            correct = NO;
        }

        if (correct == YES) {
            stat.validAnswers += 1;
        }
    }

    line();
    cout.precision(3);
    cout << "All problems: " << stat.allProblems << endl;
    cout << "Valid answers: " << stat.validAnswers << endl;
    cout << "Invalid answers: " << stat.allProblems - stat.validAnswers << endl;
    cout << "Valid answers (%): " << (float)(stat.validAnswers * 100) / (float)stat.allProblems << "%" << endl;
    cout << "Your mark: " 
         << (float)(stat.validAnswers * 5 + (stat.allProblems - stat.validAnswers) * 2) / (float)(stat.allProblems) 
         << endl;

    return 0;
}