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

Node *kReverse(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *current = head;
    Node *prev = nullptr;
    Node *nextNode = nullptr;
    int count = 0;

    while (current != nullptr && count < k)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
        count++;
    }

    if (nextNode != nullptr)
    {
        head->next = kReverse(nextNode, k);
    }

    return prev;
}
int main()
{

    Node *head = takeInput();
    print_LL(head);

    int k;

    cout << "Enter the number k for reverse LL : ";
    cin >> k;

    head = kReverse(head, k);
    print_LL(head);
}
