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

// RECURSIVE SOLUTION
bool SearchInBST_first(Node *root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    else if (root->data > key)
        return SearchInBST_first(root->left, key);

    else
        return SearchInBST_first(root->right, key);
}

// ITERATIVE SOLUTION
bool SearchInBST_second(Node *root, int key)
{
    Node *temp = root;
    while (temp != NULL)
    {
        if (root->data == key)
            return true;
        else if (root->data > key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return true;
}

int main()
{
    cout << "Enter data to construct a BST : " << endl;
    Node *BST = NULL;
    getData(BST);
    cout << "The level order traversal is : " << endl;
    LevelOrderTraversal(BST);
    int key1 = 25;
    if (SearchInBST_first(BST, key1))
        cout << key1 << " is present." << endl;
    else
        cout << key1 << " is absent." << endl;

    int key2 = 15;
    if (SearchInBST_second(BST, key2))
        cout << key2 << " is present." << endl;
    else
        cout << key2 << " is absent." << endl;
    return 0;
}
// 21 10 50 5 15 40 60 55 70 -1