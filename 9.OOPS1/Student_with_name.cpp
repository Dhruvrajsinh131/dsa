#include <iostream>
#include <string.h>
using namespace std;
class Student_with_name
{

    int age;
    char *name;

public:
    Student_with_name(int age, char *name)
    {
        this->age = age;

        // Shallow Copy
        // this->name = name; // We will avoid to use as it is manipulating The Array directly
        // Deep Copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void display()
    {

        cout << "Name = " << name << " ." << endl;
        cout << "Age = " << age << " ." << endl;
    }
};