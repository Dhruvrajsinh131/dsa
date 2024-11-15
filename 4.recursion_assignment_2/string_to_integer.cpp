#include <iostream>
using namespace std;

// int convertToInt(char *str, int start, int end)

// {

//     if (start > end)
//     {
//         return 0;
//     }

//     int num = str[end] - '0';

//     return num + convertToInt(str, start, end - 1) * 10;
// }

int convertToInt2(char *str, int i, int size)

{

    if (size == 0)
    {
        return 0;
    }

    int num = str[i] - '0';

    int getPower = 1;

    for (int i = 0; i < size - 1; i++)
    {
        getPower *= 10;
    }

    return num * getPower + convertToInt2(str, i + 1, size - 1);
}

int main()
{
    char str[] = "345";

    // int result = convertToInt(str, 0, 2); // (string ,start , end)
    int result = convertToInt2(str, 0, 3); // (string ,index , length)

    cout << result;
}
