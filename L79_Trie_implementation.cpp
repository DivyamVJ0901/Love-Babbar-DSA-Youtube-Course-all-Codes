#include <iostream>
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

    // INSERTION OF A WORD
    void InsertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // we are asuming that all words are in CAPS
        int index = word[0] - 'A';
        TrieNode *child;

        // Present , that means bas aage badh jaao
        if (root->children[index] != NULL)
            child = root->children[index];

        // Absent , to new node create krke insert kro
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        InsertUtil(child, word.substr(1)); // root ke agle wala child pass kra aur word pass kr diya pehle character ko chhodke
    }

    void InsertWord(string word)
    {
        InsertUtil(root, word);
    }

    // SEARCHNING OF A WORD
    bool SearchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];

        else
            return false;

        return SearchUtil(child, word.substr(1));
    }

    bool Searchword(string word)
    {
        return SearchUtil(root, word);
    }

    // REMOVAL OF A WORD
    void RemoveUtil(TrieNode *root, string word)
    {
        // Base case
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];

        RemoveUtil(child, word.substr(1));
    }

    void RemoveWord(string word)
    {
        RemoveUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->InsertWord("ARM");
    t->InsertWord("DO");
    t->InsertWord("TIME");
    t->InsertWord("NIGHT");
    if (t->Searchword("DO"))
        cout << "YES YES " << endl;
    else
        cout << "NO NO " << endl;

    t->RemoveWord("DO");
    if (t->Searchword("DO"))
        cout << "YES YES " << endl;
    else
        cout << "NO NO " << endl;

    t->InsertWord("DO");
    if (t->Searchword("DO"))
        cout << "YES YES " << endl;
    else
        cout << "NO NO " << endl;
    return 0;
}