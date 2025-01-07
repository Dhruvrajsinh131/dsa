#include <iostream>
using namespace std;
#include "Node.cpp"

Node *appendLastNToFirst(Node *head, int i)
{
    Node *temp = head;

    int length = 0;

    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }

    int splitPoint = length - i;
    if (splitPoint <= 0)
        return head;

    temp = head;

    for (int i = 1; i < splitPoint; i++)
    {
        temp = temp->next;
    }

    Node *newHead = temp->next;
    temp->next = nullptr;

    Node *tail = newHead;

    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    tail->next = head;

    return newHead;
}

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

int main()
{
    Node *head = takeInput();

    print_LL(head);
    head = appendLastNToFirst(head, 2);
    print_LL(head);
}