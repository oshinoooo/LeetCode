#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution
{
public:
    int countKDifference(vector<int>& nums, int k)
    {
        if (nums.empty()) return 0;

        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] - nums[j] == k || nums[i] - nums[j] == -k)
                    ++count;
            }
        }
        return count;
    }

    vector<int> findOriginalArray1(vector<int> changed)
    {
        if (changed.empty()) return {};

        multiset<int> nums;
        for (auto change : changed)
            nums.insert(change);
        changed.clear();

        while (!nums.empty())
        {
            if (*nums.begin() == 0)
            {
                if (nums.count(0) % 2 == 0)
                {
                    changed.push_back(0);
                    nums.erase(nums.begin());
                    nums.erase(nums.find(0));
                }
                else
                    return {};
            }
            else
            {
                multiset<int>::iterator ptr = nums.find(*nums.begin() * 2);
                if (ptr == nums.end())
                    return {};
                else
                {
                    changed.push_back(*nums.begin());
                    nums.erase(nums.begin());
                    nums.erase(ptr);
                }
            }
        }
        return changed;
    }

    vector<int> findOriginalArray2(vector<int> changed)
    {
        if (changed.size() < 2) return {};

        sort(changed.begin(), changed.end());
        vector<int> out;

        while (!changed.empty())
        {
            if (changed[0] == 0)
            {
                if (changed[1] == 0)
                {
                    out.push_back(0);
                    changed.erase(changed.begin());
                    changed.erase(changed.begin());
                }
                else
                    return {};
            }
            else
            {
                int position = search(changed, 1, changed.size() - 1, changed[0] * 2);
                if (position == -1)
                    return {};
                else
                {
                    out.push_back(changed[0]);
                    changed.erase(changed.begin());
                    changed.erase(changed.begin() + position - 1);
                }
            }
        }
        return out;
    }

    vector<int> findOriginalArray3(vector<int> changed)
    {
        if (changed.size() < 2) return {};

        sort(changed.begin(),changed.end());
        queue<int> q;
        vector<int> res,empty;
        int n = changed.size();
        if(n%2)return empty;
        for(int i=0;i<n;i++)
        {
            if(q.empty())
                q.push(changed[i]);
            else
            {
                if(q.front()*2 == changed[i])
                {
                    res.push_back(q.front());
                    q.pop();
                }
                else
                    q.push(changed[i]);
            }
        }
        if(!q.empty())
            return empty;
        return res;
    }

    int search(vector<int>& nums, int left, int right, int target)
    {
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides)
    {
        return 0;
    }
};

int test1()
{
    Solution s;
    vector<int> nums = {1,2,2,1};
    int k = 1;
    cout << s.countKDifference(nums, k) << endl;
    return 0;
}

int test2()
{
    Solution s;
    vector<int> changed = {1,3,4,2,6,8};

    vector<int> out1 = s.findOriginalArray1(changed);
    for (auto ou : out1)
       cout << ou << " ";
    cout << endl;

    vector<int> out2 = s.findOriginalArray2(changed);
    for (auto ou : out2)
        cout << ou << " ";
    cout << endl;

    vector<int> out3 = s.findOriginalArray3(changed);
    for (auto ou : out3)
        cout << ou << " ";
    cout << endl;
    return 0;
}

int test3()
{
    Solution s;
    int n = 0;
    vector<vector<int>> rides = {};
    cout << s.maxTaxiEarnings(n, rides) << endl;
    return 0;
}

int main()
{
    cout << "------------------------" << endl;
    test1();
    cout << "------------------------" << endl;
    test2();
    cout << "------------------------" << endl;
    test3();
    cout << "------------------------" << endl;
    return 0;
}
