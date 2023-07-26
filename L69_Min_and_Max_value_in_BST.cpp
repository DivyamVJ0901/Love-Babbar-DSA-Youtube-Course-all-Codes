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

Node *MinValueInBST(Node *&root)
{
    Node *temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

Node *MaxValueInBST(Node *&root)
{
    Node *temp = root;
    while (temp->right != NULL)
        temp = temp->right;
    return temp;
}

int main()
{
    Node *BST = NULL;
    cout << "Enter data to create BST : " << endl;
    getData(BST);
    cout << "The Level Order Traversal of BST is : " << endl;
    LevelOrderTraversal(BST);
    cout << "The Minimum Value of a node in BST is : " << MinValueInBST(BST)->data << endl;
    cout << "The Maximum Value of a node in BST is : " << MaxValueInBST(BST)->data << endl;
    return 0;
}
// 50 20 70 10 30 90 110 -1