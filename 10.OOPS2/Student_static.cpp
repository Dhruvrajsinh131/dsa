#include <iostream>
using namespace std;

class Student
{
    static int totalStudents;

public:
    int rollNo;
    int age;

    Student()
    {
        totalStudents++;
    }

    int getRollNo()
    {
        return rollNo;
    }

    static int getTotalStudents()
    {
        return totalStudents;
    }
};

int Student ::totalStudents = 0; // Initialize static Members

int main()
{

    Student *s1 = new Student();
    Student *s2 = new Student();
    Student *s3 = new Student();
    Student *s4 = new Student();
    Student *s5 = new Student();

    // cout << s1->age << " - " << s1->rollNo << endl;
    // cout << s1->totalStudents << endl;

    // s1->totalStudents = 13;
    cout << Student ::getTotalStudents(); // Access static Members
}