#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput()
{
    int data;
    Node *head = nullptr;
    Node *tail = nullptr;

    cout << "Enter the LL elements. Enter -1 to exit" << endl;
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

Node *even_after_odd(Node *head)
{

    Node *temp = head;
    Node *oddList = nullptr;
    Node *oddListTail = nullptr;
    Node *evenList = nullptr;
    Node *evenListTail = nullptr;

    while (temp != nullptr)
    {

        if (temp->data % 2 == 0 || temp->data == 0)
        {
            if (evenList == nullptr)
            {
                evenList = temp;
                evenListTail = temp;
            }
            else
            {
                evenListTail->next = temp;
                evenListTail = evenListTail->next;
            }
        }
        else
        {
            if (oddList == nullptr)
            {
                oddList = temp;
                oddListTail = temp;
            }
            else
            {
                oddListTail->next = temp;
                oddListTail = oddListTail->next;
            }
        }
        temp = temp->next;
    }

    // Make even list's tail node pointing to nullptr to avoid circular/infinite traveral
    if (evenListTail != nullptr)
    {
        evenListTail->next = nullptr;
    }

    if (oddList != nullptr)
    {

        oddListTail->next = evenList;
        return oddList;
    }

    return evenList;
}

int main()
{

    Node *head = takeInput();
    print_LL(head);

    head = even_after_odd(head);
    print_LL(head);
}
