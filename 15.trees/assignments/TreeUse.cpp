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

// Assignment 2
pair<TreeNode<int> *, int> maxChildSumNodeHelper(TreeNode<int> *root)
{
    if (!root)
        return {nullptr, 0};

    int currentSum = root->data;
    for (TreeNode<int> *child : root->children)
    {
        currentSum += child->data;
    }

    int maxSum = currentSum;
    TreeNode<int> *maxNode = root;

    for (TreeNode<int> *child : root->children)
    {
        pair<TreeNode<int> *, int> childPair = maxChildSumNodeHelper(child);

        if (childPair.second > maxSum)
        {
            maxSum = childPair.second;
            maxNode = childPair.first;
        }
    }

    return {maxNode, maxSum};
}

TreeNode<int> *maxChildSumNode(TreeNode<int> *root)
{
    return maxChildSumNodeHelper(root).first;
}

// Assignment 4
bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    if (root1->data != root2->data)
        return false;
    if (root1->children.size() != root2->children.size())
        return false;

    for (int i = 0; i < root1->children.size(); i++)
    {
        if (!areIdentical(root1->children[i], root2->children[i]))
        {
            return false;
        }
    }

    return true;
}

int nextLarger(TreeNode<int> *root, int x)
{
    if (!root)
        return -1;

    int ans = -1;

    if (root->data > x)
    {
        ans = root->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        int temp = nextLarger(root->children[i], x);

        if (temp > x)
        {
            ans = temp;
        }
    }

    return ans;
}

// 5 2 4 3 2  2 1 0 0 0

int main()
{
    TreeNode<int> *root1 = takeTreeInput();
    // TreeNode<int> *root2 = takeTreeInput();
    // TreeNode<int> *maxNode = maxChildSumNode(root1);

    // if (maxNode)
    //     cout << "Node with maximum child sum: " << maxNode->data << endl;

    // cout << "Are trees Identical ?? " << areIdentical(root1, root2);

    cout << endl;
    cout << " Value = " << nextLarger(root1, 4);
}
