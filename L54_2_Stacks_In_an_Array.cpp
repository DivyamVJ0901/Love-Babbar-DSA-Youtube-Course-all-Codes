// IMPLEMENTATION OF 2 STACKS IN AN ARRAY
#include <iostream>
using namespace std;

class TwoStack
{
public:
    int *arr, top1, top2, size;
    TwoStack(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void Push1(int num)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }

        else
            cout << "Stack overflow" << endl;
    }

    void Push2(int num)
    {
        if (top2 < size)
        {
            top2--;
            arr[top2] = num;
        }

        else
            cout << "Stack Overflow" << endl;
    }

    int Pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }

        else
            return -1;
    }

    int Pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }

        else
            return -1;
    }
};

int main()
{
    TwoStack Tst(6);
    Tst.Push1(12);
    Tst.Push1(15);
    Tst.Push1(14);
    return 0;
}
