#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput()
{
    int data;
    cin >> data;

    Node *head = nullptr;

    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == nullptr)
        {
            head = n;
        }
        else
        {
            Node *temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = n;
        }

        cin >> data;
    }
    return head;
}

void print(Node *head)
{

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{

    // Statically
    // Node n1(2);
    // Node n2(4);
    // Node n3(6);
    // Node n4(8);
    // Node n5(10);

    // // Defining Head of Liked List
    // Node *head = &n1;

    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    Node *head = takeInput();

    print(head);

    // cout << n1.data << " " << n2.data << endl;
    // cout << head->data << endl;

    // Dynamically

    // Node *n3 = new Node(3);
    // Node *head2 = n3;
    // Node *n4 = new Node(5);

    // n3->next = n4;

    // cout << head2->data << endl;

    // delete n3;
    // delete n4;
}