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

class Solution
{
public:
    vector<int> constructArr1(vector<int>& a)
    {
        vector<int> out;
        for (int i = 0; i < a.size(); ++i)
        {
            int mul = 1;
            for (int j = 0; j < a.size(); ++j)
            {
                if (i != j)
                    mul *= a[j];
            }
            out.push_back(mul);
        }
        return out;
    }

    vector<int> constructArr(vector<int>& a)
    {
        int length = a.size();

        vector<int> left(length, 1);
        for (int i = 1; i < length; ++i)
            left[i] = left[i - 1] * a[i - 1];

        vector<int> right(length, 1);
        for (int i = length - 2; 0 <= i; --i)
            right[i] = right[i + 1] * a[i + 1];

        vector<int> out;
        for (int i = 0; i < length; ++i)
            out.push_back(left[i] * right[i]);

        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    vector<int> out = s.constructArr(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
