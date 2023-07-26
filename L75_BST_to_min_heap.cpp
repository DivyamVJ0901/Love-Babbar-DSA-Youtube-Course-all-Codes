#include <iostream>
#include <vector>
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

vector<int> *BSTtoInorder(Node *root, vector<int> inO)
{
    if (root == NULL)
        return NULL;

    BSTtoInorder(root->left, inO);
    inO.push_back(root->data);
    BSTtoInorder(root->right, inO);
}


void Preorder(Node*temp , vector<int> ans , int index)
{
    
}

int main()
{

    return 0;
}