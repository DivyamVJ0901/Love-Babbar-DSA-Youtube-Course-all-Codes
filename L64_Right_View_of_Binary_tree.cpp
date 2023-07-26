#include <iostream>
#include <queue>
#include <vector>
#include <map>
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

void Solve(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);

    // RIGHT VIEW KE CASE ME RIGHT WAALI CALL PEHLE AAYEGI THEN LEFT KI CALL
    Solve(root->right, ans, level + 1);
    Solve(root->left, ans, level + 1);
}

vector<int> RightView(Node *root)
{
    vector<int> ans;
    Solve(root, ans, 0);
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
    Node *BT = NULL;
    BT = TreeFormation(BT);
    LevelOrderTraversal(BT);
    cout << "The Left view of given tree is : " << endl;
    Print(RightView(BT));
    return 0;
}

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 8 -1 -1