#include <iostream>
using namespace std;

void removeDups(char *str)
{
    if (*str == '\0')
    {
        return;
    }

    if (*str != *(str + 1))
    {
        removeDups(str + 1);
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

        removeDups(str);
    }
}

int main()
{
    char str[100];

    cout << "Enter the string : ";
    cin >> str;
    removeDups(str);

    cout << "Result = " << str;
}