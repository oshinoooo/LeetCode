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
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_set<int> s1;
        for (int i = 1; i <= n; ++i)
            s1.insert(i);

        for (int i = 0; i < n; ++i) {
            unordered_set<int> s2;
            unordered_set<int> s3;
            for (int j = 0; j < n; ++j) {
                s2.insert(matrix[i][j]);
                s3.insert(matrix[j][i]);
            }

            if (s1 != s2 || s1 != s3)
                return false;
        }

        return true;
    }

    int minSwaps(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == nums.size() || sum == 0 || sum == 1)
            return 0;

        nums.insert(nums.end(), nums.begin(), nums.end());

        int min_zeros = INT_MAX;
        int cur_zeros = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)
                ++cur_zeros;

            if (sum <= i) {
                if (nums[i - sum] == 0)
                    --cur_zeros;

                min_zeros = min(min_zeros, cur_zeros);
            }
        }

        return min_zeros;
    }

    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> masks;
        for (auto& startWord : startWords) {
            int binary = toBinary(startWord);
            for (int i = 0; i < 26; ++i) {
                int tmp = binary | (1 << i);
                if (tmp != binary)
                    masks.insert(tmp);
            }

        }

        int count = 0;
        for (auto& targetWord : targetWords) {
            if (masks.count(toBinary(targetWord)))
                ++count;
        }

        return count;
    }

private:
    int toBinary(string word) {
        int out = 0;
        for (auto& c : word)
            out += (1 << (c - 'a'));
        return out;
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> matrix = {{15,7,18,11,19,10,14,16,8,2,3,6,5,1,17,12,9,4,13},
                                  {17,15,9,8,11,13,7,6,5,1,3,16,12,19,10,2,4,14,18},
                                  {19,14,12,10,8,9,17,16,4,3,13,18,1,5,7,11,2,15,6},
                                  {4,2,10,15,19,16,8,9,5,3,1,11,13,14,6,18,12,17,7},
                                  {13,19,9,16,5,8,6,12,14,11,18,10,7,2,3,4,15,17,1},
                                  {4,7,18,11,17,16,5,12,10,1,15,13,14,6,19,2,3,9,8},
                                  {14,5,15,1,18,6,12,7,8,9,3,13,2,10,19,4,11,16,17},
                                  {10,3,1,8,14,19,11,18,15,13,9,12,16,17,7,4,5,2,6},
                                  {14,13,19,18,7,2,4,8,10,17,12,5,15,1,6,9,11,3,16},
                                  {19,8,10,18,16,12,11,17,4,9,7,2,5,13,15,3,6,1,14},
                                  {1,10,6,14,7,18,3,9,4,16,5,11,13,17,15,8,19,2,12},
                                  {13,10,5,16,1,19,17,3,9,11,7,8,12,6,4,2,14,15,18},
                                  {17,2,1,6,9,19,18,14,4,11,12,13,16,5,8,7,3,10,15},
                                  {1,4,10,5,13,6,18,11,3,2,15,14,16,12,17,19,8,9,7},
                                  {2,14,3,12,16,17,11,9,1,6,5,19,10,13,4,18,7,15,8},
                                  {15,9,8,18,14,13,4,12,5,17,6,1,11,16,19,3,7,2,10},
                                  {15,8,12,16,13,2,6,19,18,14,10,5,11,9,7,1,3,17,4},
                                  {15,6,17,7,5,3,1,9,19,12,10,11,16,14,18,8,2,13,4},
                                  {6,11,10,14,2,13,16,1,9,15,8,19,17,3,5,18,7,4,12}};
    cout << s.checkValid(matrix) << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {0,1,0,1,1,0,0};
    cout << s.minSwaps(nums) << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> startWords = {"ant","act","tack"};
    vector<string> targetWords = {"tack","act","acti"};
    cout << s.wordCount(startWords, targetWords) << endl;
    return 0;
}

int test4() {
        cout << "---------------------" << endl;
        Solution s;
        cout << "" << endl;
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
