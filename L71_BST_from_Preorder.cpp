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

Node *Solve(vector<int> &GivenArr, int min, int max, int &i)
{
    if (i >= GivenArr.size())
        return NULL;

    if (GivenArr[i] < min || GivenArr[i] > max)
        return NULL;

    Node *root = new Node(GivenArr[i++]);

    root->left = Solve(GivenArr, min, root->data, i);
    root->right = Solve(GivenArr, root->data, max, i);

    return root;
}

Node *PreorderToBST(vector<int> &preorder)
{
    int i = 0;
    return Solve(preorder, INT16_MIN, INT16_MAX, i);
}

void PrintArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> preorder = {20, 10, 5, 15, 13, 35, 30, 40};
    cout << "The enterd Preorder traversal : ";
    PrintArray(preorder);
    Node *ans = PreorderToBST(preorder);
    cout << "The BST is : " << endl;
    LevelOrderTraversal(ans);
    return 0;
}
// 20 10 5 15 13 35 30 40
