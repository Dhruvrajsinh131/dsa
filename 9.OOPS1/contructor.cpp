#include <iostream>
using namespace std;

class Student
{
public:
    int rollNumber;

private:
    int age;

public:
    ~Student()
    {
        cout << "Destructor Called" << endl;
    }
    Student()
    {
        cout << "Constructor  1 called" << endl;
    }

    Student(int rollNumber)
    {
        this->rollNumber = rollNumber;
        cout << "Constructor  2 called" << endl;
    }
    Student(int r, int a)
    {
        rollNumber = r;
        age = a;
        cout << "Constructor  3 called" << endl;
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

    // Student *s1 = new Student(10, 21);

    // s1->display();
    // Student *s2 = new Student(11, 23);
    // s2->display();

    // *s2 = *s1;

    // s2->display();

    // delete s1;
    // delete s2;

    Student s1;
    Student s2(10);
    Student s3(10, 21);
    Student s4(s1);

    // s1 = s2;

    Student s5 = s4; // Copy constructor
}