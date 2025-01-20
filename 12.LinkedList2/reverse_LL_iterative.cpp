#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput()
{
    int data;

    Node *head = nullptr;
    Node *tail = nullptr;

    cout << "Enter LL elements :-\nEnter -1 for Exit.";
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
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

Node *reverse_LL_iterative(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

int main()
{

    Node *head = takeInput();
    print_LL(head);
    head = reverse_LL_iterative(head);
    print_LL(head);
}