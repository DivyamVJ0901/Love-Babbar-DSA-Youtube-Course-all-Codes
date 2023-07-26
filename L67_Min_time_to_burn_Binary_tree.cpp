#include <iostream>
#include <vector>
#include <queue>
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

Node *ParentMapping(Node *root, int target, map<Node *, Node *> &NodesToParent)
{
    Node *result = NULL;

    queue<Node *> king;
    king.push(root);

    while (!king.empty())
    {
        Node *front = king.front();
        king.pop();

        if (front->data == target)
            result = front;

        if (front->left)
        {
            NodesToParent[front->left] = front;
            king.push(front->left);
        }

        if (front->right)
        {
            NodesToParent[front->right] = front;
            king.push(front->right);
        }
    }
    return result;
}

int BurnTree(Node *root, map<Node *, Node *> NodesToParent)
{
    int time = 0;
    map<Node *, bool> visited;
    queue<Node *> hitman;

    hitman.push(root);
    visited[root] = true;

    while (!hitman.empty())
    {
        bool flag = 0;
        for (int i = 0; i < hitman.size(); i++)
        {
            Node *front = hitman.front();
            hitman.pop();

            if (front->left && !visited[front->left])
            {
                flag = 1;
                hitman.push(front->left);
                visited[front->left] = 1;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                hitman.push(front->right);
                visited[front->right] = 1;
            }
            if (NodesToParent[front] && !visited[NodesToParent[front]])
            {
                flag = 1;
                hitman.push(NodesToParent[front]);
                visited[NodesToParent[front]] = 1;
            }
        }
        if (flag == 1)
            time++;
    }
    return time;
}

int minTime(Node *root, int target)
{
    map<Node *, Node *> NodesToParent;
    Node *targetNode = ParentMapping(root, target, NodesToParent);
    int ans = BurnTree(targetNode, NodesToParent);
    return ans;
}

int main()
{
    Node *tree = NULL;
    tree = TreeFormation(tree);
    LevelOrderTraversal(tree);
    int Target = 8;
    cout << "The minimum time to burn tree if we start from " << Target << " is : " << minTime(tree, Target);
    return 0;
}
// 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1