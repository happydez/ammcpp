#include <iostream>

using namespace std;

void ShowPerson(string firstname = "NoName", string lastname = "NoName", int age = 0)
{
    cout << "Name: " << firstname << endl;
    cout << "Surname: " << lastname << endl;
    cout << "Age: " << age << endl;
}

void line(char s = '-', int c = 32)
{
    cout << string(c, s) << endl;
}

int main()
{

    ShowPerson("Alexey", "Kaschenko", 18);
    line();

    ShowPerson();
    line();

    ShowPerson("Alexey");
    line();

    return 0;
}