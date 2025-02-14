#include <iostream>
using namespace std;
#include <vector>

int main()
{
    vector<int> v;
    // vector<int> *vp = new vector<int>();
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);

    // v[0] = 2000;

    // v[3] = 24324;

    // v.push_back(324);
    // v[6] = 45;

    // cout << v[0] << endl;
    // cout << v[1] << endl;
    // cout << v[2] << endl;
    // cout << v[3] << endl;
    // cout << v[4] << endl;
    // cout << v[5] << endl;
    // cout << v[6] << endl;

    // v.pop_back();

    // cout << "Size = " << v.size() << endl;

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }

    for (int i = 0; i < 100; i++)
    {
        v.push_back(i + 1);

        cout << v.size() << endl;
    }

    cout << v.capacity();
}