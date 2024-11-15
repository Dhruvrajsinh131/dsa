#include <iostream>
using namespace std;

void pairStar(char *str, int index, int &size)
{
    if (str[index] == '\0')
    {
        return;
    }

    if (str[index] == str[index + 1])
    {
        for (int i = size; i >= index + 1; i--)
        {
            str[i + 1] = str[i];
        }
        size++;

        str[index + 1] = '*';

        pairStar(str, index + 2, size);
    }
    else
    {
        pairStar(str, index + 1, size);
    }
}

int getLength(char *str)
{
    int l = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        l++;
    }

    return l;
}

int main()
{
    char str[100];

    cout << "Enter the string : ";
    cin >> str;

    int length = getLength(str);

    pairStar(str, 0, length);

    cout << "Answer = " << str;
}