#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        unordered_map<int, int> cnt;
        for (int x : arr)
            ++cnt[x];

        if (cnt[0] % 2)
            return false;

        vector<int> vals;
        vals.reserve(cnt.size());
        for (auto &[x, _] : cnt)
            vals.push_back(x);

        sort(vals.begin(), vals.end(), [](int a, int b) { return abs(a) < abs(b); });

        for (int x : vals) {
            if (cnt[2 * x] < cnt[x])
                return false;

            cnt[2 * x] -= cnt[x];
        }

        return true;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> arr = {4,-2,2,-4};
    cout << s.canReorderDoubled(arr) << endl;
    cout << "--------------------" << endl;
    return 0;
}