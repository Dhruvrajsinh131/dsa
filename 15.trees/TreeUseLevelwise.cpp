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

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
}