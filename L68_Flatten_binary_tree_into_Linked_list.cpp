#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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

void FlattenTree(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left)
        {
            Node *predecessor = curr->left;
            while (predecessor->right)
                predecessor = predecessor->right;

            predecessor->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void PrintLL(Node *node)
{
    Node *temp = node;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
        if (temp == NULL)
            cout << "NULL";
    }
    cout << endl;
}

int main()
{
    Node *tree = NULL;
    tree = TreeFormation(tree);
    LevelOrderTraversal(tree);
    FlattenTree(tree);
    PrintLL(tree);
    return 0;
}
// 7 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1