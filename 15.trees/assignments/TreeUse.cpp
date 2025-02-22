#include <iostream>
using namespace std;
#include <queue>
#include "TreeNode.h"

TreeNode<int> *takeTreeInput()
{
    int rootData;
    cout << "Enter the data at root : ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int n;
        cout << "Enter numeber of children for Node = " << front->data << " -> ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int childData;
            cout << "Enter value at index = " << i << "For node = " << front->data << " . ";
            cin >> childData;

            TreeNode<int> *childNode = new TreeNode(childData);

            front->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (!root)
        return;

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "parent -> " << front->data << endl;

        cout << "Children ->  ";

        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " ";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;

        cout << "-----------------------------------------------------" << endl;
    }
}

bool containsX(TreeNode<int> *root, int x)
{
    if (!root)
        return false;

    if (root->data == x)
    {
        return true;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        containsX(root->children[i], x);
    }

    return false;
}

int countGreaterNodes(TreeNode<int> *root, int num)
{
    if (!root)
        return 0;

    int count = 0;

    if (root->data > num)
        count++;

    for (int i = 0; i < root->children.size(); i++)
    {
        count += countGreaterNodes(root->children[i], num);
    }
    return count;
}

// 5 2 4 3 2  2 1 0 0 0

int main()
{
    TreeNode<int> *root = takeTreeInput();

    printTree(root);
    cout << containsX(root, 5) << endl;

    cout << countGreaterNodes(root, 1) << endl;
}