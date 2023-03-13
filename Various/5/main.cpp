#include <iostream>

using namespace std;

bool is_num(char n)
{
    return ('0' <= n) && (n <= '9');
}

void change_numbers(char* str, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (is_num(str[i]))
        {
            str[i] = ' ';
        }
    }
}

int get_words(const char str[], int size)
{
    int w = 0;

    for (int i = 0; i < size; i++)
    {
        if (str[i] != '\0')
        {
            if (str[i] != ' ')
            {
                if (i == size - 1)
                {
                    w++;
                }
                else if ((str[i + 1] == ' ') && (i != (size - 1)))
                {
                    w++;
                }
            }
        }
    }

    return w;
}

void show(char str[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << str[i];
    }
    cout << endl;
}

int main()
{
    char str[] = "He11lo w12orl 1231";
    int size = sizeof(str) / sizeof(char);

    cout << "Current string: ";
    show(str, size);

    change_numbers(str, size);

    cout << "After change: ";
    show(str, size);

    cout << "Total words: " << get_words(str, size) << endl;

    return 0;
}

// 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