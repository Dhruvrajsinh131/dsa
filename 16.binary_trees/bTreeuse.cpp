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
    int root;
    cout << "Enter data : " << endl;
    cin >> root;

    if (root == -1)
    {
        return nullptr;
    }

    BtreeNode<int> *rootNode = new BtreeNode<int>(root);
    BtreeNode<int> *left = takeInput();
    BtreeNode<int> *right = takeInput();

    rootNode->left = left;
    rootNode->right = right;

    return rootNode;
}

int main()
{

    BtreeNode<int> *root = takeInput();

    printTree(root);
}
