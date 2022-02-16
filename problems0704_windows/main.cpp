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
    int search(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size() - 1;

        while (head <= tail) {
            int mid = head + (tail - head) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                head = mid + 1;
            else
                tail = mid - 1;
        }

        return -1;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {-1,0,3,5,9,12};
    cout << s.search(nums, 5) << endl;
    cout << "---------------------" << endl;
    return 0;
}
