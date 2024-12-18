#include <iostream>
#include <vector>
using namespace std;

bool canSplit(vector<int> &arr, int length, int index, int leftPart, int rightPart)
{
    if (index == length)
    {
        return leftPart == rightPart;
    }

    int current = arr[index];

    if (current % 5 == 0)
    {
        return canSplit(arr, length, index + 1, leftPart, rightPart + current);
    }
    else if (current % 3 == 0)
    {
        return canSplit(arr, length, index + 1, leftPart + current, rightPart);
    }
    else
    {
        return canSplit(arr, length, index + 1, leftPart + current, rightPart) || canSplit(arr, length, index + 1, leftPart, rightPart + current);
    }
}

bool splitArray(vector<int> &arr, int length)
{

    return canSplit(arr, length, 0, 0, 0);
}

int main()
{
    int n;
    cout << "Enter number of length : ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (splitArray(arr, n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}