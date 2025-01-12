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

Node *reverse_LL(Node *head)
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

    Node *secondHalf = reverse_LL(slow);
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
        temp = temp->next;
        firstHalf = firstHalf->next;
    }

    reverse_LL(secondHalf);

    return isPalin;
}

int main()
{

    Node *head = takeInput();
    // print_LL(head);
    // head = reverse_LL(head);

    print_LL(head);
    cout << "Is palin = " << isPalindrome(head) << endl;
    print_LL(head);
}