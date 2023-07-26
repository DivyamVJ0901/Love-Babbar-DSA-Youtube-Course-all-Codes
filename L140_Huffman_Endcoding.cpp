#include <bits/stdc++.h>
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

class cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

void solveForHufmann(Node *root, vector<string> &ans, string temp)
{
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(temp);
        return;
    }

    solveForHufmann(root->left, ans, temp + '0');
    solveForHufmann(root->right, ans, temp + '1');
}

vector<string> huffmanCodes(string S, vector<int> freq, int N)
{
    vector<string> ans;
    priority_queue<Node *, vector<Node *>, cmp> minHeap;

    for (int i = 0; i < N; i++)
    {
        Node *temp = new Node(freq[i]);
        minHeap.push(temp);
    }

    while (minHeap.size() > 1)
    {
        Node *leftNode = minHeap.top();
        minHeap.pop();

        Node *rightNode = minHeap.top();
        minHeap.pop();

        Node *newNode = new Node(leftNode->data + rightNode->data);

        newNode->left = leftNode;
        newNode->right = rightNode;

        minHeap.push(newNode);
    }

    // Yaha tak aane ke baad min Heap me sirf ek element bcha hoga ,, aur usiko hum root element bolenge
    Node *root = minHeap.top();

    // temp string me hum '0' aur '1' ko store krenge Hufmann coding ke liye
    string temp = "";

    solveForHufmann(root, ans, temp);

    return ans;
}

void Print(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    string S = "abcdef";
    vector<int> frequency = {5, 9, 12, 13, 16, 45};
    vector<string> ans = huffmanCodes(S, frequency, frequency.size());
    Print(ans);
    return 0;
}