#include <iostream>
using namespace std;

int getLength(char str[])
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

bool isPalindrome(char str[], int start, int end)
{

    if (start >= end)
    {
        return true;
    }

    if (str[start] != str[end])
    {
        return false;
    }
    else
    {
        return isPalindrome(str, start + 1, end - 1);
    }
}

int main()
{
    char str[] = "kanak";
    int length = getLength(str);

    bool ans = isPalindrome(str, 0, length - 1);

    cout << "Answer = " << ans;
}