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
    int strToInt(string str) {
        int out = 0;
        bool negative = false;
        bool valid = false;

        for (int i = 0; i < str.size(); ++i) {
            if (valid && !isdigit(str[i])) {
                return out;
            }
            else if (!valid && str[i] == '-') {
                negative = true;
                valid = true;
            }
            else if (!valid && str[i] == '+') {
                valid = true;
            }
            else if (!valid && !isdigit(str[i]) && str[i] != ' ') {
                break;
            }
            else if (isdigit(str[i])) {
                valid = true;
                if (!negative) {
                    if (out < INT_MAX / 10 || (INT_MAX / 10 == out && str[i] - '0' <= 7)) {
                        out = out * 10 + (str[i] - '0');
                    }
                    else {
                        return INT_MAX;
                    }
                }
                else {
                    if (INT_MIN / 10 < out || (INT_MIN / 10 == out && str[i] - '0' <= 8)) {
                        out = out * 10 - (str[i] - '0');
                    }
                    else {
                        return INT_MIN;
                    }
                }
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.strToInt("0-1") << endl;
    cout << "---------------------" << endl;
    return 0;
}
