#include <iostream>
using namespace std;

void print_subs(string input, string output)

{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    print_subs(input.substr(1), output);
    print_subs(input.substr(1), output + input[0]);
}

int main()
{
    string str;
    cout << "Enter the string : ";
    cin >> str;

    print_subs(str, "");
}