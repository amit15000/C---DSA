#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int val)
    {
        data = val;
    }
};
Node *createTree()
{
    int val;
    cout << "Enter the value" << endl;
    cin >> val;

    if (val == -1)
    {
        return nullptr;
    }
    Node *newNode = new Node(val);
    // left child
    cout << "Left child of the " << newNode->data << endl;
    newNode->left = createTree();

    // left child
    cout << "Right child of the " << newNode->data << endl;
    newNode->right = createTree();
}
void preOrderTraversal(Node *root)
{
    // Root Left Right
    if (root == nullptr)
    {
        return;
    }
    // current
    cout << root->data << " ";
    // left child
    preOrderTraversal(root->left);
    // right child
    preOrderTraversal(root->right);
}
void InOrderTraversal(Node *root)
{
    // Left Root Right
    if (root == nullptr)
        return;

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}
void PostOrderTraversal(Node *root)
{
    // Left Right Root
    if (root == nullptr)
        return;

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = createTree();

    cout << "Pre Order : ";
    preOrderTraversal(root);
    cout << endl;
    cout << "In Order : ";
    InOrderTraversal(root);
    cout << endl;
    cout << "Post Order : ";
    PostOrderTraversal(root);
    cout << endl;
}
