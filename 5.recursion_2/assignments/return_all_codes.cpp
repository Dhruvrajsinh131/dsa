#include <iostream>
using namespace std;

char getChar(int num)
{
    return 'a' + num - 1;
}

void printCodes(string number, string output)
{
    if (number.empty())
    {
        cout << output << endl;
        return;
    }

    int num1 = number[0] - '0';
    if (num1 >= 1 && num1 <= 26)
    {
        printCodes(number.substr(1), output + getChar(num1));
    }

    if (number.size() >= 2)
    {
        int num2 = stoi(number.substr(0, 2));
        if (num2 >= 1 && num2 <= 26)
        {
            printCodes(number.substr(2), output + getChar(num2));
        }
    }
}

int main()
{
    string number;
    cout << "Enter the number : ";
    cin >> number;

    printCodes(number, "");
}