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
#include <math.h>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());

        for (auto& num : nums) {
            if (num == original)
                original *= 2;
        }

        return original;
    }

    vector<int> maxScoreIndices(vector<int>& nums) {
        int length = nums.size();

        vector<int> left(length + 1);
        int count = 0;
        for (int i = 0; i < length; ++i) {
            left[i] = count;
            if (nums[i] == 0)
                ++count;
        }
        left.back() = count;

        vector<int> right(length + 1);
        count = 0;
        for (int i = length - 1; 0 <= i; --i) {
            if (nums[i] == 1)
                ++count;
            right[i] = count;
        }
        right.back() = 0;

        int maxPoint = 0;
        vector<int> out;
        for (int i = 0; i < length + 1; ++i) {
            int tmp = left[i] + right[i];
            if (maxPoint < tmp) {
                maxPoint = tmp;
                out.clear();
                out.push_back(i);
            }
            else if (maxPoint == tmp)
                out.push_back(i);
        }

        return out;
    }

    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int length = s.size();

        vector<long long> p(k, 1);
        for (int i = 1; i < k; ++i)
            p[i] = (p[i - 1] * power) % modulo;

        vector<long long> hash;
        for (int i = 0; i < length; ++i) {
            hash.push_back(s[i] - 'a' + 1);

            if (k - 1 <= i) {
                int start = i - k + 1;
                int sumHash = 0;
                for (int j = 0; j < k; ++j) {
                    sumHash = (sumHash + hash[start + j] * p[j]) % modulo;
                    if (sumHash == hashValue)
                        return s.substr(start, k);
                }
            }
        }

        return "";
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {5,3,6,1,12};
    cout << s.findFinalValue(nums, 3) << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {0,0,1,0};
    vector<int> out = s.maxScoreIndices(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution solution;
    cout << solution.subStrHash("xxterzixjqrghqyeketqeynekvqhc", 15, 94, 4, 16) << endl;
    return 0;
}

int test4() {
    cout << "---------------------" << endl;
    Solution s;
//    vector<vector<int>> statements = {{2, 1, 2},
//                                      {1, 2, 2},
//                                      {2, 0, 2}};
//    cout << s.maximumGood(statements) << endl;
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
