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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> out;

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> out = s.combinationSum2(candidates, target);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
