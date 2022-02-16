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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int cursum = 0;
        int count = 0;
        m.insert({0, 1});

        for(int i = 0; i < nums.size(); ++ i){
            cursum += nums[i];
            if(m.count(cursum - k))
                count += m[cursum - k];
            m[cursum]++;
        }

        return count;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3};
    cout << s.subarraySum(nums, 3) << endl;
    cout << "---------------------" << endl;
    return 0;
}
