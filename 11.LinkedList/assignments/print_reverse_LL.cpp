#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput()
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
            tail = tail->next;
        }

        cin >> data;
    }

    return head;
}

void print_LL(Node *head)
{
    if (head == nullptr)
    {
        return;
    }

    cout << head->data << " ";

    print_LL(head->next);
}

void rev_print_LL(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    rev_print_LL(head->next);
    cout << head->data << " ";
}

int main()
{
    Node *head = takeInput();

    cout << endl;
    print_LL(head);
    cout << endl;
    rev_print_LL(head);
}