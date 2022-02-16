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
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n)
            return {};
        vector<vector<int>> out;
        for (int i = 0; i < m * n; i += n)
            out.emplace_back(original.begin() + i, original.begin() + i + n);
        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> original = {1,2,3,4};
    vector<vector<int>> out = s.construct2DArray(original, 2, 2);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
