#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

TreeNode<int> *takeTreeInput()
{
    int rootData;
    cout << "Enter the data at root: ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int n;
        cout << "Enter number of children for Node = " << front->data << " -> ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int childData;
            cout << "Enter value at index = " << i << " for node = " << front->data << ": ";
            cin >> childData;

            TreeNode<int> *childNode = new TreeNode<int>(childData);
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

pair<TreeNode<int> *, int> maxChildSumNodeHelper(TreeNode<int> *root)
{
    if (!root)
        return {nullptr, 0};

    int currentSum = root->data;
    for (TreeNode<int> *child : root->children)
    {
        currentSum += child->data;
    }

    TreeNode<int> *maxNode = root;
    int maxSum = currentSum;

    for (TreeNode<int> *child : root->children)
    {
        pair<TreeNode<int> *, int> childResult = maxChildSumNodeHelper(child);
        if (childResult.second > maxSum)
        {
            maxSum = childResult.second;
            maxNode = childResult.first;
        }
    }

    return {maxNode, maxSum};
}

TreeNode<int> *maxChildSumNode(TreeNode<int> *root)
{
    return maxChildSumNodeHelper(root).first;
}

// 5 2 4 3 2  2 1 0 0 0

int main()
{
    TreeNode<int> *root = takeTreeInput();
    TreeNode<int> *maxNode = maxChildSumNode(root);

    if (maxNode)
        cout << "Node with maximum child sum: " << maxNode->data << endl;

    return 0;
}
