#include <iostream>
using namespace std;

template <typename T, typename V>

class Pair
{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }

    T getX()
    {
        return x;
    }

    void setY(V y)
    {
        this->y = y;
    }

    V getY()
    {
        return y;
    }
};

int main()
{
    Pair<Pair<int, int>, int> p1;
    p1.setY(10);

    Pair<int, int> p4;
    p4.setX(456);
    p4.setY(76);

    p1.setX(p4);

    cout << p1.getX().getX() << " " << p1.getX().getY() << " " << p1.getY() << endl;

    // p1.setX(10);
    // p1.setY(20);

    // cout << p1.getX() << " " << p1.getY() << endl;

    // Pair<double, double> p2;

    // p2.setX(100.32);
    // p2.setY(20.532);

    // cout << p2.getX() << " " << p2.getY() << endl;
    // Pair<char, int> p3;

    // p3.setX('d');
    // p3.setY(20);

    // cout << p3.getX() << " " << p3.getY() << endl;
}