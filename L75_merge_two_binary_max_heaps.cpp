#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < arr.size() && arr[largest] < arr[left])
        largest = left;

    if (right < arr.size() && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest);
    }
}

vector<int> mergedHeap(vector<int> &heap1, vector<int> &heap2)
{
    vector<int> merged;

    for (int i = 0; i < heap1.size(); i++)
        merged.push_back(heap1[i]);

    for (int i = 0; i < heap2.size(); i++)
        merged.push_back(heap2[i]);

    for (int i = merged.size() / 2 - 1; i >= 0; i--)
        heapify(merged, 0);

    return merged;
}

void PrintArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> h = {30, 50, 60, 70, 20};
    vector<int> p = {7, 10, 4, 20, 15};
    vector<int> ans = mergedHeap(h, p);
    PrintArray(ans);
    return 0;
}