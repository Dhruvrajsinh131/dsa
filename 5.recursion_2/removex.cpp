#include <iostream>
using namespace std;

void removex(char *str, char target)
{
    if (str[0] == '\0')
    {
        return;
    }

    if (str[0] != target)
    {
        removex(str + 1, target);
    }
    else
    {
        int i = 1;

        while (str[i] != '\0')
        {
            str[i - 1] = str[i];
            i++;
        }
        str[i - 1] = '\0';

        removex(str, target);
    }
}

int main()
{
    char str[100];
    cout << "Enter the string : ";
    cin >> str;

    char target;

    cout << "Enter the target character to remove : ";
    cin >> target;

    removex(str, target);

    cout << "Result = " << str;
}