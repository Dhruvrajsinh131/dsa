#include <iostream>
using namespace std;

void printPermutations(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
    }

    for (int i = 0; i < input.size(); i++)
    {
        string prefix = output + input[i];
        string rem = input.substr(0, i) + input.substr(i + 1);
        printPermutations(rem, prefix);
    }
}

int main()
{
    string input = "abc";
    printPermutations(input, "");
}