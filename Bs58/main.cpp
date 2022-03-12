#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxSubArrLength(vector<int>& arr) {
        int n = arr.size();

        map<int, int> mp;
        int start = 0;
        int tmpLength = 0;
        int maxLength = 0;
        for (int i = 0; i < n; ++i) {
            if (!mp.count(arr[i]) || mp[arr[i]] < start) {
                ++tmpLength;
                mp[arr[i]] = i;
            }
            else {
                start = mp[arr[i]] + 1;
                tmpLength = i - start + 1;
                mp[arr[i]] = i;
            }

            maxLength = max(maxLength, tmpLength);
        }

        return maxLength;
    }

    vector<vector<int>> process(vector<int>& allScoreArray,
                                int examCount,
                                int lastScore) {
        int n = allScoreArray.size();
        int sum = 0;
        vector<int> tmp;
        vector<bool> used(n, false);
        vector<vector<int>> out;
        myProcess(allScoreArray, examCount, lastScore, sum, tmp, used, out);
        return out;
    }

    void myProcess(const vector<int>& allScoreArray,
                   const int& examCount,
                   const int& lastScore,
                   int& sum,
                   vector<int>& tmp,
                   vector<bool>& used,
                   vector<vector<int>>& out) {
        if (tmp.size() == examCount - 1) {
            tmp.push_back(lastScore);
            if ((sum + lastScore) % examCount == 0)
                out.push_back(tmp);
            tmp.pop_back();
            return;
        }

        int n = allScoreArray.size();

        for (int i = 0; i < n; ++i) {
            if (!used[i] && allScoreArray[i] != lastScore) {
                used[i] = true;
                tmp.push_back(allScoreArray[i]);
                sum += allScoreArray[i];

                if (sum % tmp.size() == 0)
                    myProcess(allScoreArray, examCount, lastScore, sum, tmp, used, out);

                sum -= allScoreArray[i];
                tmp.pop_back();
                used[i] = false;
            }
        }
    }

    int getCount(int m) {
        vector<int> dp(m + 4, 0);
        dp[1] = 1;

        for (int i = 1; i <= m; ++i) {
            dp[i + 1] += dp[i];

            if (i % 2)
                dp[i + 2] += dp[i];
            else
                dp[i + 3] += dp[i];
        }

        return dp[m];
    }
};

int main() {
    Solution s;

    cout << "--------------------" << endl;
    vector<int> arr = {1,2,3,1,2,3,2,2};
    cout << s.maxSubArrLength(arr) << endl;

    cout << "--------------------" << endl;
    vector<int> allScoreArray = {3,4,5,6,7,8,9,10};
    int examCount = 6;
    int lastScore = 6;
    vector<vector<int>> out = s.process(allScoreArray, examCount, lastScore);
    for (auto nums : out) {
        for (auto num : nums)
            cout << num << " ";
        cout << endl;
    }

    cout << "--------------------" << endl;
    cout << s.getCount(2) << endl;

    cout << "--------------------" << endl;
    return 0;
}
