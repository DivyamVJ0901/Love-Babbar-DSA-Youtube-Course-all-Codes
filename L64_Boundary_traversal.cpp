#include <iostream>
#include <vector>
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

void LeftTraversal(Node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);

    if (root->left)
        LeftTraversal(root->left, ans);
    else
        LeftTraversal(root->right, ans);
}

void LeafTraversal(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    LeafTraversal(root->left, ans);
    LeafTraversal(root->right, ans);
}

void RightTraversal(Node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        RightTraversal(root->right, ans);
    else
        RightTraversal(root->left, ans);

    ans.push_back(root->data);
}

vector<int> BoundaryTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    LeftTraversal(root->left, ans);
    LeafTraversal(root->left, ans);
    LeafTraversal(root->right, ans);
    RightTraversal(root->right, ans);

    return ans;
}

void Print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    Node *BinaryTree = NULL;
    BinaryTree = TreeFormation(BinaryTree);
    cout << "The level order traversal of entered tree is : " << endl;
    LevelOrderTraversal(BinaryTree);

    vector<int> finalResult = BoundaryTraversal(BinaryTree);
    Print(finalResult);
    return 0;
}
// 1 2 3 -1 -1 5 -1 -1 4 -1 6 8 -1 -1 7 -1 -1