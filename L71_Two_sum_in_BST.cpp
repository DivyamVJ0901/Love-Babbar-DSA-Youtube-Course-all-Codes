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

void Inorder(Node *root, vector<int> &node)
{
    if (root == NULL)
        return;

    Inorder(root->left, node);
    node.push_back(root->data);
    Inorder(root->right, node);
}

// ITERATIVE SOLUTION
bool TwoSum(Node *root, int target)
{
    vector<int> node;
    Inorder(root, node);
    int i = 0, j = node.size() - 1;

    while (i < j)
    {
        if (node[i] + node[j] == target)
            return true;

        else if (node[i] + node[j] > target)
            j--;

        else
            i++;
    }
    return false;
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    getData(root);
    cout << "The Level Order Traversal of BST is : " << endl;
    LevelOrderTraversal(root);

    cout << "Enter target sum : " << endl;
    int sum;
    cin >> sum;
    if (TwoSum(root, sum))
        cout << "YES YES" << endl;
    else
        cout << "No NO" << endl;
    return 0;
}
// 10 6 12 2 8 11 15 -1