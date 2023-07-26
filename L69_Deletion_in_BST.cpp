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

void Inorder(Node *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(Node *root)
{
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

Node *MinValueInBST(Node *&root)
{
    Node *temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

Node *MaxValueInBST(Node *&root)
{
    Node *temp = root;
    while (temp->right != NULL)
        temp = temp->right;
    return temp;
}

// DELETION
Node *DeletionInBST(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
    {
        // NODE WITH 0 CHILD (LEAF NODE)
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // NODE WITH 1 CHILD

        // Left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // NODE WITH 2 CHILDREN
        if (root->left != NULL && root->right != NULL)
        {
            int mini = MinValueInBST(root->right)->data;    // Right subtree se minimum node nikal li
            root->data = mini;                              // Root ke data me min value of right subtree daal di , sirf copy kiya
            root->right = DeletionInBST(root->right, mini); // ab yaha mini ko delete kr diya root ke right me se
            return root;

            /*
            int maxi = MaxValueInBST(root->left)->data;     // left subtree se maximum node nikal li
            root->data = maxi;                              // Root ke data me max value of left subtree daal di , sirf copy kiya
            root->left = DeletionInBST(root->left, maxi);   // ab yaha maxi ko delete kr diya root ke left me se
            return root;
            */
           
        }
    }

    else if (root->data > key)
    {
        root->left = DeletionInBST(root->left, key);
        return root;
    }

    else
    {
        root->right = DeletionInBST(root->right, key);
        return root;
    }
}

int main()
{
    Node *BST = NULL;
    cout << "Enter data to create BST : " << endl;
    getData(BST);
    cout << "The Level Order Traversal of BST is : " << endl;
    LevelOrderTraversal(BST);
    cout << "The Inorder Traversal of BST is : " << endl;
    Inorder(BST);
    cout << endl;
    cout << "The Preorder Traversal of BST is : " << endl;
    Preorder(BST);
    cout << endl;
    cout << "The Postorder Traversal of BST is : " << endl;
    Postorder(BST);
    cout << endl;

    // DELETION
    int key;
    cout << "Enter Node to be deleted : " << endl;
    cin >> key;
    BST = DeletionInBST(BST, key);
    cout << "The Level Order Traversal of BST is : " << endl;
    LevelOrderTraversal(BST);
    cout << "The Inorder Traversal of BST is : " << endl;
    Inorder(BST);
    cout << endl;
    cout << "The Preorder Traversal of BST is : " << endl;
    Preorder(BST);
    cout << endl;
    cout << "The Postorder Traversal of BST is : " << endl;
    Postorder(BST);
    return 0;
}
// 50 20 70 10 30 90 110 -1
// 8 3 10 14 1 6 4 7 13 -1
