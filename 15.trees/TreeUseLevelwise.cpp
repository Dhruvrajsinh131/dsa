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

void printAtLevelk(TreeNode<int> *root, int k)
{
    if (root == nullptr)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << endl;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelk(root->children[i], k - 1);
    }
}

int findHeight(TreeNode<int> *root)
{
    int maxHeight = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        maxHeight = max(maxHeight, findHeight(root->children[i]));
    }

    return maxHeight + 1;
}

int countOfLeafNodes(TreeNode<int> *root)
{
    if (root == nullptr)
        return 0;

    if (root->children.empty())
    {
        return 1;
    }

    int leafCount = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        leafCount += countOfLeafNodes(root->children[i]);
    }

    return leafCount;
}

void preOrderTraverse(TreeNode<int> *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";

    for (int i = 0; i < root->children.size(); i++)
    {
        preOrderTraverse(root->children[i]);
    }
}

void postOrder(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }

    cout << root->data << " ";
}

// This is way 1 of doing it
void deleteTree(TreeNode<int> *root)
{

    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }

    delete root;
}

// 5 2 4 3 2 2 1 0 0 0

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);

    cout << endl;

    cout << "Total Nodes = " << nodeCount(root) << endl;
    cout << "Sum Of All Nodes = " << sumOfAllNodes(root) << endl;
    cout << "Largest Node = " << getLargestNode(root) << endl;
    cout << "Height Of a tree = " << findHeight(root) << endl;
    printAtLevelk(root, 1);
    cout << "Total count of leaf Nodes of the tree = " << countOfLeafNodes(root) << endl;

    cout << "Preorder = ";
    preOrderTraverse(root);
    cout << endl;

    cout << "Postorder = ";

    postOrder(root);
    cout << endl;

    // way 1
    // deleteTree(root);

    // way 2
    // using destructor
    delete root;
}