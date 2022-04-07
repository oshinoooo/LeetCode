#include <iostream>
#include <vector>

using namespace std;

class Trie {
public:
    Trie() {
        end = false;
        children.resize(26, nullptr);
    }

    void insert(string word) {
        Trie* node = this;

        for (const char& c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new Trie();
            node = node->children[index];
        }

        node->end = true;
    }

    bool search(string word) {
        Trie* node = this;

        for (const char& c : word) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }

        return node->end;
    }

    bool startsWith(string prefix) {
        Trie* node = this;

        for (const char& c : prefix) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }

        return true;
    }

private:
    bool end;
    vector<Trie*> children;
};

int main() {
    cout << "--------------------" << endl;
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;
    trie.insert("app");
    cout << trie.search("app") << endl;
    cout << "--------------------" << endl;
    return 0;
}