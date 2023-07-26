#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>ṇ
using namespace std;

class Node
{
public:
    int data;
    int row;
    int col;
    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool Operator(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

vector<int> MergedKarraysSorted(vector<vector<int>> kArrays, int k)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    // STEP 1 : SAARE ARRAYS KE FIRST ELEMENTS KO MIN HEAP ME DAAL LIYA
    for (int i = 0; i < k; i++)
    {
        Node *temp = new Node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // STEP 2 :
    while (!minHeap.size())
    {
        Node *temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int row = temp->row;
        int col = temp->col;

        if (col + 1 < kArrays[row].size())
        {
            Node *next = new Node(kArrays[row][col + 1], row, col + 1);
            minHeap.push(next);
        }
    }
    return ans;
}

void PrintArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    vector<int> merged = MergedKarraysSorted(a, 4);

    PrintArray(merged);
    return 0;
}