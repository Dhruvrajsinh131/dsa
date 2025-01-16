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

Node *findMiddle(Node *head)
{
    if (head == nullptr)
        return head;

    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

Node *mergeTwoLists(Node *head1, Node *head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    Node *mergedHead = nullptr;

    if (head1->data < head2->data)
    {
        mergedHead = head1;
        mergedHead->next = mergeTwoLists(head1->next, head2);
    }
    else
    {
        mergedHead = head2;
        mergedHead->next = mergeTwoLists(head1, head2->next);
    }

    return mergedHead;
}

Node *mergeSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *middle = findMiddle(head);
    Node *half2 = middle->next;
    middle->next = nullptr;

    Node *sortedHalf1 = mergeSort(head);
    Node *sortedHalf2 = mergeSort(half2);

    return mergeTwoLists(sortedHalf1, sortedHalf2);
}

int main()
{
    Node *head = takeInput();
    print_LL(head);

    head = mergeSort(head);

    // Print the sorted linked list
    cout << "Sorted linked list: ";
    print_LL(head);
}