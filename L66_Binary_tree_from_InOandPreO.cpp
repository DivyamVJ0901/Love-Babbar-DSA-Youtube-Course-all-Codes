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

Node *Solve(int InOrder[], int PreOrder[], int n, int &index, int IOstart, int IOend, map<int, int> NodesToIndex)
{
    if (index >= n || IOstart > IOend)
        return NULL;

    // Create a root node for element
    int element = PreOrder[index++];
    Node *root = new Node(element);

    // Find element's position in inorder
    int p = NodesToIndex[element];

    // Recursive calls
    // preorder ke case me left ki call pehle aayegi right se
    root->left = Solve(InOrder, PreOrder, n, index, IOstart, p - 1, NodesToIndex); 
    root->right = Solve(InOrder, PreOrder, n, index, p + 1, IOend, NodesToIndex);
    
    return root;
}

Node *TreefromIOandPreO(int InOrder[], int PreOrder[], int n)
{
    int index = 0;
    map<int, int> NodesToIndex;
    CreateMapping(InOrder, NodesToIndex, n);
    return Solve(InOrder, PreOrder, n, index, 0, n - 1, NodesToIndex);
}

void PostOrder(Node *root)
{
    if (root == NULL)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    int InO[6] = {3, 1, 4, 0, 5, 2};
    int PreO[6] = {0, 1, 3, 4, 2, 5};
    cout << "PostOrder Traversal from PreO and InO : " << endl;
    PostOrder(TreefromIOandPreO(InO, PreO, 6));
    cout << endl;
    cout << "Level Order Traversal of tree is : " << endl;
    LevelOrderTraversal(TreefromIOandPreO(InO, PreO, 6));
    return 0;
}