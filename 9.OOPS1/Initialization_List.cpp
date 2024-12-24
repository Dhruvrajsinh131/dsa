#include <iostream>
using namespace std;

class Student
{
public:
    int age;
    int const rollNo;

    int &x;
    Student(int r, int age) : rollNo(r), age(age), x(this->age)
    {
    }

    void display()
    {

        cout << "Age = " << age << endl;
        cout << "RollNo = " << rollNo << endl;
    }
};

int main()
{

    Student s1(13, 20);

    s1.display();

    // s1.rollNo = 1001;
}