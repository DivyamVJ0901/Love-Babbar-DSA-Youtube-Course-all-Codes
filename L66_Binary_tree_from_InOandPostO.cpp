#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    Node *left = NULL;
    Node *right = NULL;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
    }
};

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

// MOST OPTIMIZED APPROACH
void CreateMapping(int InOrder[], map<int, int> &NodesToIndex, int n)
{
    for (int i = 0; i < n; i++)
        NodesToIndex[InOrder[i]] = i;
}

Node *Solve(int InOrder[], int PostOrder[], int n, int index, int IOstart, int IOend, map<int, int> NodesToIndex)
{
    if (index < 0 || IOstart > IOend)
        return NULL;

    // Create a root node for element
    int element = PostOrder[index--]; // Post Order ke case me index decrement hota h
    Node *root = new Node(element);

    // Find element's position in inorder
    int p = NodesToIndex[element];

    // Recursive calls
    // Post order ke case me right ki call pehle aati hai left se
    root->right = Solve(InOrder, PostOrder, n, index, p + 1, IOend, NodesToIndex);
    root->left = Solve(InOrder, PostOrder, n, index, IOstart, p - 1, NodesToIndex);

    return root;
}

Node *TreefromIOandPostO(int InOrder[], int PostOrder[], int n)
{
    int index = n - 1;
    map<int, int> NodesToIndex;
    CreateMapping(InOrder, NodesToIndex, n);
    return Solve(InOrder, PostOrder, n, index, 0, n - 1, NodesToIndex);
}

void PreOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

int main()
{
    int InO[8] = {4, 8, 2, 5, 1, 6, 3, 7};
    int PostO[8] = {8, 4, 5, 2, 6, 7, 3, 1};
    cout << "Preorder Traversal from PreO and InO : " << endl;
    PreOrder(TreefromIOandPostO(InO, PostO, 8));
    cout << endl;
    cout << "Level Order Traversal of tree is : " << endl;
    LevelOrderTraversal(TreefromIOandPostO(InO, PostO, 8));
    return 0;
}