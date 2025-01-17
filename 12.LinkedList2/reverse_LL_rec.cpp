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

Node *reverse_LL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *reversedList = reverse_LL(head->next);

    head->next->next = head;
    head->next = nullptr;

    return reversedList;
}

int main()
{

    Node *head = takeInput();
    print_LL(head);

    head = reverse_LL(head);
    print_LL(head);
}