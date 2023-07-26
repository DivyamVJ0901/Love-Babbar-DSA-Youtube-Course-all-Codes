// STACK USING STL
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(45);
    s.push(12);
    s.push(63);
    s.push(85);

    cout << "Peak element " << s.top() << endl;
    s.pop();
    cout << "Peak element " << s.top() << endl;
    s.pop();
    cout << "Peak element " << s.top() << endl;
    s.pop();
    cout << "Peak element " << s.top() << endl;
    s.pop();

    if (s.empty())
        cout << "Khatam" << endl;
    else
        cout << "Kuch to hai abhi bhi" << endl;
    return 0;
}