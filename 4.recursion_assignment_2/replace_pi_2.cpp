#include <iostream>
using namespace std;

void removePI(char *str, int index, int &length)
{
    if (str[index] == '\0' || str[index + 1] == '\0')
    {
        return;
    }

    if (str[index] == 'p' && str[index + 1] == 'i')
    {
        for (int i = length; i >= index + 2; i--)
        {
            str[i + 2] = str[i];
        }

        str[index] = '3';
        str[index + 1] = '.';
        str[index + 2] = '1';
        str[index + 3] = '4';

        length += 2;

        removePI(str, index + 4, length);
    }
    else
    {
        removePI(str, index + 1, length);
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
    cout << "Enter the string : ";
    cin >> str;

    int length = getLength(str);

    removePI(str, 0, length);

    cout << "Answer = " << str;
}