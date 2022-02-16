#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Trie
{
public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word)
    {
        Trie* node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
                node->children[ch] = new Trie();
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix)
    {
        return this->searchPrefix(prefix) != nullptr;
    }

private:
    Trie* searchPrefix(string prefix)
    {
        Trie* node = this;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
                return nullptr;
            node = node->children[ch];
        }
        return node;
    }

private:
    vector<Trie*> children;
    bool isEnd;
};

int main()
{
    cout << "-------------------------" << endl;
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;
    cout << trie->search("app") << endl;
    cout << trie->startsWith("app") << endl;
    trie->insert("app");
    cout << trie->search("app") << endl;
    cout << "-------------------------" << endl;
    return 0;
}
