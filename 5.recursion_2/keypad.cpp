#include <iostream>
using namespace std;

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(string input, int index, string currentCombination)
{
    if (index == input.size())
    {
        cout << currentCombination << endl;
        return;
    }

    int digit = input[index] - '0';

    string letters = keypad[digit];

    for (int i = 0; i < letters.size(); i++)
    {
        currentCombination[index] = letters[i];
        backtrack(input, index + 1, currentCombination);
    }
}

void printCombos(string input)
{
    if (input.empty())
    {
        return;
    }

    string currentCombination(input.size(), ' ');
    backtrack(input, 0, currentCombination);
}

int main()
{
    string input;
    cout << "Enter the number : ";
    cin >> input;

    cout << "Answer = ";

    printCombos(input);
}