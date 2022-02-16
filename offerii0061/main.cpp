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
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
        multimap<int, vector<int>> m;
        for (int i = 0; i < (nums1.size() < k ? nums1.size() : k); ++i) {
            for (int j = 0; j < (nums2.size() < k ? nums2.size() : k); ++j) {
                m.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }
        }

        vector<vector<int>> out;
        auto it = m.begin();
        for (int i = 0; i < (m.size() < k ? m.size() : k); ++i, ++it)
            out.push_back(it->second);

        return out;
    }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first + p1.second < p2.first + p2.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            for (int j = 0; j < nums2.size() && j < k; ++j) {
                if (heap.size() < k) {
                    heap.push({nums1[i], nums2[j]});
                }
                else if (nums1[i] + nums2[j] < heap.top().first + heap.top().second)  {
                    heap.pop();
                    heap.push({nums1[i], nums2[j]});
                }
            }
        }

        vector<vector<int>> out(heap.size());
        for (int i = heap.size() - 1; 0 <= i; --i) {
            out[i] = {heap.top().first, heap.top().second};
            heap.pop();
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    vector<vector<int>> out = s.kSmallestPairs(nums1, nums2, 3);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
