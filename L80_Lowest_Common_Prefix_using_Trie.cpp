#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childcount;
    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        this->isTerminal = false;
        this->childcount = 0;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie(char ch)
    {
        root = new TrieNode(ch);
    }
    void InsertUtil(TrieNode *root, string word)
    {
        // Base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];
        else
        {
            child = new TrieNode(word[0]);
            root->childcount++;
            root->children[index] = child;
        }

        InsertUtil(child, word.substr(1));
    }

    void InsertWord(string word)
    {
        InsertUtil(root, word);
    }

    void lcp(string str, string ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (root->childcount == 1)
            {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            // else if (root->childcount != 1 && root->isTerminal)
            //     break;
            else
                break;
            if(root->isTerminal)
                break;
        }
    }
};

string LongestCommonPref(vector<string> &arr, int n)
{
    string ans = "";
    Trie *t = new Trie('\0');

    // ab saari ki saari strings ko trie me daal do
    for (int i = 0; i < n; i++)
        t->InsertWord(arr[i]);

    string first = arr[0];

    t->lcp(first, ans);
    return ans;
}

void PrintStr(string temp)
{
    for (int i = 0; i < temp.length(); i++)
        cout << temp[i];
    cout << endl;
}

int main()
{
    vector<string> ques = {"ninja", "night", "nil"};
    string res = LongestCommonPref(ques, ques.size());
    PrintStr(res);
    return 0;
}