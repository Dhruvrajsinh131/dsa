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

    void add(const Fraction &f2)
    {

        int lcm = this->denominator * f2.denominator;
        int upperValue = (this->numarator * f2.denominator) + (this->denominator * f2.numarator);

        this->denominator = lcm;
        this->numarator = upperValue;
        simplify();
    }

    void multiply(const Fraction &f2)
    {

        this->numarator = this->denominator * f2.denominator;
        this->denominator = this->numarator * f2.numarator;

        simplify();
    }
};

int main()
{
    Fraction *f1 = new Fraction(10, 3);
    f1->print();

    Fraction *f2 = new Fraction(10, 3);
    f1->add(*f2);

    f1->print();

    f1->multiply(*f2);

    f1->print();

    delete f1;
    delete f2;
}
