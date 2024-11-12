#include <iostream>
using namespace std;

void replacePi(char *str, char *resultStr, int index, int resultIndex)
{
    if (str[index] == '\0')
    {
        resultStr[resultIndex] = '\0';
        return;
    }

    if (str[index] == 'p' && str[index + 1] == 'i')
    {
        resultStr[resultIndex] = '3';
        resultStr[resultIndex + 1] = '.';
        resultStr[resultIndex + 2] = '1';
        resultStr[resultIndex + 3] = '4';

        replacePi(str, resultStr, index + 2, resultIndex + 4);
    }
    else
    {
        resultStr[resultIndex] = str[index];
        replacePi(str, resultStr, index + 1, resultIndex + 1);
    }
}

int main()
{
    char str[100];

    cout << "Enter the string : ";
    cin >> str;

    char resultStr[200];

    replacePi(str, resultStr, 0, 0);

    cout << "Output = " << resultStr;
}