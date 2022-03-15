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
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        count = 0;
        maxNum = 0;
        sort(this->nums.begin(), this->nums.end());
        for (int i = 0; i < n; ++i) {
            myCountMaxOrSubsets(0, i);
        }
        return count;
    }

private:
    void myCountMaxOrSubsets(int tmpNum, int index) {
        int n = nums.size();

        if (n <= index)
            return;

        tmpNum |= nums[index];

        if (maxNum < tmpNum) {
            maxNum = tmpNum;
            count = 1;
        }
        else if (maxNum == tmpNum)
            ++count;

        for (int i = index + 1; i < n; ++i)
            myCountMaxOrSubsets(tmpNum, i);
    }

private:
    vector<int> nums;
    int count;
    int maxNum;
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {3,2,1,5};
    cout << s.countMaxOrSubsets(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
