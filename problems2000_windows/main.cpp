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
#include <ctime>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == ch) {
                reverse(word.begin(), word.begin() + i + 1);
                break;
            }
        }

        return word;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.reversePrefix("abcdefd", 'd') << endl;
    cout << "---------------------" << endl;
    return 0;
}
