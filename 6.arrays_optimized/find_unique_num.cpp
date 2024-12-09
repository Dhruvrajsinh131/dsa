#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 3, 2, 1, 5};
    int length = 7;

    int uniqueNum = 0;
    for (int i = 0; i < length; i++)
    {
        uniqueNum ^= arr[i];
    }

    cout << "Unique number = " << uniqueNum;
}