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

class Trie {
public:
    Trie() {
        child = vector<Trie*>(26, nullptr);
        isEnd = false;
    }

    void insert(string word) {
        Trie* node = this;

        for (auto& c : word) {
            if (!node->child[c - 'a'])
                node->child[c - 'a'] = new Trie();
            node = node->child[c - 'a'];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this;

        for (auto& c : word) {
            if (!node->child[c - 'a'])
                return false;
            node = node->child[c - 'a'];
        }

        return node->isEnd;
    }

    void depth(int& count, int level) {
        bool allNullptr = true;
        ++level;
        for (auto& node : child) {
            if (node) {
                node->depth(count, level);
                allNullptr = false;
            }
        }
        if (allNullptr)
            count += level + 1;
    }

    vector<Trie*> child;
    bool isEnd;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie* root = new Trie();
        for (auto& word : words) {
            reverse(word.begin(), word.end());
            root->insert(word);
        }

        int count = 0;
        for (auto& node : root->child) {
            if (node)
                node->depth(count, 0);
        }
        return count;
    }

    int minimumLengthEncoding2(vector<string>& words) {
        unordered_set<string> good(words.begin(), words.end());
        for (const string& word: words) {
            for (int k = 1; k < word.size(); ++k) {
                good.erase(word.substr(k));
            }
        }

        int ans = 0;
        for (const string& word: good) {
            ans += word.size() + 1;
        }
        return ans;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> words = {"time", "me", "bell"};
    cout << s.minimumLengthEncoding(words) << endl;
    cout << "---------------------" << endl;
    return 0;
}
