// QUEUE USING STL
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> Divyam;
    Divyam.push(54);
    Divyam.push(78);
    Divyam.push(91);
    Divyam.push(23);
    cout << "Size of queue is : " << Divyam.size() << endl;
    cout << Divyam.front() << endl;
    cout << Divyam.back() << endl;
    Divyam.pop();
    cout << endl;

    cout << "Size of queue is : " << Divyam.size() << endl;
    cout << Divyam.front() << endl;
    cout << Divyam.back() << endl;
    Divyam.pop();
    cout << endl;

    cout << "Size of queue is : " << Divyam.size() << endl;
    cout << Divyam.front() << endl;
    cout << Divyam.back() << endl;
    Divyam.pop();
    cout << endl;

    cout << "Size of queue is : " << Divyam.size() << endl;
    cout << Divyam.front() << endl;
    cout << Divyam.back() << endl;
    Divyam.pop();
    cout << endl;

    if (Divyam.empty())
        cout << "Empty" << endl;
    else
        cout << "Not empty" << endl;
    return 0;
}