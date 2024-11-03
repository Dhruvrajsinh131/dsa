#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3};
    char str[] = "abc";

    cout << arr << endl;
    cout << str << endl;
    char *ptr = &str[0];

    cout << ptr;

    char c = 's';
    char *pc = &c;

    cout << pc << endl;

    char sstr[] = "abcd";
    char *psstr = "abcd"; // Not good to do

    cout << sstr << endl;
    cout << psstr << endl;
}