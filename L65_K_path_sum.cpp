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

void Solve(Node *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
        return;

    path.push_back(root->data);

    Solve(root->left, k, count, path);
    Solve(root->right, k, count, path);

    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum += path[i];
        if (k == sum)
            count++;
    }
    path.pop_back();
}

int Ksum(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    Solve(root, k, count, path);
    return count;
}

int main()
{
    Node *BT = NULL;
    BT = TreeFormation(BT);
    LevelOrderTraversal(BT);
    cout << "The numeber of k sums are : " << Ksum(BT, 5);
    return 0;
}
// 1 3 2 -1 -1 1 1 -1 -1 -1 0 5 1 -1 -1 2 -1 -1 5 -1 6 -1 -1