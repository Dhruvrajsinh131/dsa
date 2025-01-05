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

int get_LL_length_rec(Node *head, int length = 0)
{
    if (head == nullptr)
    {
        return length;
    }

    head = head->next;
    length++;

    return get_LL_length_rec(head, length);
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

Node *insertAtIthIndex(Node *head, int i, int data)
{
    Node *newNode = new Node(data);

    if (i == 0)
    {
        newNode->next = head;
        return newNode;
    }

    Node *temp = head;
    int count = 0;

    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp != nullptr)
    {

        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

Node *deleteNodeAtIthIndex(Node *head, int index)
{

    if (head == nullptr)
    {
        cout << "List is empty. cannot delete ." << endl;
        return head;
    }

    if (index == 0)
    {
        Node *toDelete = head;

        head = head->next;

        delete toDelete;

        return head;
    }

    int count = 0;
    Node *temp = head;

    while (temp != nullptr && count < index - 1)
    {
        temp = temp - 1;
        count++;
    }

    if (temp == nullptr && temp->next == nullptr)
    {

        cout << "Index out of bounds for deletation" << endl;
        return head;
    }

    Node *toDate = temp->next;
    temp->next = toDate->next;

    delete toDate;

    return head;
}

int main()
{

    Node *head = takeInput();

    print_LL(head);

    cout << "length = " << get_LL_length(head) << endl;
    cout << "length (rec)= " << get_LL_length_rec(head) << endl;
    cout << "Element At index 1 = " << printIthelemet(1, head) << endl;

    // head = insertAtIthIndex(head, 0, 69);
    head = deleteNodeAtIthIndex(head, 9);
    print_LL(head);
}