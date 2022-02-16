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
    bool validPalindrome(string s) {
        int head = 0;
        int tail = s.size() - 1;

        while (head < tail) {
            if (s[head] != s[tail])
                return my_validPalindrome(s, head + 1, tail) || my_validPalindrome(s, head, tail - 1);
            ++head;
            --tail;
        }

        return true;
    }

private:
    bool my_validPalindrome(string s, int head, int tail) {
        while (head < tail) {
            if (s[head] != s[tail])
                return false;
            ++head;
            --tail;
        }

        return true;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.validPalindrome("123452364321") << endl;
    cout << "---------------------" << endl;
    return 0;
}
