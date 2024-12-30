#include <iostream>
using namespace std;
#include "Node.cpp"

int main()
{

    // Statically
    Node n1(2);
    Node *head = &n1;
    Node n2(4);

    n2.next = &n2;

    // cout << n1.data << " " << n2.data << endl;
    cout << head->data;
}