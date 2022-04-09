#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const static string MORSE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
    "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-",
    "...-", ".--", "-..-", "-.--", "--.."
};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        unordered_set<string> seen;
        for (auto &word: words) {
            string code;
            for (auto &c: word)
                code.append(MORSE[c - 'a']);
            seen.emplace(code);
        }
        return seen.size();
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<string> words = {"gin", "zen", "gig", "msg"};
    cout << s.uniqueMorseRepresentations(words) << endl;
    cout << "--------------------" << endl;
    return 0;
}