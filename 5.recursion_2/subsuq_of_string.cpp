#include <iostream>
using namespace std;

int subsq(string input, string *output)
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallString = input.substr(1);
    int smallStrSize = subsq(smallString, output);
    for (int i = 0; i < smallStrSize; i++)
    {
        output[i + smallStrSize] = input[0] + output[i];
    }
    return 2 * smallStrSize;
}

int main()
{
    string input;
    cin >> input;

    string *output = new string[1000];

    int count = subsq(input, output);

    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }

    delete[] output;
    output = nullptr;
}