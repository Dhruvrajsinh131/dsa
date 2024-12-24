#include <iostream>
using namespace std;
#include "Student_with_name.cpp"

int main()
{

    char name[] = "Dhruvraj";
    Student_with_name *s1 = new Student_with_name(23, name);

    // Student_with_name s1(23, name);

    // s1.display();

    Student_with_name *s2 = new Student_with_name(*s1);
    s2->name[0] = 'V';
    s1->display();
    s2->display();
    s1->display();

    // name[3] = 'v';
    // Student_with_name *s2 = new Student_with_name(22, name);
    // Student_with_name s2(22, name);

    // s2.display();
    // s1.display();
    // s1->display();

    Student_with_name *s3 = new Student_with_name(23, name);
}