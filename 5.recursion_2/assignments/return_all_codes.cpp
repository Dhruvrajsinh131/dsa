#include <iostream>
#include <string>
using namespace std;

// Helper function to convert a numeric string to its corresponding character
char getChar(int num)
{
    return 'a' + num - 1;
}

// Recursive function to generate and print all possible codes
void getCodesHelper(string input, string output)
{
    // Base case: If the input is empty, print the current output and return
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    // Take the first digit and map it to a character
    int num1 = input[0] - '0';
    if (num1 > 0 && num1 <= 26)
    {
        getCodesHelper(input.substr(1), output + getChar(num1));
    }

    // Take the first two digits (if possible) and map them to a character
    if (input.size() >= 2)
    {
        int num2 = stoi(input.substr(0, 2));
        if (num2 > 0 && num2 <= 26)
        {
            getCodesHelper(input.substr(2), output + getChar(num2));
        }
    }
}

// Function to generate all possible codes and print them
void getCodes(string input)
{
    getCodesHelper(input, "");
}

int main()
{
    string input;
    cin >> input;

    getCodes(input);

    return 0;
}
