// Diameter of Binary Tree : Longest path between any two end nodes and equal to the number of nodes in path 
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

// FOR TIME COMPLEXITY : O(n)
pair<int, int> optimisedDiameter(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0); // the first int in pair represents DIAMETER and second one represents HEIGHT 
        return p;
    }
    pair<int, int> left = optimisedDiameter(root->left);
    pair<int, int> right = optimisedDiameter(root->right);

    int FirstOpt = left.first;
    int SecondOpt = right.first;
    int ThirdOpt = left.second + right.second + 1;

    pair<int, int> finalAns;
    finalAns.first = max(FirstOpt, max(SecondOpt, ThirdOpt));
    finalAns.second = max(left.second, right.second) + 1;

    return finalAns;
}

int Diameter(Node *root)
{
    return optimisedDiameter(root).first;
}

// FOR TIME COMPLEXITY : O(n^2)
int Height(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int Diameter2(Node *root)
{
    if (root == NULL)
        return 0;

    int firstOption = Diameter(root->left);
    int secondOption = Diameter(root->right);
    int thirdOption = Height(root->left) + Height(root->right) + 1;

    return max(firstOption, max(secondOption, thirdOption));
}

int main()
{
    Node *BinaryTree = NULL;
    BinaryTree = TreeFormation(BinaryTree);
    levelOrderTraversal(BinaryTree);
    cout << "The height of Binary tree is : " << Height(BinaryTree) << endl;
    cout << "The Diameter of Binary tree in O(n) is : " << Diameter(BinaryTree) << endl;
    cout << "The Diameter of Binary tree in O(n^2) is : " << Diameter2(BinaryTree) << endl;
    return 0;
}