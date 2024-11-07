#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int j = 21;

    // this just makes read only path  to variable it is pointing
    int const *ptr = &i;
    ptr = &j;
    // (*ptr)++; this gives error because pointer has readonly access

    // this makes the memory it is pointing const you can not ressign it to any other memory
    int *const ptr2 = &i;
    // ptr2 = &j; gives error

    // you can not ressign it to any memory location & and can not change variablr because of read only access
    int const *const ptr3 = &i;
    // ptr3 = &j; gives error
    // (*ptr3)++; gives error
}