#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput()
{
    int data;

    // Taking First Input
    cin >> data;

    // Initialize head as nullptr
    Node *head = nullptr;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cin >> data;
    }

    return head;
}

void print(Node *head)
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
    print(head);
}