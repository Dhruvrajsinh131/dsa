#include <iostream>
using namespace std;

class Student
{
public:
    int age;
    Student()
    {
        cout << "Contructor Called" << endl;
    }

    Student(int n)
    {
        cout << "Constructor 2 Called" << endl;
        // this holds the adddress of current Obj
        cout << this << endl;
        this->age = n;
    }
};

int main()
{
    Student s1;

    s1.age = 70;

    Student s2(20);
    cout << s2.age << " " << &s2;
}