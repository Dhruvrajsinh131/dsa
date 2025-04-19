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
int search(int inorder[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

BtreeNode<int> *buildTreeHelper(int preorder[], int inorder[], int &preIndex, int inStart, int inEnd)
{
    if (inStart > inEnd)
    {
        return nullptr;
    }

    int rootVal = preorder[preIndex++];
    BtreeNode<int> *root = new BtreeNode(rootVal);

    int inIndex = search(inorder, inStart, inEnd, rootVal);

    root->left = buildTreeHelper(preorder, inorder, preIndex, inStart, inIndex - 1);
    root->right = buildTreeHelper(preorder, inorder, preIndex, inIndex + 1, inEnd);

    return root;
}

pair<int, int> heightDiameter(BtreeNode<int> *root)
{
    if (!root)
    {
        return {0, 0};
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);

    int diameter = max(lh + rh, max(ld, rd));

    return {height, diameter};
}

BtreeNode<int> *buildTree(int preorder[], int inorder[], int n)
{
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, preIndex, 0, n - 1);
}

int main()
{
    BtreeNode<int> *root = takeInputLevelWise();

    printBTree(root);
    int ansHeight = heightDiameter(root).first;
    int ansDiametter = heightDiameter(root).second;
    cout << ansHeight << endl;

    cout << ansDiametter << endl;
}