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
    int countPairs(vector<int>& nums, int k) {
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j] && ((i * j) % k) == 0)
                    ++count;
            }
        }

        return count;
    }

    vector<long long> sumOfThree(long long num) {
        vector<long long> out;
        if (num % 3 == 0)
            out = {num / 3 - 1, num / 3, num / 3 + 1};
        return out;
    }

    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 == 1)
            return {};

        vector<long long> out;
        long long total = 0;
        for (long long i = 2; i <= finalSum; i += 2) {
            if (total + i <= finalSum) {
                total += i;
                out.push_back(i);
            }
            else {
                out.back() += finalSum - total;
                break;
            }
        }

        return out;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int length = nums1.size();

        unordered_map<int, int> um;
        for (int i = 0; i < length; ++i)
            um[nums2[i]] = i;

        long long count = 0;
        for (int i = 0; i < length - 2; ++i) {
            for (int j = i + 1; j < length - 1; ++j) {
                if (um[nums1[i]] < um[nums1[j]]) {
                    for (int k = j + 1; k < length; ++k) {
                        if (um[nums1[j]] < um[nums1[k]])
                            ++count;
                    }
                }
            }
        }

        return count;
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {3,1,2,2,2,1,3};
    int k = 2;
    cout << s.countPairs(nums, k) << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    vector<long long> out = s.sumOfThree(33);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution s;
    vector<long long> out = s.maximumEvenSplit(6);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int test4() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums1 = {2,0,1,3};
    vector<int> nums2 = {0,1,2,3};
    cout << s.goodTriplets(nums1, nums2) << endl;
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
