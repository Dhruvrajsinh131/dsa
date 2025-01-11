#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

void insertNode(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    while (current)
    {
        Node *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    if (!head || !head->next)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *secondHalf = reverseList(slow);

    Node *firstHalf = head;
    Node *temp = secondHalf;
    bool isPalin = true;
    while (temp)
    {
        if (firstHalf->data != temp->data)
        {
            isPalin = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    reverseList(secondHalf);

    return isPalin;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 2);
    insertNode(head, 1);

    cout << "Original List: ";
    printList(head);

    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
