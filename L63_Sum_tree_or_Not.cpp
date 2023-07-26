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

pair<bool,int> CheckSumTree(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = CheckSumTree(root->left);
    pair<bool, int> rightAns = CheckSumTree(root->right);

    bool condition = root->data == leftAns.second + rightAns.second;

    pair<bool, int> ans;

    if (leftAns.first && rightAns.first && condition)
    {
        ans.first = true;
        ans.second = root->data + leftAns.second + rightAns.second;
    }
    else
        ans.first= false;
    
    return ans;
}

int main()
{
    Node *BinaryTree = NULL;
    BinaryTree = Tree(BinaryTree);
    LevelOrderTraversal(BinaryTree);

    if (CheckSumTree(BinaryTree).first)
        cout << "Tree is a sum tree" << endl;
    else
        cout << "Tree is not a sum tree" << endl;

    return 0;
}