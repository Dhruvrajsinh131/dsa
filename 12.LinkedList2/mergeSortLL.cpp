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

Node *findMidPoint(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *mergeList(Node *l1, Node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    Node *tempHead = nullptr;
    Node *tempTail = nullptr;

    Node *temp1 = l1;
    Node *temp2 = l2;

    if (temp1->data > temp2->data)
    {
        tempHead = temp2;
        tempTail = temp2;
        temp2 = temp2->next;
    }
    else
    {
        tempHead = temp1;
        tempTail = temp1;
        temp1 = temp1->next;
    }

    while (temp1 && temp2)
    {
        if (temp1->data > temp2->data)
        {
            tempTail->next = temp2;
            tempTail = tempTail->next;
            temp2 = temp2->next;
        }
        else
        {
            tempTail->next = temp1;
            tempTail = tempTail->next;
            temp1 = temp1->next;
        }
    }

    if (temp1)
        tempTail->next = temp1;
    if (temp2)
        tempTail->next = temp2;

    return tempHead;
}

Node *mergeSort(Node *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *midpoint = findMidPoint(head);
    Node *secondHalf = midpoint->next;
    midpoint->next = nullptr;

    Node *sortedHalf1 = mergeSort(head);
    Node *sortedHalf2 = mergeSort(secondHalf);

    return mergeList(sortedHalf1, sortedHalf2);
}

int main()
{

    Node *head = takeInput();

    print_LL(head);

    head = mergeSort(head);

    cout << "Sorted List = ";
    print_LL(head);
}