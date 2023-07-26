// CODE NOT WORKING
#include <iostream>
#include <vector>
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

vector<int> zigzag(Node *&root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> virat;
    virat.push(root);

    bool LeftToRight = true;

    while (!virat.empty())
    {
        vector<int> temp(virat.size());

        for (int i = 0; i < temp.size(); i++)
        {
            Node *frontNode = virat.front();
            virat.pop();
            int index;
            if (LeftToRight)
                index = i;
            else
                index = virat.size() - i - 1;

            temp[index] = frontNode->data;

            if (frontNode->left)
                virat.push(frontNode->left);

            if (frontNode->right)
                virat.push(frontNode->right);
        }

        // LeftToRight = !LeftToRight;
        LeftToRight = false;
        for (auto i : temp)
            ans.push_back(i);   
    }
    return ans;
}

void Print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    Node *tree = NULL;
    tree = TreeFormation(tree);
    levelOrderTraversal(tree);
    vector<int> s = zigzag(tree);
    Print(s);
    return 0;
}
// 1 2 3 -1 -1 5 -1 -1 4 -1 6 8 -1 -1 7 -1 -1