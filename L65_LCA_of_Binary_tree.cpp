#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
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
    int a;
    cin >> a;

    root = new Node(a);

    if (a == -1)
        return NULL;

    cout << "Enter data for left of " << a << endl;
    root->left = TreeFormation(root->left);
    cout << "Enter data for right of " << a << endl;
    root->right = TreeFormation(root->right);
    return root;
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> cheems;
    cheems.push(root);
    cheems.push(NULL);

    while (!cheems.empty())
    {
        Node *temp = cheems.front();

        cheems.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!cheems.empty())
                cheems.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                cheems.push(temp->left);
            if (temp->right)
                cheems.push(temp->right);
        }
    }
}

Node *LCA(Node *root, int node1, int node2)
{
    if (root == NULL)
        return NULL;

    if (root->data == node1 || root->data == node2)
        return root;

    Node *leftAns = LCA(root->left, node1, node2);
    Node *rightAns = LCA(root->right, node1, node2);

    if (leftAns == NULL && rightAns == NULL)
        return NULL;
    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;
    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;
    else
        return root;
}

int main()
{
    Node *BT = NULL;
    BT = TreeFormation(BT);
    LevelOrderTraversal(BT);

    cout << "The Lowest Common Ancestor for 4 and 21 is : " << LCA(BT, 4, 21)->data;
    return 0;
}
// 1 2 6 -1 8 -1 -1 -1 3 4 -1 -1 5 21 -1 -1 -1