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

Node *removeDup(Node *head)
{
    Node *temp = head;

    while (temp != nullptr && temp->next != nullptr)
    {

        Node *nextNode = temp->next;
        if (temp->data == nextNode->data)
        {
            temp->next = nextNode->next;
            delete nextNode;
        }
        else
        {

            temp = temp->next;
        }
    }

    return head;
}

int main()
{

    Node *head = takeInput();
    print_LL(head);

    head = removeDup(head);
    print_LL(head);
}