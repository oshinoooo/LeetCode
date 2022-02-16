#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string kthLargestNumber(vector<string>& nums, int k)
    {
        sort(nums.begin(), nums.end(), [](const string& s1, const string& s2) -> bool
             {
                 if (s1.size() < s2.size())
                     return true;
                 else if (s1.size() > s2.size())
                     return false;
                 else
                     return s1 < s2;
             }
        );

        for (auto num : nums)
            cout << num << endl;
        return nums[nums.size() - k];
    }
};

int main()
{
    cout << "----------------------" << endl;
    Solution s;
    vector<string> in = {"3","6","7","10"};
    cout << s.kthLargestNumber(in, 4) << endl;
    cout << "----------------------" << endl;
    return 0;
}
