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

bool BSTorNot(Node *root, int min, int max)
{
    // base case
    if (root == NULL)
        return true;

    if (root->data >= min && root->data <= max)
    {
        bool leftAns = BSTorNot(root->left, min, root->data);   // min vahi rehta hai but max ab root ke data ke equal ho jaata hai
        bool rightAns = BSTorNot(root->right, root->data, max); // max vahi rehta hai but min ab root ke data ke equal ho jaata hai
        return leftAns && rightAns;
    }
        
        return false;
}

bool ValidateBST(Node *root)
{
    return BSTorNot(root, INT16_MIN, INT16_MAX);
}

int main()
{
    cout<<"Enter data for BST : "<<endl;
    Node *BST = NULL;
    getData(BST);
    cout << "The LOT of BST is : " << endl;
    LevelOrderTraversal(BST);
    if (ValidateBST(BST))
        cout << "Yes , tree is a BST" << endl;
    else
        cout << "No , tree is not a BST " << endl;
    return 0;
}
// 10 5 15 6 20 -1