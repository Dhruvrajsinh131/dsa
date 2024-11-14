#include <iostream>
using namespace std;

int convertToInt(char *str, int index)
{
    if (str[index] == '\0')
    {
        return 0;
    }

    int result = convertToInt(str, index + 1);
    int number = str[index] - '0';

    return number * 10 + result;
}

int main()
{
    char str[] = "345";

    int result = convertToInt(str, 0);

    cout << result;
}
