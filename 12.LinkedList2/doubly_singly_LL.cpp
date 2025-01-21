#include <iostream>
using namespace std;
#include "DNode.cpp"

DNode *takeInput()
{
    int data;

    DNode *head = nullptr;
    DNode *tail = nullptr;

    cout << "Enter the Linked list elems (Enter -1 to exit) : " << endl;
    cin >> data;

    while (data != -1)
    {
        DNode *newNode = new DNode(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }

        cin >> data;
    }

    return head;
}

void print_LL(DNode *head)
{

    DNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void print_reverse_LL(DNode *head)
{
    DNode *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    DNode *tail = temp;

    while (tail != nullptr)
    {

        cout << tail->data << " ";
        tail = tail->prev;
    }

    cout << endl;
}

int main()
{

    DNode *head = takeInput();
    print_LL(head);
    cout << endl;
    print_reverse_LL(head);
}