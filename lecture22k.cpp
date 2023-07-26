// CODE FOR STRING COMPRESSION
// Time complexity --> O(n)
// Space complexity --> O(1)
#include <iostream>
#include <vector>
using namespace std;

int compress(char ch[], int n)
{
    int i = 0;
    int ansIndex = 0;

    while (i < n)
    {
        int j = i + 1;
        while (j < n && ch[i] == ch[j])
        {
            j++;
        }

        ch[ansIndex] = ch[i];
        ansIndex++;

        int count = j - i;

        if (count > 1)
        {
            string cnt = to_string(count);
            for (char c : cnt)
            {
                ch[ansIndex] = c;
                ansIndex++;
            }
        }
        i = j;
    }
    return ansIndex;
}

int main()
{
    char s[500] = "a";
    cout << "Your string is : " << s << endl;
    cout << compress(s, 500);
    return 0;
}