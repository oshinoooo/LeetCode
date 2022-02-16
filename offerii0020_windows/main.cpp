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

class Solution {
public:
    int countSubstrings1(string s) {
        int count = s.size();
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                string str1 = s.substr(i, j - i + 1);
                string str2 = str1;
                reverse(str2.begin(), str2.end());
                if (str1 == str2)
                    ++count;
            }
        }
        return count;
    }

    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            int head = i;
            int tail = i;
            while (0 <= head && tail < s.size() && s[head] == s[tail]) {
                ++count;
                --head;
                ++tail;
            }
        }

        for (int i = 0; i < s.size() - 1; ++i) {
            int head = i;
            int tail = i + 1;
            while (0 <= head && tail < s.size() && s[head] == s[tail]) {
                ++count;
                --head;
                ++tail;
            }
        }

        return count;
    }

    int countSubstrings3(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++count;
            }
        }
        return count;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.countSubstrings("aaa") << endl;
    cout << "---------------------" << endl;
    return 0;
}
