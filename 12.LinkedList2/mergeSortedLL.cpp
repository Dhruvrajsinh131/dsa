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
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

Node *mergeSortedLL(Node *l1, Node *l2)
{

    Node *temp1 = l1;
    Node *temp2 = l2;

    Node *newhead = nullptr;
    Node *newtail = nullptr;

    if (temp1->data > temp2->data)
    {
        newhead = temp2;
        newtail = temp2;
        temp2 = temp2->next;
    }
    else
    {
        newhead = temp1;
        newtail = temp1;
        temp1 = temp1->next;
    }

    while (temp1 && temp2)
    {

        if (temp1->data > temp2->data)
        {
            newtail->next = temp2;
            newtail = newtail->next;

            temp2 = temp2->next;
        }
        else
        {
            newtail->next = temp1;
            newtail = newtail->next;

            temp1 = temp1->next;
        }
    }

    if (temp1)
    {
        newtail->next = temp1;
    }

    if (temp2)
    {
        newtail->next = temp2;
    }

    return newhead;
}

int main()
{
    cout << "Enter LL 1" << endl;
    Node *ll1head = takeInput();
    cout << "Enter LL 2" << endl;
    Node *ll2head = takeInput();

    cout << "Linked List 1 = ";
    print_LL(ll1head);
    cout << "Linked List 2 = ";
    print_LL(ll2head);

    Node *merged = mergeSortedLL(ll1head, ll2head);
    print_LL(merged);
}