#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxilary, char destination)
{
    if (n == 1)
    {
        cout << source << " " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxilary);

    cout << source << " " << destination << endl;

    towerOfHanoi(n - 1, auxilary, source, destination);
}

int main()
{
    int c;
    cin >> c;

    towerOfHanoi(c, 'a', 'b', 'c');
    return 0;
}