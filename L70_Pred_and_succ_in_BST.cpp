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

pair<int, int> PredecessorSuccessor(Node *root, int key)
{
    Node *temp = root;
    int p = -1, s = -1;
    while (temp->data != key)
    {
        if (temp->data > key)
        {
            s = temp->data;
            temp = temp->left;
        }
        else
        {
            p = temp->data;
            temp = temp->right;
        }
    }

    Node *leftAns = temp->left;
    while (leftAns != NULL)
    {
        p = leftAns->data;
        leftAns = leftAns->right;
    }

    Node *rightAns = temp->right;
    while (rightAns != NULL)
    {
        s = rightAns->data;
        rightAns = rightAns->left;
    }

    return {p, s};
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    getData(root);
    cout << "The Level Order Traversal of BST is : " << endl;
    LevelOrderTraversal(root);
    int key = 161;
    pair<int, int> ans = PredecessorSuccessor(root, key);
    cout << "The Pred and Succ of " << key << " are " << ans.first << " and " << ans.second << " respectively" << endl;
    return 0;
}
// 4 2 5 1 3 -1
// 103 153  161  174  195  200 -1
