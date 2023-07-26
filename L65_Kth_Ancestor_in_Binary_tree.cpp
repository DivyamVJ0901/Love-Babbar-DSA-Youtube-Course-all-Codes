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

Node *Solve(Node *root, int &k, int n)
{
    if (root == NULL)
        return NULL;

    if (root->data == n)
        return root;

    Node *leftAns = Solve(root->left, k, n);
    Node *rightAns = Solve(root->right, k, n);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT16_MAX; // Aisa hamne ans ko lock karne ke liye kiya
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT16_MAX; // Aisa hamne ans ko lock karne ke liye kiya
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int KthAncestor(Node *root, int k, int n)
{
    Node *ans = Solve(root, k, n);
    if (ans == NULL || ans->data == n)
        return -1;
    else
        ans->data;
}
int main()
{
    Node *BinaryTree = NULL;
    BinaryTree = TreeFormation(BinaryTree);
    LevelOrderTraversal(BinaryTree);

    cout << "The 2nd ancestor for 4 is : "<< KthAncestor(BinaryTree, 2, 4);
    return 0;
}
// 9 2 4 -1 -1 5 -1 -1 3 -1 -1