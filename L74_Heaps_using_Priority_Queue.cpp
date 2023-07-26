#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cout << "HEAPS USING PRIORITY QUEUE : " << endl;

    // it represents MAX HEAP
    // Jo element sabse bada hoga vo sabse uper rahega aur jo sabse chota hoga vo sabse neeche

    priority_queue<int> heap;
    heap.push(5);
    heap.push(3);
    heap.push(2);
    heap.push(7);

    while (heap.size() > 0)
    {
        cout<<heap.top()<<" ";
        heap.pop();
    }
    

    // cout << "Element at top : " << heap.top() << endl;
    // heap.pop();
    // cout << "Element at top : " << heap.top() << endl;
    // cout << "Size of heap : " << heap.size() << endl;

    // if (heap.empty())
    //     cout << "Heap is empty" << endl;
    // else
    //     cout << "Heap is not empty" << endl;

    // // it represents MIN HEAP

    // priority_queue<int, vector<int>, greater<int>> minHeap;
    // minHeap.push(5);
    // minHeap.push(3);
    // minHeap.push(2);
    // minHeap.push(7);
    // cout << "Element at top : " << minHeap.top() << endl;
    // minHeap.pop();
    // minHeap.pop();
    // minHeap.pop();
    // minHeap.pop();
    // cout << "Element at top : " << minHeap.top() << endl;
    // cout << "Size of heap : " << minHeap.size() << endl;

    // if (minHeap.empty())
    //     cout << "Heap is empty" << endl;
    // else
    //     cout << "Heap is not empty" << endl;

    return 0;
}