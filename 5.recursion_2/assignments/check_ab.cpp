#include <iostream>
using namespace std;

bool checkABHelper(string str, int index)
{
    if (index == str.length())
    {
        return true;
    }

    if (str[index] == 'a')
    {
        if (index + 1 < str.length() && str[index + 1] == 'b' && index + 2 < str.length() && str[index + 2] == 'b')
        {
            return checkABHelper(str, index + 3);
        }
        return checkABHelper(str, index + 1);
    }

    if (index + 1 < str.length() && str[index] == 'b' && str[index + 1] == 'b')
    {

        return (index + 2 == str.length() || checkABHelper(str, index + 2));
    }

    return false;
}

bool checkAB(string s)
{

    if (s.empty() || s[0] != 'a')
    {
        return false;
    }
    return checkABHelper(s, 0);
}

int main()
{
    string str;
    cout << "Enter the string : ";
    cin >> str;
    cout << checkAB(str);
}