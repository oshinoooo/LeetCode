#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int almostSame(vector<int>& nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (diff(nums[i], nums[j]))
                    ++count;
            }
        }

        return count;
    }

private:
    bool diff(int a, int b)
    {
        map<int, int> m_a;
        while (a > 0)
        {
            ++m_a[a % 10];
            a /= 10;
        }

        int count = 0;
        while (b > 0)
        {
            if (m_a.count(b % 10) == 0 || m_a[b % 10] <= 0)
            {
                ++count;
            }
            else
            {
                --m_a[b % 10];
            }
            b /= 10;
        }
        return count == 1;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {121, 122, 221, 222};
    cout << s.almostSame(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
