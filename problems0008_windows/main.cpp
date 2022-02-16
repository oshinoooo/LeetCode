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
    int myAtoi(string s) {
        long out = 0;
        bool negative = false;
        bool start = false;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < '0' || '9' < s[i]) {
                if (start)
                    break;

                if (s[i] == '+') {
                    start = true;
                    negative = false;
                }
                else if (s[i] == '-') {
                    start = true;
                    negative = true;
                }
                else if (s[i] != ' ')
                    break;
            }
            else {
                start = true;
                out = out * 10 + s[i] - '0';

                if (INT_MAX < out)
                    break;
            }
        }

        if (negative)
            out *= -1;

        if (out < INT_MIN)
            out = INT_MIN;
        else if (INT_MAX < out)
            out = INT_MAX;

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.myAtoi(" +1  000-1234 asdf") << endl;
    cout << "---------------------" << endl;
    return 0;
}
