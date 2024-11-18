#include <iostream>
using namespace std;

int getLength(char *str)
{

    if (str[0] == '\0')
    {
        return 0;
    }

    int smallString = getLength(str + 1);

    return 1 + smallString;
}

int main()
{
    char str[100];
    cout << "Enter the string : ";
    cin >> str;

    cout << "Length = " << getLength(str);
}
