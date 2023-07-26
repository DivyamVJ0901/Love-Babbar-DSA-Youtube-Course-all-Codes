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

void Inorder(Node *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(Node *root)
{
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    getData(root);
    cout << "The Level Order Traversal of BST is : " << endl;
    LevelOrderTraversal(root);
    cout << "The Inorder Traversal of BST is : " << endl;
    Inorder(root);
    cout << endl;
    cout << "The Preorder Traversal of BST is : " << endl;
    Preorder(root);
    cout << endl;
    cout << "The Postorder Traversal of BST is : " << endl;
    Postorder(root);
    return 0;
}
// 10 8 21 7 27 5 4 3 -1
// 50 30 60 20 40 70 80 -1
