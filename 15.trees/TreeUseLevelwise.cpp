#include <iostream>
using namespace std;
#include "TreeNode.h"
#include <queue>

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root Data : ";
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
            cout << "Enter value at index " << i << "for Node = " << front->data << " -> ";
            cin >> childData;

            TreeNode<int> *childNode = new TreeNode<int>(childData);
            front->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }

    return root;
}

int nodeCount(TreeNode<int> *root)
{

    int count = 1;

    for (int i = 0; i < root->children.size(); i++)
    {
        count += nodeCount(root->children[i]);
    }

    return count;
}

int sumOfAllNodes(TreeNode<int> *root)
{
    int sum = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumOfAllNodes(root->children[i]);
    }

    return sum;
}

int getLargestNode(TreeNode<int> *root)
{
    int largestNode = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        largestNode = max(largestNode, getLargestNode(root->children[i]));
    }

    return largestNode;
}

int findHeight(TreeNode<int> *root)
{

    int maxChildHeight = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        maxChildHeight = max(maxChildHeight, findHeight(root->children[i]));
    }

    return maxChildHeight + 1;
}

void printTreeLevelWise(TreeNode<int> *root)
{
    if (!root)
        return;

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Parent -> " << front->data << endl;

        cout << "Children -> ";

        if (front->children.empty())
        {
            cout << "No Children";
        }
        else
        {

            for (int i = 0; i < front->children.size(); i++)
            {

                cout << front->children[i]->data << " ";
                pendingNodes.push(front->children[i]);
            }
        }

        cout << endl;

        cout << "-----------------------------------------------------" << endl;
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);

    cout << endl;

    cout << "Total Nodes = " << nodeCount(root) << endl;
    cout << "Sum Of All Nodes = " << sumOfAllNodes(root) << endl;
    cout << "Largest Node = " << getLargestNode(root) << endl;
    cout << "Height Of a tree = " << findHeight(root) << endl;
}