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
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto& num : nums)
            ++m[num];

        int sum = 0;
        for (auto& [num, count] : m) {
            if (count == 1)
                sum += num;
        }
        return sum;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1,2,3,2};
    cout << s.sumOfUnique(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
