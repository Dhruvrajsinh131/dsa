#include <iostream>
using namespace std;
#include "btreeNode.h"
#include <queue>

BtreeNode<int> *takeInputLevelWise()
{

    int rootData;
    cout << "Enter RootData" << endl;
    cin >> rootData;

    if (rootData == -1)
    {
        return nullptr;
    }

    BtreeNode<int> *root = new BtreeNode(rootData);

    queue<BtreeNode<int> *> pendingNodes;

    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BtreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter Left Child for " << front->data << " : ";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BtreeNode<int> *leftchild = new BtreeNode(leftChildData);
            front->left = leftchild;
            pendingNodes.push(leftchild);
        }
        cout << "Enter Right Child for " << front->data << " : ";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BtreeNode<int> *rightChild = new BtreeNode(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root;
}

void printBTree(BtreeNode<int> *root)
{
    if (!root)
        return;

    cout << root->data << "-> ";

    if (root->left)
    {
        cout << root->left->data;
    }

    if (root->right)
    {
        cout << "<->" << root->right->data;
    }
    cout << endl;
    printBTree(root->left);
    printBTree(root->right);
}

void printTreeLevelWise(BtreeNode<int> *root)
{
    if (!root)
        return;

    queue<BtreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {

        BtreeNode<int> *front = pendingNodes.front();

        cout << front->data << ":";
        cout << "LEFT:";
        if (front->left && front->left->data)
        {
            cout << front->left->data;
        }
        else
            cout << "-1";
        cout << ",";
        cout << "RIGHT:";
        if (front->right && front->right->data)
        {
            cout << front->right->data;
        }
        else
            cout << "-1";

        cout << endl;
        pendingNodes.pop();
        printTreeLevelWise(front->left);
        printTreeLevelWise(front->right);
    }
}
void mirrorTree(BtreeNode<int> *root)
{
    if (!root)
    {
        return;
    }

    BtreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

int countNodes(BtreeNode<int> *root)
{
    if (root == nullptr)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int heightOfTree(BtreeNode<int> *root)
{
    if (root == nullptr)
        return 0;

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return 1 + max(leftHeight, rightHeight);
}

void preorderTraversal(BtreeNode<int> *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(BtreeNode<int> *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(BtreeNode<int> *root)
{
    if (root == nullptr)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    BtreeNode<int> *root = takeInputLevelWise();
    // printBTree(root);
    // printTreeLevelWise(root);
    // mirrorTree(root);
    // printTreeLevelWise(root);

    // cout << "Node Count = " << countNodes(root) << " ";
    // cout << "Height of tree = " << heightOfTree(root) << " ";

    printBTree(root);
    preorderTraversal(root);
    cout << endl;
    // inorderTraversal(root);
    postorderTraversal(root);
}