#include <iostream>
using namespace std;

void replaceWithCharacter(char *str, char toreplaceChar, char withReplaceChar)
{
    if (*str == '\0')
    {
        return;
    }

    if (*str != toreplaceChar)
    {
        replaceWithCharacter(str + 1, toreplaceChar, withReplaceChar);
    }
    else
    {
        *str = withReplaceChar;
        replaceWithCharacter(str + 1, toreplaceChar, withReplaceChar);
    }
}

int main()
{
    char str[100];
    cout << "Enter the string : ";
    cin >> str;

    char toreplaceChar;
    cout << "Enter the character to replace : ";
    cin >> toreplaceChar;

    char withReplaceChar;
    cout << "Enter the character with replace : ";
    cin >> withReplaceChar;

    replaceWithCharacter(str, toreplaceChar, withReplaceChar);

    cout << "Result = " << str;
}