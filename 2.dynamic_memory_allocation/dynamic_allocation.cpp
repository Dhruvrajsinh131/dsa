#include <iostream>
using namespace std;

int main()
{

    // int *p = new int;
    // *p = 10;

    // cout << *p << endl;

    // double *pd = new double;
    // *pd = 3.4;

    // cout << *pd << endl;

    // char *pc = new char;
    // *pc = 'y';

    // cout << *pc << endl;

    // int n;

    // cout << "ENter size of array";
    // cin >> n;

    // int *arr = new int[n];

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // int max = -1;
    // for (int i = 0; i < n; i++)
    // {
    //     if (max < arr[i])
    //     {
    //         max = arr[i];
    //     }
    // }

    // cout << "max value = " << max;

    int *ptr = new int;
    *ptr = 234324;

    cout << *ptr << endl;

    delete ptr;
}
