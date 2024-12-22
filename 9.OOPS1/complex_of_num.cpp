#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imaginary;

public:
    Complex(int r, int i)
    {
        this->real = r;
        this->imaginary = i;
    }

    void print()
    {
        cout << real << " + " << imaginary << "i" << endl;
    }

    void add(const Complex &c)
    {
        this->real += c.real;
        this->imaginary += c.imaginary;
    }

    void multiply(const Complex &c)
    {
        int newReal = (this->real * c.real) - (this->imaginary * c.imaginary);
        int newImaginary = (this->real * c.imaginary) + (this->imaginary * c.real);

        this->real = newReal;
        this->imaginary = newImaginary;
        // this->real = c.real;
        // this->imaginary = c.imaginary;
    }
};

int main()
{
    Complex *c1 = new Complex(4, 5);
    Complex *c2 = new Complex(6, 7);

    c1->print();

    // c1->add(*c2);
    // c1->print();

    c1->multiply(*c2);
    c1->print();
}