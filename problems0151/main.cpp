#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords1(string s) {
        vector<string> words;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ')
                start = i + 1;
            else if (i == s.size() - 1 || s[i + 1] == ' ')
                words.push_back(s.substr(start, i - start + 1));
        }

        reverse(words.begin(), words.end());

        string out;
        for (int i = 0; i < words.size(); ++i) {
            if (!out.empty())
                out += " ";
            out += words[i];
        }

        return out;
    }

    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int curr = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (curr != 0 && i != 0 && s[i - 1] == ' ')
                    s[curr++] = ' ';
                s[curr++] = s[i];
            }
        }

        s.resize(curr);

        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i == s.size() - 1 || s[i + 1] == ' ') {
                reverse(s.begin() + start, s.begin() + i + 1);
                start = i + 2;
            }
        }

        return s;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.reverseWords("     the    sky is     blue   ") << endl;
    cout << "--------------------" << endl;
    return 0;
}
