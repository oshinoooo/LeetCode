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
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> count;
        count['b'] = 0;
        count['a'] = 0;
        count['l'] = 0;
        count['o'] = 0;
        count['n'] = 0;

        for (auto& c : text)
            ++count[c];

        int out = INT_MAX;
        for (auto& [c, num] : count) {
            if (c == 'l' || c == 'o')
                out = min(out, num / 2);
            else if (c == 'b' || c == 'a' || c == 'n')
                out = min(out, num);
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.maxNumberOfBalloons("loonbalxballpoon") << endl;
    cout << "---------------------" << endl;
    return 0;
}
