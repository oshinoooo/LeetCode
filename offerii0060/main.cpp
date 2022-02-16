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
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto& num : nums)
            ++m[num];

        auto func = [&](pair<int, int> num1, pair<int, int> num2){
            return num1.second > num2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(func)> pq(func);

        for (auto& num : m) {
            pq.push(num);
            if (k < pq.size())
                pq.pop();
        }

        vector<int> out;
        while (!pq.empty()) {
            out.push_back(pq.top().first);
            pq.pop();
        }
        return out;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> out;





        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> out = s.topKFrequent(nums, 2);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
