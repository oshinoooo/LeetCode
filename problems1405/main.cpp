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
    string longestDiverseString(int a, int b, int c) {
        string out;
        vector<pair<int, char>> arr = {{a, 'a'}, {b, 'b'}, {c, 'c'}};

        while (0 < a || 0 < b || 0 < c) {
            sort(arr.begin(), arr.end(), greater<>());

            if (!out.empty() && )
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.longestDiverseString(1, 1, 7) << endl;
    cout << "---------------------" << endl;
    return 0;
}
