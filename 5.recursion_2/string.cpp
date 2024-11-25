#include <iostream>
using namespace std;

int main()
{
    // string str = "test";
    // string str1;
    // str1 = "test1";

    // string *str3 = new string;
    // *str3 = "test3";
    // cout << str << endl;
    // cout << str1 << endl;
    // cout << *str3 << endl;

    // string s;
    // // cin >> s;
    // getline(cin, s);
    // cout << "Input = " << s << endl;

    string s1 = "Hi ";
    string s2 = "Dhruv";

    string s3 = s1 + s2;

    cout << s3 << endl;
    cout << "Size  = " << s3.size() << endl;
    cout << s3.substr(1) << endl;
    cout << s3.substr(1, 3) << endl;
    cout << s3.find("Dih") << endl;
}