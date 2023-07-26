#include <iostream>
#include <vector>
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

Node *Tree(Node *root)
{
    cout << "Enter data : " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for left of " << data << left << endl;
    root->left = Tree(root->left);
    cout << "Enter data for right of " << data << right << endl;
    root->right = Tree(root->right);
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

bool CheckTreesEqual(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 != NULL ||  root2 != NULL)
        return false;

    bool leftTree = CheckTreesEqual(root1->left, root2->left);
    bool rightTree = CheckTreesEqual(root1->right, root2->right);

    bool val = root1->data == root2->data;

    if (leftTree && rightTree && val)
        return true;
    else
        return false;
}

int main()
{
    Node *tree1 = NULL;
    Node *tree2 = NULL;

    tree1 = Tree(tree1);
    tree2 = Tree(tree2);

    LevelOrderTraversal(tree1);
    LevelOrderTraversal(tree2);

    if (CheckTreesEqual(tree1, tree2))
        cout << "Trees are equal" << endl;
    else
        cout << "Trees are not equal" << endl;
    return 0;
}

// 1 2 -1 -1 3 -1 -1
// 1 2 3 -1 -1 -1 -1