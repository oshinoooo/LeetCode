#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        map<int, int> count;
        for (int i = 0; i < nums.size(); ++i)
            ++count[nums[i]];

        vector<int> out;
        for (auto num : count)
        {
            if (num.second > nums.size() / 3)
                out.push_back(num.first);
        }
        return out;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    vector<int> nums = {1,1,1,3,3,2,2,2};
    vector<int> out = s.majorityElement(nums);
    for (auto o : out)
        cout << o << " ";
    cout << endl;
    cout << "-------------------------" << endl;
    return 0;
}
