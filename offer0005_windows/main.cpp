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
    string replaceSpace(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                s.replace(i, 1, "%20");
            }
        }
        return s;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.replaceSpace("We are happy.") << endl;
    cout << "---------------------" << endl;
    return 0;
}
