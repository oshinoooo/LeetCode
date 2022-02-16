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

    string getPrefix(string word) {
        string out;
        Trie* node = this;

        for (auto& c : word) {
            if (!node->chars[c - 'a'])
                break;

            out.push_back(c);
            node = node->chars[c - 'a'];

            if (node->end)
                return out;
        }

        return "";
    }

private:
    vector<Trie*> chars;
    bool end;
};

class Solution {
public:
    string replaceWords1(vector<string>& dictionary, string sentence) {
        unordered_set<string> s;
        for (auto& root : dictionary)
            s.insert(root);

        string out;
        int start = 0;
        for (int i = 0; i < sentence.size(); ++i) {
            if (i == sentence.size() - 1 || sentence[i + 1] == ' ') {
                string word = sentence.substr(start, i - start + 1);
                bool found = false;

                for (int j = 1; j <= word.size(); ++j) {
                    string tmp = word.substr(0, j);
                    if (s.count(tmp)) {
                        out += tmp + " ";
                        found = true;
                        break;
                    }
                }

                if (!found)
                    out += word + " ";

                start = i + 2;
            }
        }


        out.pop_back();

        return out;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();
        for (auto& prefix : dictionary)
            root->insert(prefix);

        vector<string> words;
        int start = 0;
        for (int i = 0; i < sentence.size(); ++i) {
            if (i == sentence.size() - 1 || sentence[i + 1] == ' ') {
                string word = sentence.substr(start, i - start + 1);
                words.push_back(word);
                start = i + 2;
            }
        }

        string out;
        for (auto& word : words) {
            string prefix = root->getPrefix(word);
            if (prefix == "")
                out += word + " ";
            else
                out += prefix + " ";
        }

        out.pop_back();
        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    cout << s.replaceWords(dictionary, sentence) << endl;
    cout << "---------------------" << endl;
    return 0;
}
