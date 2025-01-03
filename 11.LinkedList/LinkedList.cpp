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

int get_LL_length(Node *head)
{
    int length = 0;

    Node *temp = head;

    while (temp != nullptr)
    {
        length++;

        temp = temp->next;
    }

    return length;
}

int printIthelemet(int index, Node *head)
{
    int length = 0;
    Node *temp = head;

    while (temp != nullptr)
    {

        if (length == index)
        {
            return temp->data;
        }

        length++;
        temp = temp->next;
    }

    return -1;
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

    cout << "length = " << get_LL_length(head) << endl;
    cout << "Element At index 1 = " << printIthelemet(2, head) << endl;
}