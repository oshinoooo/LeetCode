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
        chars = vector<Trie*>(26, nullptr);
        end = false;
    }

    void insert(string word) {
        Trie* node = this;

        for (auto& c : word) {
            if (!node->chars[c - 'a'])
                node->chars[c - 'a'] = new Trie();
            node = node->chars[c - 'a'];
        }

        node->end = true;
    }

    bool search(string word) {
        Trie* node = this;

        for (auto& c : word) {
            if (!node->chars[c - 'a'])
                return false;
            node = node->chars[c - 'a'];
        }

        return node->end;
    }

    bool startsWith(string prefix) {
        Trie* node = this;

        for (auto& c : prefix) {
            if (!node->chars[c - 'a'])
                return false;
            node = node->chars[c - 'a'];
        }

        return true;
    }

private:
    vector<Trie*> chars;
    bool end;
};

int main() {
    cout << "---------------------" << endl;
    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;

    cout << trie.startsWith("app") << endl;

    trie.insert("app");
    cout << trie.search("app") << endl;

    cout << "---------------------" << endl;
    return 0;
}
