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

Node *TreeFormation(Node *rootNode)
{
    cout << "Enter data : " << endl;
    int data;
    cin >> data;

    rootNode = new Node(data);

    if (data == -1)
        return NULL;

    cout << "For left root node of " << data << endl;
    rootNode->left = TreeFormation(rootNode->left);
    cout << "For right root node of " << data << endl;
    rootNode->right = TreeFormation(rootNode->right);
    return rootNode;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> cheems;
    cheems.push(root);
    cheems.push(NULL);

    while (!cheems.empty())
    {
        Node *temp = cheems.front();
        cheems.pop();

        if (temp == NULL) // Pehla level complete ho chuka hai
        {
            cout << endl;
            if (!cheems.empty()) // Queue abhi bhi empty hai
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

void TreeFormationByLOT(Node *root)
{
    queue<Node *> q;
    cout << "Enter root data : " << endl;
    int data;
    cin >> data;

    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter left data for " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right data for " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
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

void Print(vector<vector<Node*>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
            cout << arr[j][i] << " ";
        cout << endl;
    }
}

int main()
{
    Node *root = NULL;
    TreeFormationByLOT(root);
    cout << "The Level order Traversal of given tree is : " << endl;
    levelOrderTraversal(root);

    cout << "The Inorder Traversal of given tree is : ";
    Inorder(root);
    cout << endl;

    cout << "The Preorder Traversal of given tree is : ";
    Preorder(root);
    cout << endl;

    cout << "The Postorder Traversal of given tree is : ";
    Postorder(root);
    cout << endl;
    return 0;
}

// 1 2 -1 3 4 6 5 -1 -1 -1 -1 -1 -1
// 1 2 3 6 -1 -1 5 -1 -1 4 -1 -1 -1
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
// 1 3 1 2 -1 1 2 2 4 -1 3 2 1 1 -1 1 1 3 1 -1 1 2 2 1
