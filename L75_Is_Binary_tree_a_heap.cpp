#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *TreeFormation(Node *root)
{
    cout << "Enter data : " << endl;
    int data;
    cin >> data;

    root = new Node(data);
    if (data == -1)
        return NULL;

    cout << "Enter data for left node of " << data << endl;
    root->left = TreeFormation(root->left);

    cout << "Enter data for right node of " << data << endl;
    root->right = TreeFormation(root->right);

    return root;
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
    }
}

int TotalNodes(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + TotalNodes(root->left) + TotalNodes(root->right);
}

bool isCBT(Node *root, int i, int CountNodes)
{
    if (root == NULL)
        return true;

    if (i >= CountNodes)
        return false;

    else
    {
        bool left = isCBT(root->left, 2 * i + 1, CountNodes);
        bool right = isCBT(root->right, 2 * i + 2, CountNodes);

        return (left && right);
    }
}

bool isMaxHeap(Node *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->right == NULL)
        return (root->data > root->left->data);

    else
    {
        bool a = root->data > root->left->data;
        bool b = root->data > root->right->data;
        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);
        return (a && b && left && right);
    }
}

int main()
{
    Node *tree = NULL;
    tree = TreeFormation(tree);
    LevelOrderTraversal(tree);

    int nodes = TotalNodes(tree);

    if ((isCBT(tree, 0, nodes) && isMaxHeap(tree)))
        cout << "YES , Binary tree is a heap." << endl;
    else
        cout << "NO , Binary tree is not a heap." << endl;
    return 0;
}

// 5 2 -1 -1 3 -1 -1
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1