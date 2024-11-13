#include <iostream>
using namespace std;

void removeX(char *str, char remove_char, int &length, int index)
{
    if (str[index] == '\0')
    {
        return;
    }

    if (str[index] == remove_char)
    {
        for (int i = index; i < length; i++)
        {
            str[i] = str[i + 1];
        }
        length--;

        removeX(str, remove_char, length, index);
    }
    else
    {
        removeX(str, remove_char, length, index + 1);
    }
}

int getLength(char *str)
{

    int length = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }

    return length;
}

int main()
{
    char str[100];
    char remove_char;
    cout << "Enter the string : ";
    cin >> str;

    cout << "Enter the character to remove : ";
    cin >> remove_char;

    int length = getLength(str);

    removeX(str, remove_char, length, 0);

    cout << "Answer = " << str;
}