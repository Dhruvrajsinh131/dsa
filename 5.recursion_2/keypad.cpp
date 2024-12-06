#include <iostream>
using namespace std;
string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int getComboCount(string input)
{
    int count = 1;

    for (int i = 0; input[i] != '\0'; i++)
    {
        int digit = input[i] - '0';
        count *= keypad[digit].size();
    }

    return count;
}

void backTrack(string input, int index, string currCombo, string *output, int &outputIndex)
{
    if (index == currCombo.size())
    {
        output[outputIndex++] = currCombo;
        return;
    }

    int digit = input[index] - '0';
    string letters = keypad[digit];

    for (int i = 0; i < letters.size(); i++)
    {
        currCombo[index] = letters[i];
        backTrack(input, index + 1, currCombo, output, outputIndex);
    }
}

string *getCombos(string input, int &size)
{
    if (input.empty())
    {
        size = 0;
        return nullptr;
    }

    size = getComboCount(input);
    string *output = new string[size];

    string currCombo(input.size(), ' ');
    int outputIndex = 0;

    backTrack(input, 0, currCombo, output, outputIndex);

    return output;
}

int main()
{
    string input;

    cout << "Enter the Number : ";
    cin >> input;
    cout << "Answer : ";
    int size = 0;

    string *op = getCombos(input, size);

    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << op[i] << endl;
    }

    delete[] op;
}