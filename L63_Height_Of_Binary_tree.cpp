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

Node *TreeFormation(Node *rootNode)
{
    cout << "Enter data : " << endl;
    int data;
    cin >> data;

    rootNode = new Node(data);

    if (data == -1)
        return NULL;

    cout << "For left root node of " << data << endl;
    rootNode->left = TreeFormation(rootNode->left);
    cout << "For right root node of " << data << endl;
    rootNode->right = TreeFormation(rootNode->right);
    return rootNode;
}

void levelOrderTraversal(Node *root)
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

int Height(Node *root)
{
    if (root == NULL)
        return 0;   

    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    return max(leftHeight , rightHeight) + 1;
}

int main()
{
    Node *firstBinaryTree = NULL;
    firstBinaryTree = TreeFormation(firstBinaryTree);
    levelOrderTraversal(firstBinaryTree);
    cout<<"Height of Binary tree : "<<Height(firstBinaryTree);
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1