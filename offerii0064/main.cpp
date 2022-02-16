#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>

using namespace std;

//class MagicDictionary {
//public:
//    MagicDictionary() {
//        root = new Trie();
//    }
//
//    void buildDict(vector<string> dictionary) {
//        for (auto& word : dictionary)
//            root->insert(word);
//    }
//
//    bool search(string searchWord) {
//        for (int i = 0; i < searchWord.size(); ++i) {
//            string tmp = searchWord;
//            for (int j = 0; j < 26; ++j) {
//                if (searchWord[i] != 'a' + j) {
//                    tmp[i] = 'a' + j;
//                    if (root->search(tmp))
//                        return true;
//                }
//            }
//        }
//        return false;
//    }
//
//private:
//    Trie* root;
//};

class Trie {
public:
    Trie () : isWord(false), children(26, nullptr) {}

    void insert(const string& str) {
        Trie* node = this;
        for (auto& ch : str) {
            if (node->children[ch - 'a'] == nullptr)
                node->children[ch - 'a'] = new Trie();
            node = node->children[ch - 'a'];
        }
        node->isWord = true;
    }

    bool isWord;
    vector<Trie*> children;
};

class MagicDictionary {
public:
    MagicDictionary() {
        root = new Trie();
    }

    void buildDict(vector<string> dictionary) {
        for (auto& word : dictionary) {
            root->insert(word);
        }
    }

    bool search(string searchWord) {
        return dfs(root, searchWord, 0, 0);
    }

private:
    bool dfs(Trie* root, string& word, int i, int edit) {
        if (!root)
            return false;

        if (root->isWord && i == word.size() && edit == 1)
            return true;

        if (i < word.size() && edit <= 1) {
            bool found = false;
            for (int j = 0; j < 26 && !found; ++j) {
                int next = (j == word[i] - 'a') ? edit : edit + 1;
                found = dfs(root->children[j], word, i + 1, next);
            }

            return found;
        }

        return false;
    }

private:
    Trie* root;
};

int main() {
    cout << "---------------------" << endl;
    MagicDictionary magicDictionary;
    magicDictionary.buildDict({"hello", "leetcode"});
    cout << magicDictionary.search("hello") << endl;
    cout << magicDictionary.search("hhllo") << endl;
    cout << magicDictionary.search("hell") << endl;
    cout << magicDictionary.search("leetcoded") << endl;
    cout << "---------------------" << endl;
    return 0;
}
