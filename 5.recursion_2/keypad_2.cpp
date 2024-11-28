#include <iostream>
using namespace std;

const string keypad[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypadStrings(int n, string output)
{
    if (n == 0)
    {
        cout << output << endl;
        return;
    }

    int digit = n % 10;

    string chars = keypad[digit];

    for (int i = 0; i < chars.size(); i++)
    {
        printKeypadStrings(n / 10, chars[i] + output);
    }
}

int main()
{
    int n;
    cin >> n; // Input the number

    printKeypadStrings(n, ""); // Call the recursive function
    return 0;
}