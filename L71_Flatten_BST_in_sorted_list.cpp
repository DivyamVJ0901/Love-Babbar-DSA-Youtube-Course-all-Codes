#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
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

void Inorder(Node *root, vector<int> &arr)
{
    if (root == NULL)
        return;

    Inorder(root->left, arr);
    arr.push_back(root->data);
    Inorder(root->right, arr);
}

Node *FlattenBSTtoSortedList(Node *root)
{
    vector<int> arr;
    Inorder(root, arr);

    Node *newR = new Node(arr[0]);
    Node *curr = newR;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;

    return newR;
}

void PrintLL(Node *node)
{
    Node *temp = node;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    if (temp == NULL)
        cout << "NULL";
    cout << endl;
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    getData(root);
    cout << "The Level Order Traversal of BST is : " << endl;
    LevelOrderTraversal(root);
    Node *ans = FlattenBSTtoSortedList(root);
    PrintLL(ans);
    return 0;
}
// 4 7 9 2 4 6 3 5 -1
// 2->3->4->5->6->7->9->NULL