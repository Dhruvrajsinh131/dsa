#include <iostream>
#include <string.h>
using namespace std;
class Student_with_name
{

    int age;

public:
    char *name;
    Student_with_name(int age, char *name)
    {
        this->age = age;

        // Shallow Copy
        // this->name = name; // We will avoid to use as it is manipulating The Array directly
        // Deep Copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // Copy Contstructor
    Student_with_name(Student_with_name const &s)
    {

        this->age = s.age;
        // this->name = s.name; // Shallow Copy X
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display()
    {

        cout << "Name = " << name << " ." << endl;
        cout << "Age = " << age << " ." << endl;
    }
};