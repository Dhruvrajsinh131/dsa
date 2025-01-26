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

    while (temp != nullptr)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
}

void delete_n_nodes(Node *head, int m, int n)
{

    if (!head || m <= 0 || n <= 0)
        return;
    int c1 = 1;
    int c2 = 1;

    Node *t1 = head;
    Node *t2 = nullptr;

    while (t1)
    {
        while (c1 < m && t1)
        {
            t1 = t1->next;
            c1++;
        }

        if (!t1)
            return;
        t2 = t1->next;

        while (c2 <= n && t2)
        {
            Node *todDeleteNode = t2;
            t2 = t2->next;
            delete todDeleteNode;
            c2++;
        }

        t1->next = t2;

        c1 = 1;
        c2 = 1;

        t1 = t2;
    }
}

int main()
{

    int m, n;

    Node *head = takeInput();

    print_LL(head);

    cout << "Enter ineterval : ";
    cin >> m;
    cout << "Enter number of node to be skipped : ";
    cin >> n;

    delete_n_nodes(head, m, n);

    print_LL(head);
}