#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeatingChar(string stream)
{
    unordered_map<char , int> vis;
    queue<char> que;
    string ans = "";

    for (int i = 0; i < stream.length(); i++)
    {
        char temp_char = stream[i];
        
        vis[temp_char]++;    // Map me count store kar rahe har character ka

        que.push(temp_char);   // Usi time us char ko queue me bhi daal rahe

        while (!que.empty())
        {
            if(vis[que.front()] > 1)  // repeating character
                que.pop(); 
            else                    // Non-repeating character
            {
                ans += que.front();
                break;
            }
        }

        if(que.empty()) // Yaha pe hum tabhi pahuche hai jab yaa to que empty ho chuki hai yaa fir uper waale while loop me if condition fail hogyi hogi
            ans += '#';
    }
    return ans;
}

int main()
{
    string ques = "aabc";
    cout<<FirstNonRepeatingChar(ques);
    return 0;
}