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
    int findLUSlength(string a, string b) {
        return a == b ? -1 : (a.size() < b.size() ? b.size() : a.size());
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.findLUSlength("123", "456") << endl;
    cout << "--------------------" << endl;
    return 0;
}
