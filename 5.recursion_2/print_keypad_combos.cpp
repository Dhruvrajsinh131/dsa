#include <iostream>
using namespace std;
string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printCombos(int input, string output)
{
    if (input == 0)
    {
        cout << output << endl;
        return;
    }

    int digit = input % 10;
    string letters = keypad[digit];

    for (int i = 0; i < letters.size(); i++)
    {
        printCombos(input / 10, letters[i] + output);
    }
}

int main()
{
    int input;

    cout << "Enter the input : ";
    cin >> input;

    printCombos(input, "");
}