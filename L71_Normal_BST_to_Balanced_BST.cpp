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

void Inorder(Node *root, vector<int> &arr)
{
    if (root == NULL)
        return;

    Inorder(root->left, arr);
    arr.push_back(root->data);
    Inorder(root->right, arr);
}

// BST from Inorder Traversal
Node *InorderToBST(int s, int e, vector<int> &arr)
{
    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;

    Node *newR = new Node(arr[mid]);
    newR->left = InorderToBST(s, mid - 1, arr);
    newR->right = InorderToBST(mid + 1, e, arr);

    return newR;
}

Node *BalancedBST(Node *root)
{
    vector<int> arr;
    Inorder(root, arr);

    return InorderToBST(0, arr.size() - 1, arr);
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    getData(root);
    cout << "The Level Order Traversal of Normal BST is : " << endl;
    LevelOrderTraversal(root);

    cout << "The Level Order Traversal of Balanced BST is : " << endl;
    Node *ans = BalancedBST(root);
    LevelOrderTraversal(ans);

    return 0;
}
// 50 30 60 20 40 70 80 -1
