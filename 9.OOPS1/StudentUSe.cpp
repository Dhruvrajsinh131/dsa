#include <iostream>
using namespace std;
#include "student.cpp"

int main()
{
    // Create Objects Staticalluy
    Student s1;
    Student s2;
    Student s3;

    cin >> s1.name;
    s1.setRollNo(21);

    cout << s1.name << endl;
    cout << s1.getRollNo() << endl;

    // Create Objects Dynamically

    Student *s11 = new Student;

    cin >> s11->name;
    s11->setRollNo(13);

    Student *s22 = new Student();
    Student *s33 = new Student();

    cout << s11->name << endl;
    cout << s11->getRollNo() << endl;
}