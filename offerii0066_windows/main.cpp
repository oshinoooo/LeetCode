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
        prefixSum = 0;
    }

    void insert(string word, int value) {
        int oldValue = m[word];
        m[word] = value;
        value -= oldValue;

        Trie* node = this;

        for (auto& c : word) {
            if (!node->child[c - 'a'])
                node->child[c - 'a'] = new Trie();
            node = node->child[c - 'a'];
            node->prefixSum += value;
        }

        node->isEnd = true;
    }

    int getSum(string prefix) {
        Trie* node = this;
        for (auto& c : prefix) {
            node = node->child[c - 'a'];
            if (!node)
                return 0;
        }
        return node->prefixSum;
    }

private:
    vector<Trie*> child;
    bool isEnd;
    int prefixSum;
    unordered_map<string, int> m;
};

class MapSum {
public:
    MapSum() {
        root = new Trie();
    }

    void insert(string key, int val) {
        root->insert(key, val);
    }

    int sum(string prefix) {
        return root->getSum(prefix);
    }

private:
    Trie* root;
};

int main() {
    cout << "---------------------" << endl;
    MapSum mapSum;

    mapSum.insert("apple", 3);
    cout << mapSum.sum("ap") << endl;

    mapSum.insert("app", 2);
    cout << mapSum.sum("ap") << endl;

    mapSum.insert("apple", 5);
    mapSum.insert("apple", 1);
    cout << mapSum.sum("apple") << endl;
    cout << "---------------------" << endl;
    return 0;
}
