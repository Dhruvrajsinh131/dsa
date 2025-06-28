#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class BtreeNode
{

public:
    T data;
    BtreeNode *left;
    BtreeNode *right;

    BtreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

BtreeNode<int> *takeInput()
{
    int root;
    cout << "Enter the root Value : ";
    cin >> root;

    if (root == -1)
    {
        return nullptr;
    }

    BtreeNode<int> *rootNode = new BtreeNode<int>(root);

    queue<BtreeNode<int> *> pendingNodes;

    pendingNodes.push(rootNode);

    while (!pendingNodes.empty())
    {
        BtreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        // Get input for left child
        cout << "Enter the left child for " << front->data << " : ";
        int leftChildData;
        cin >> leftChildData;

        if (leftChildData != -1)
        {
            BtreeNode<int> *leftChild = new BtreeNode(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        // Get input for left child

        cout << "Enter right child for " << front->data << " : ";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BtreeNode<int> *rightChild = new BtreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return rootNode;
}

void printTree(BtreeNode<int> *root)
{
    if (!root)
        return;

    cout << root->data << "->";

    if (root->left)
    {
        cout << root->left->data;
    }
    if (root->right)
    {
        cout << "<->" << root->right->data;
    }
    cout << endl;

    printTree(root->left);
    printTree(root->right);
}

void printBtreeLevelWise(BtreeNode<int> *root)
{

    if (!root)
        return;

    queue<BtreeNode<int> *> pendingNodes;

    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BtreeNode<int> *front = pendingNodes.front();

        cout << front->data << " : ";

        cout << "Left : ";
        if (front->left && front->left->data)
        {
            cout << front->left->data;
        }
        else
        {
            cout << "-1";
        }
        cout << ",";
        cout << " Right: ";

        if (front->right && front->right->data)
        {
            cout << front->right->data;
        }
        else
            cout << "-1";

        cout << endl;
        pendingNodes.pop();
        printBtreeLevelWise(front->left);
        printBtreeLevelWise(front->right);
    }
}

int main()
{

    BtreeNode<int> *root = takeInput();

    printBtreeLevelWise(root);
}