#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        map<int, int> m;
        for (auto& num : nums)
            ++m[num];

        if (m.size() < 2)
            return 0;

        int count = 0;
        for (auto& num : m)
            count += num.second;

        return count - m.begin()->second - m.rbegin()->second;
    }

    vector<int> rearrangeArray(vector<int>& nums) {
        int ptr1 = 0;
        int ptr2 = 0;
        vector<int> out;

        while (out.size() < nums.size()) {
            while (nums[ptr1] < 0)
                ++ptr1;
            out.push_back(nums[ptr1++]);

            while (0 < nums[ptr2])
                ++ptr2;
            out.push_back(nums[ptr2++]);
        }

        return out;
    }

    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto& num : nums)
            ++m[num];

        vector<int> out;
        for (auto [index, value] : m) {
            if (value == 1 && m.count(index - 1) == 0 && m.count(index + 1) == 0)
                out.push_back(index);
        }

        return out;
    }

    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();

        int out = 0;



        return out;
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {11,7,2,15};
    cout << s.countElements(nums) << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {3,1,-2,-5,2,-4};
    vector<int> out = s.rearrangeArray(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {10,6,5,8};
    vector<int> out = s.findLonely(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int test4() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> statements = {{2, 1, 2},
                                      {1, 2, 2},
                                      {2, 0, 2}};
    cout << s.maximumGood(statements) << endl;
    return 0;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    cout << "---------------------" << endl;
    return 0;
}
