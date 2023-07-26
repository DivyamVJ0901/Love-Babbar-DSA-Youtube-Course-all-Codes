#include <iostream>
#include <queue>
#include <vector>
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

void Solve(Node *root, int len, int &maxLen, int sum, int &maxSum)
{
    if (root == NULL)
        return;

    if (len > maxLen)
    {
        maxLen = len;
        maxSum = sum;
    }
    else if (len == maxLen)
        maxSum = max(sum, maxSum);

    sum += root->data;

    Solve(root->left, len + 1, maxLen, sum, maxSum);
    Solve(root->right, len + 1, maxLen, sum, maxSum);
}

int SumToLongestPath(Node *root)
{
    int len = 0, maxLen = 0, sum = 0, maxSum = INT16_MIN;
    Solve(root, len, maxLen, sum, maxSum);
    return maxSum;
}

int main()
{
    Node *BT = NULL;
    BT = TreeFormation(BT);
    LevelOrderTraversal(BT);
    cout << "The sum of all the nodes in the longest path is : " << SumToLongestPath(BT) << endl;
    return 0;
}
// 4 2 7 -1 -1 1 6 -1 -1 -1 5 2 -1 -1 3 -1 -1