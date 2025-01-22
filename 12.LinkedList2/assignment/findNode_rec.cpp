#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput()
{
    int data;
    Node *head = nullptr;
    Node *tail = nullptr;

    cout << "Enter the LL elements : " << endl;
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

int findNodeIndex_rec(Node *head, int index, int target)
{
    if (head == nullptr)
    {
        return -1;
    }

    if (head->data == target)
    {
        return index;
    }

    return findNodeIndex_rec(head->next, index + 1, target);
}

int main()
{

    Node *ll1 = takeInput();
    print_LL(ll1);

    int target;

    cout << endl;
    cout << "Enter the element to find Index : ";
    cin >> target;

    cout << findNodeIndex_rec(ll1, 0, target);
}