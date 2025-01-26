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
            newNode->prev = tail;
            tail = tail->next;
        }

        cin >> data;
    }

    return head;
}

void print_LL(Node *head)
{
    Node *temp = head;

    while (temp)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

Node *swap_nodes(Node *head, int m, int n)
{

    Node *left = nullptr;
    Node *right = nullptr;

    int index = 0;
    Node *temp = head;

    while (temp)
    {
        if (m == index)
        {
            left = temp;
        }

        if (n == index)
        {
            right = temp;
            break;
        }

        index++;
        temp = temp->next;
    }

    if (!left || !right)
    {
        head;
    }

    Node *prevLeft = left->prev;
    Node *prevRight = right->prev;
    Node *nextLeft = left->next;
    Node *nextRight = right->next;

    if (prevLeft)
        prevLeft->next = right;
    if (prevRight)
        prevRight->next = left;

    if (nextLeft)
        nextLeft->prev = right;

    if (nextRight)
        nextRight->prev = left;

    right->prev = prevLeft;
    right->next = nextLeft;

    left->prev = prevRight;
    left->next = nextRight;

    if (m == 0)
        head = right;

    if (n == 0)
        head = left;

    return head;
}

int main()
{

    Node *head = takeInput();
    print_LL(head);

    int m, n;

    cout << "Enter first Node index : ";
    cin >> m;
    cout << "Enter second Node index : ";
    cin >> n;

    head = swap_nodes(head, m, n);

    print_LL(head);
}