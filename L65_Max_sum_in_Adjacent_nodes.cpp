#include <iostream>
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

pair<int, int> Solve(Node *&root)
{
    if (root == NULL)
        pair<int, int> p = make_pair(0, 0);

    pair<int, int> leftAns = Solve(root->left);
    pair<int, int> rightAns = Solve(root->right);

    pair<int, int> temp;

    temp.first = root->data + leftAns.second + rightAns.second;
    temp.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

    return temp;
}

int MaxSumAdjNodes(Node *root)
{
    pair<int, int> ans = Solve(root);
    return max(ans.first,ans.second);
}

int main()
{
    Node *BinaryTree = NULL;
    BinaryTree = TreeFormation(BinaryTree);
    LevelOrderTraversal(BinaryTree);
    cout << "The max sum of Adjacent nodes is : " << MaxSumAdjNodes(BinaryTree) << endl;
    return 0;
}
// 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1