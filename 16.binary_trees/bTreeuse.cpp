#include <iostream>
using namespace std;
#include "btreeNode.h"

void printTree(BtreeNode<int> *root)
{

    if (root == nullptr)
        return;

    cout << root->data << " :";

    if (root->left)
        cout << "Left ->" << root->left->data << " | ";
    if (root->right)
        cout << "Right -> " << root->right->data;
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

BtreeNode<int> *takeInput()
{
    int rootData;

    cout << "Enter data : " << endl;
    cin >> rootData;

    if (rootData == -1)
    {
        return nullptr;
    }

    BtreeNode<int> *root = new BtreeNode<int>(rootData);
    BtreeNode<int> *leftChild = takeInput();
    BtreeNode<int> *rightChild = takeInput();

    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int main()
{
    // BtreeNode<int> *root = new BtreeNode(1);
    // BtreeNode<int> *node1 = new BtreeNode(2);
    // BtreeNode<int> *node2 = new BtreeNode(3);

    // root->left = node1;
    // root->right = node2;

    BtreeNode<int> *root = takeInput();

    printTree(root);
}
