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
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();

        vector<int> left(n, 0);
        for (int i = 1; i < n; ++i) {
            if (security[i - 1] >= security[i])
                left[i] = left[i - 1] + 1;
        }

        vector<int> right(n, 0);
        for (int i = n - 2; 0 <= i; --i) {
            if (security[i] <= security[i + 1])
                right[i] = right[i + 1] + 1;
        }

        vector<int> out;
        for (int i = 0; i < n; ++i) {
            if (time <= left[i] && time <= right[i])
                out.push_back(i);
        }

        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> security = {5, 3, 3, 3, 5, 6, 2};
    int time = 2;
    vector<int> out = s.goodDaysToRobBank(security, time);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}
