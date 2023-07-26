#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
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
        this->col = col;
        this->row = row;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    int mini = INT_MAX, maxi = INT_MIN;

    priority_queue<Node *, vector<Node *>, compare> minHeap;

    // STEP 1 : Creating a min heap to store starting values of each list and tracking min/ max values
    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        minHeap.push(new Node(element, i, 0));
    }

    int s = mini, e = maxi;

    // STEP 2 : processing ranges
    while (!minHeap.empty())
    {
        // STEP 3 : mini fetch
        Node *temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;

        // STEP 4 : Range or answer updation 
        if (maxi - mini < e - s)
        {
            e = maxi;
            s = mini;
        }

        // STEP 5 : Next element exists 
        if (temp->col + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }

        // STEP 6 : Next element not exist
        else
            break;
    }

    // STEP 7: returning ans
    return (e - s + 1);
}

int main()
{
    vector<vector<int>> ques = {{1, 10, 11}, {2, 3, 20}, {5, 6, 12}};
    cout << "Smallest range diffrence is : " << kSorted(ques, 3, 3) << endl;
    return 0;
}