#include <iostream>
using namespace std;

class Student
{
public:
    int rollNumber;

private:
    int age;

public:
    // Student()
    // {
    //     cout << "Constructor called" << endl;
    // }

    Student(int rollNumber)
    {
        this->rollNumber = rollNumber;
    }

    Student(int r, int a)
    {
        rollNumber = r;
        age = a;
        cout << "this = " << this << endl;
    }
    void display()
    {
        cout << rollNumber << " " << age << endl;
    }

    int getAge()
    {
        return age;
    }
};

int main()
{

    //     Student *s1 = new Student(10);

    //     s1->display();

    //     Student s2(21, 20);

    //     s2.display();
    // Student *s3 = new Student();

    // s3->display();

    // cout << "addressOf s1 = " << &s1 << endl;
    // cout << "s1 rollNO = " << s1->rollNumber << endl;
    // Student *s2 = new Student(*s1);

    // cout << "s2 rollNO = " << s2->rollNumber << endl;

    Student *s1 = new Student(10, 21);

    s1->display();
    Student *s2 = new Student(11, 23);
    s2->display();

    s2 = s1;

    s2->display();
}