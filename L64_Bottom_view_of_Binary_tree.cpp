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

vector<int> BottomView(Node *root)
{
    vector<int> temp;
    if (root == NULL)
        return temp;

    map<int, int> bottomView;

    queue<pair<Node *, int>> que;
    que.push(make_pair(root, 0));

    while (!que.empty())
    {
        pair<Node *, int> p = que.front();
        que.pop();
        Node *frontNode = p.first;
        int HorizontalDist = p.second;

        bottomView[HorizontalDist] = frontNode->data;

        if (frontNode->left)
            que.push(make_pair(frontNode->left, HorizontalDist - 1));
        if (frontNode->right)
            que.push(make_pair(frontNode->right, HorizontalDist + 1));
    }

    for (auto i : bottomView)
        temp.push_back(i.second);
    return temp;
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
    cout << "The Bottom view of given tree is : " << endl;
    Print(BottomView(BT));
    return 0;
}

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1