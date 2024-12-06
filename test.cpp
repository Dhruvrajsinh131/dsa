#include <iostream>
using namespace std;

int getSubseqs(string input, string *output)
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallStr = input.substr(1);
    int smallStrLength = getSubseqs(smallStr, output);

    for (int i = 0; i < smallStrLength; i++)
    {
        output[i + smallStrLength] = input[0] + output[i];
    }
    return 2 * smallStrLength;
}

void printSubSeqs(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    printSubSeqs(input.substr(1), output);
    printSubSeqs(input.substr(1), input[0] + output);
}
int main()
{
    string input;
    cout << "Enter input string : ";
    cin >> input;

    printSubSeqs(input, "");
}