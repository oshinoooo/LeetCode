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
    string modifyString(string s) {
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            if (s[i] == '?') {
                if (i == 0) {
                    if (i + 1 < length && s[i + 1] != '?') {
                        s[i] = (s[i + 1] - 'a' + 1) % 26 + 'a';
                    }
                    else {
                        s[i] = 'a';
                    }
                }
                else if (i == s.size() - 1) {
                    if (0 <= i - 1) {
                        s[i] = (s[i - 1] - 'a' + 1) % 26 + 'a';
                    }
                    else {
                        s[i] = 'a';
                    }
                }
                else {
                    char tmp = (s[i - 1] - 'a' + 1) % 26 + 'a';
                    s[i] = tmp == s[i + 1] ? (tmp - 'a' + 1) % 26 + 'a' : tmp;
                }
            }
        }

        return s;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.modifyString("??yw?ipkj?") << endl;
    cout << "---------------------" << endl;
    return 0;
}
