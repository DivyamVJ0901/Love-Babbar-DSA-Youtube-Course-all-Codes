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

Node *Tree(Node *root)
{
    cout << "Enter data : " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for left of " << data << left << endl;
    root->left = Tree(root->left);
    cout << "Enter data for right of " << data << right << endl;
    root->right = Tree(root->right);
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

// FOR TIME COMPLEXITY : O(n)
pair<bool, int> isBalanced(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = isBalanced(root->left);
    pair<bool, int> right = isBalanced(root->right);

    bool FirstOpt = left.first;
    bool SecondOpt = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> finalAns;
    finalAns.second = max(left.second, right.second) + 1;

    if (FirstOpt && SecondOpt && diff)
        finalAns.first = true;
    else
        finalAns.first = false;

    return finalAns;
}

// FOR TIME COMPLEXITY : O(n^2)
int Height(Node *root)
{
    if (root == NULL)
        return 0;

    int left = Height(root->left);
    int right = Height(root->right);

    return max(left, right) + 1;
}

bool BalancedOrNot(Node *root)
{
    if (root == NULL)
        return true;
    bool left = BalancedOrNot(root->left);
    bool right = BalancedOrNot(root->right);

    bool diffrence = abs(Height(root->left) - Height(root->right)) <= 1;

    if (left && right && diffrence)
        return true;
    else
        return false;
}

int main()
{
    Node *BT = NULL;
    BT = Tree(BT);
    LevelOrderTraversal(BT);

    if (isBalanced(BT).first)
        cout << "Tree is balanced in time complexity O(n)" << endl;
    else
        cout << "Tree is not balanced in time complexity O(n)" << endl;

    if (BalancedOrNot(BT))
        cout << "Tree is balanced in time complexity O(n^2)" << endl;
    else
        cout << "Tree is not balanced in time complexity O(n^2)" << endl;

    return 0;
}