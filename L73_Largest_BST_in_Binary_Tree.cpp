#include <iostream>
using namespace std;

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

class info
{
public:
    int maxi;
    int mini;
    int size;
    int sum;
    bool BST_or_Not;
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
    cout << "Enter data for BST : " << endl;
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
    cout << "The level order traversal is : " << endl;
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

info Solve(Node *root, int &ans, int &sum)
{
    if (root == NULL)
        return {INT16_MIN, INT16_MAX, 0, 0, true};

    info leftSubTree = Solve(root->left, ans, sum);
    info rightSubTree = Solve(root->right, ans, sum);

    info currNode;
    currNode.maxi = max(root->data, rightSubTree.maxi);
    currNode.mini = min(root->data, leftSubTree.mini);
    currNode.size = leftSubTree.size + rightSubTree.size + 1;
    currNode.sum = leftSubTree.sum + rightSubTree.sum + root->data;

    if (leftSubTree.BST_or_Not && rightSubTree.BST_or_Not && (leftSubTree.maxi < root->data && rightSubTree.mini > root->data))
        currNode.BST_or_Not = true;
    else
        currNode.BST_or_Not = false;

    if (currNode.BST_or_Not)
        ans = max(ans, currNode.size);

    if (currNode.BST_or_Not)
        sum = max(sum, currNode.sum);

    return currNode;
}

pair<int, int> maxSize_and_Sum(Node *root)
{
    int maxSum = 0, size = 0;
    Solve(root, size, maxSum);
    return {size, maxSum};
}

int main()
{
    Node *BinaryTree = NULL;
    BinaryTree = TreeFormation(BinaryTree);
    LevelOrderTraversal(BinaryTree);
    pair<int, int> ans = maxSize_and_Sum(BinaryTree);
    cout << "The size of largest BST in Binary Tree is : " << ans.first << endl;
    cout << "The sum of all the nodes in that BST is : " << ans.second << endl;
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1