#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <tuple>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
class WordDictionary
{
public:
    WordDictionary()
    {
        alphabet = vector<WordDictionary*>(26);
        isEnd = false;
    }

    void addWord(string word)
    {
        if (word.empty())
        {
            isEnd = true;
            return;
        }

        if (alphabet[word[0] - 'a'] == nullptr)
            alphabet[word[0] - 'a'] = new WordDictionary();

        alphabet[word[0] - 'a']->addWord(word.substr(1));
    }

    bool search(string word)
    {
        if (word.empty() && isEnd)
            return true;
        else if (word.empty() && !isEnd)
            return false;

        bool tmp = false;
        if (word[0] == '.')
        {
            for (int i = 0; i < alphabet.size(); ++i)
            {
                if (alphabet[i] != nullptr)
                {
                    tmp = tmp || alphabet[i]->search(word.substr(1));
                    if (tmp)
                        return true;
                }
            }
        }
        else if (alphabet[word[0] - 'a'] == nullptr)
            return false;
        else
            return alphabet[word[0] - 'a']->search(word.substr(1));

        return false;
    }

private:
    vector<WordDictionary*> alphabet;
    bool isEnd;
};
*/

struct TrieNode
{
    vector<TrieNode *> child = vector<TrieNode *>(26,nullptr);
    bool isEnd = false;
};

void insert(TrieNode * root, const string & word)
{
    TrieNode * node = root;
    for (auto c : word)
    {
        if (node->child[c - 'a'] == nullptr)
            node->child[c - 'a'] = new TrieNode();
        node = node->child[c - 'a'];
    }
    node->isEnd = true;
}

class WordDictionary
{
public:
    WordDictionary()
    {
        trie = new TrieNode();
    }

    void addWord(string word)
    {
        insert(trie,word);
    }

    bool search(string word)
    {
        return dfs(word, 0, trie);
    }

    bool dfs(const string & word,int index,TrieNode * node)
    {
        if (index == word.size())
            return node->isEnd;

        char ch = word[index];
        if (ch >= 'a' && ch <= 'z')
        {
            TrieNode * child = node->child[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child))
                return true;

        }
        else if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                TrieNode * child = node->child[i];
                if (child != nullptr && dfs(word, index + 1, child))
                    return true;
            }
        }
        return false;
    }
private:
    TrieNode * trie;
};

int main()
{
    cout << "---------------------" << endl;
    WordDictionary w;
    w.addWord("at");
    w.addWord("and");
    w.addWord("an");
    w.addWord("add");
    cout << w.search("a") << endl;
    cout << w.search(".at") << endl;
    w.addWord("bat");
    cout << w.search(".at") << endl;
    cout << w.search("an.") << endl;
    cout << w.search("a.d.") << endl;
    cout << w.search("b.") << endl;
    cout << w.search("a.d") << endl;
    cout << w.search(".") << endl;
    cout << "---------------------" << endl;
    return 0;
}
