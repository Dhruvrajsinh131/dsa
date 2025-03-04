#include <iostream>
using namespace std;
#include "TreeNode.h"

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data : ";
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter the number of nodes for : Node = " << rootData;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

void printTree(TreeNode<int> *root)
{

    if (!root)
        return;

    cout << root->data << " -> ";

    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ";
    }

    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{

    TreeNode<int> *root = takeInput();
    printTree(root);
}