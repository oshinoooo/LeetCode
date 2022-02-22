#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int ptr1 = 0;
        int ptr2 = s.size() - 1;

        while (ptr1 < ptr2) {
            if (isalpha(s[ptr1]) && isalpha(s[ptr2]))
                swap(s[ptr1++], s[ptr2--]);

            if (!isalpha(s[ptr1]))
                ++ptr1;

            if (!isalpha(s[ptr2]))
                --ptr2;
        }

        return s;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.reverseOnlyLetters("Test1ng-Leet=code-Q!") << endl;
    cout << "--------------------" << endl;
    return 0;
}
