// CODE NOT WORKING PROPERLY
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
    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
            this->children[i] = NULL;
        this->isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void InsertUtil(TrieNode *root, string word)
    {
        // base case
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
            root->children[index] = child;
        }
        InsertUtil(child, word.substr(1));
    }

    void InsertWord(string word)
    {
        InsertUtil(root, word);
    }

    void PrintSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
            // HW :- Yaha se return statement kyu htaai ??
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                PrintSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";
        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];
            prefix.push_back(lastch);

            // check for last char
            TrieNode *curr = prev->children[lastch - 'a'];

            // If not found
            if (curr == NULL)
                break;

            // If found
            vector<string> temp;
            PrintSuggestions(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    Trie *t = new Trie();
    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->InsertWord(str);
    }
    return t->getSuggestion(queryStr);
}

void Print2D(vector<vector<string>> temp)
{
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = 0; j < temp.size(); j++)
            cout << temp[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<string> ques = {"cod", "coding", "coly", "codding", "code"};
    string questionString = "coding";
    vector<vector<string>> res = phoneDirectory(ques, questionString);
    Print2D(res);
    return 0;
}