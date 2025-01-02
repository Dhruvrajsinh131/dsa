#include <iostream>
using namespace std;
#include "Node.cpp"

Node *take_input()
{
    int data;

    Node *head = nullptr;
    Node *tail = nullptr;
    cin >> data;

    while (data != -1)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print_LL(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{

    Node *head = take_input();
    print_LL(head);
}