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
    vector<vector<int>> kSmallestPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
        int length1 = nums1.size();
        int length2 = nums2.size();

        if (k < length1)
            nums1.resize(k);

        if (k < length2)
            nums2.resize(k);

        k = min(k, length1 * length2);

        multimap<int, vector<int>> m;
        for (int i = 0; i < length1; ++i) {
            for (int j = 0; j < length2; ++j)
                m.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
        }

        vector<vector<int>> out;
        auto it = m.begin();
        for (int i = 0; i < k; ++i) {
            out.push_back(it++->second);
        }

        return out;
    }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int length1 = nums1.size();
        int length2 = nums2.size();

        auto function = [&](pair<int, int> a, pair<int, int> b) {
            return a.first + a.second < b.first + b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(function)> pq(function);
        for (int i = 0; i < min(k, length1); ++i) {
            for (int j = 0; j < min(k, length2); ++j) {
                if (pq.size() < k)
                    pq.push({nums1[i], nums2[j]});
                else if (nums1[i] + nums2[j] < pq.top().first + pq.top().second) {
                    pq.pop();
                    pq.push({nums1[i], nums2[j]});
                }
            }
        }

        int size = pq.size();
        vector<vector<int>> out(size);
        for (int i = size - 1; 0 <= i; --i) {
            out[i] = {pq.top().first, pq.top().second};
            pq.pop();
        }

        return out;
    }

    vector<vector<int>> kSmallestPairs3(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&](const pair<int, int> & a, const pair<int, int> & b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min(k, m); i++) {
            pq.emplace(i, 0);
        }

        while (k-- > 0 && !pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            ans.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
            if (y + 1 < n) {
                pq.emplace(x, y + 1);
            }
        }

        return ans;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    int k = 10;
    vector<vector<int>> out = s.kSmallestPairs(nums1, nums2, k);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
