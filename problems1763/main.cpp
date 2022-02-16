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
    string longestNiceSubstring1(string s) {
        string out;
        for (int i = 0; i < s.size(); ++i) {
            int lower = 0;
            int upper = 0;
            for (int j = i; j < s.size(); ++j) {
                if (islower(s[j]))
                    lower |= 1 << (s[j] - 'a');
                else
                    upper |= 1 << (s[j] - 'A');

                if (lower == upper && out.length() < j - i + 1)
                    out = s.substr(i, j - i + 1);
            }
        }
        return out;
    }

    string longestNiceSubstring(string s) {
        string out;
        for (int i = 0; i < s.size(); ++i) {
            int lower = 0;
            int upper = 0;
            for (int j = i; j < s.size(); ++j) {
                if (islower(s[j]))
                    lower |= 1 << (s[j] - 'a');
                else
                    upper |= 1 << (s[j] - 'A');

                if (lower == upper && out.length() < j - i + 1)
                    out = s.substr(i, j - i + 1);
            }
        }
        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.longestNiceSubstring("YazaAay") << endl;
    cout << "---------------------" << endl;
    return 0;
}
