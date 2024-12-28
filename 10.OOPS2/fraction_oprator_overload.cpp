#include <iostream>
using namespace std;

class Fraction
{
private:
    int numarator;
    int denominator;

public:
    Fraction(int n, int d)
    {
        this->numarator = n;
        this->denominator = d;
    }

    void print()
    {
        cout << this->numarator << "/" << this->denominator << endl;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(this->numarator, this->denominator);
        for (int i = 1; i <= j; i++)
        {
            if (this->numarator % i == 0 & this->denominator % i == 0)
            {
                gcd = i;
            }
        }
        this->numarator = this->numarator / gcd;
        this->denominator = this->denominator / gcd;
    }

    Fraction operator+(const Fraction &f2)
    {

        int lcm = this->denominator * f2.denominator;
        int upperValue = (this->numarator * f2.denominator) + (this->denominator * f2.numarator);

        // this->denominator = lcm;
        // this->numarator = upperValue;

        Fraction *fNew = new Fraction(upperValue, lcm);
        fNew->simplify();

        return *fNew;
    }

    Fraction operator*(const Fraction &f2)
    {

        // this->numarator = this->denominator * f2.denominator;
        // this->denominator = this->numarator * f2.numarator;

        Fraction f(this->numarator * f2.numarator, this->denominator * f2.denominator);

        f.simplify();

        return f;
    }

    bool operator==(Fraction &f2)
    {
        this->simplify();
        f2.simplify();
        return this->numarator == f2.numarator && this->denominator == f2.denominator;
    }

    // Pre-Increment

    Fraction &operator++()
    {
        this->numarator = this->numarator + this->denominator;
        simplify();

        return *this;
    }
};

int main()
{

    Fraction f1(10, 2);

    Fraction f2(10, 1);

    Fraction f3 = f1 + (f2);
    Fraction f4 = f1 + (f2);

    f1.print();
    f2.print();
    f3.print();
    f4.print();

    Fraction f5 = f1 * f2;

    f5.print();

    if (f1 == f2)
    {
        cout << "Equal" << endl;
    }
    else
    {

        cout << "Not Equal" << endl;
    }

    Fraction *f6 = new Fraction(10, 2);
    Fraction *f7 = new Fraction(++(++(++(*f6))));

    f6->print();
    f7->print();

    delete f6;
    delete f7;
}
