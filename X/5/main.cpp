#include <iostream>

char* reverse(const char s[], int size)
{
    int q = 0;
    char* res = new char[size];
    for (int i = size - 1; i != -1; i--)
    {
        res[q++] = s[i];
    }

    return res;
}

int countWords(const char* s, int size)
{
    int words = 0;
    bool isfirst = true;

    for (int i = 0; i < size; i++)
    {
        if ((s[i] != ' ') && (s[i] != '\0'))
        {
            if (i == (size - 1))
            {
                words++;
            }
            else if ((s[i + 1] == ' ') && (i != (size - 1)))
            {
                words++;
            }
        }
    }

    return words;
}

void show(std::string msg, const char s[], int size)
{
    std::cout << msg << " ";
    for (int i = 0; i < size; i++)
    {
        std::cout << s[i];
    }
    std::cout << "\n";
}


int main()
{
    // Golang C# .Net Hello World
    //         Golang     C# C++         C Hello World        /
    char t[] = "Golang C# .Net Hello World";
    int size = sizeof(t)/sizeof(char);

    auto reversed = reverse(t, size);
    show("Reversed:", reversed, size);

    int words = countWords(reversed, size);
    std::cout << "Total words: " << words << std::endl;

    delete [] reversed;

    return 0;
}