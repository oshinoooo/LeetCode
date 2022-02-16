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
    int removePalindromeSub(string s) {
        int ptr1 = 0;
        int ptr2 = s.size() - 1;
        while (ptr1 < ptr2) {
            if (s[ptr1++] != s[ptr2--])
                return 2;
        }
        return 1;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.removePalindromeSub("ababa") << endl;
    cout << "---------------------" << endl;
    return 0;
}
