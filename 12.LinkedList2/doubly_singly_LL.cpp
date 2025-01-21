#include <iostream>
using namespace std;
#include "DNode.cpp"

Node *takeInput()
{
    int data;
    Node *head = nullptr;
    Node *tail = nullptr;

    cout << "Enter doubly linked list elements (Enter -1 to stop): ";
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
            newNode->prev = tail;
            tail = newNode;
        }
        cin >> data;
    }

    return head;
}

void print_DLL(Node *head)
{
    if (head == nullptr)
    {
        cout << "Doubly linked list is empty." << endl;
        return;
    }

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

    Node *head = takeInput();
    cout << "Doubly linked list: ";
    print_DLL(head);
}