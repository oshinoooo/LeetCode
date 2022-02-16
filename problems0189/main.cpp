#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        k = k % nums.size();
        nums.insert(nums.begin(), nums.end() - k, nums.end());
        nums.assign(nums.begin(), nums.end() - k);
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3};
    int k = 1;
    s.rotate(nums, k);
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
