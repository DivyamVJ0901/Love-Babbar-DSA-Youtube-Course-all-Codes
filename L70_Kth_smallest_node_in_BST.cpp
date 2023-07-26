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

Node *SetDataForBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
        root->left = SetDataForBST(root->left, data);

    else
        root->right = SetDataForBST(root->right, data);

    return root;
}

void getData(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = SetDataForBST(root, data);
        cin >> data;
    }
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

int solve(Node *root, int &i, int k)
{
    // base case
    if (root == NULL)
        return -1;

    int left = solve(root->left, i, k);

    if (left != -1)
        return left;

    i++;
    if (i == k)
        return root->data;

    return solve(root->right, i, k);
}

int kthSmallest(Node *root, int i, int k)
{
    i = 0, k = 3;
    int ans = solve(root, i, k);
    return ans;
}


int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    getData(root);
    cout << "The Level Order Traversal of BST is : " << endl;
    LevelOrderTraversal(root);
    int i = 0, k = 3;
    cout << "The " << k << "th smallest value of BST is : " << kthSmallest(root, i, k);
    return 0;
}
// 5 4 8 2 6 10 3 7 -1
