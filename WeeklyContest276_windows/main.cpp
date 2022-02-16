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
    vector<string> divideString(string s, int k, char fill) {
        vector<string> out;
        if (k <= s.size()) {
            for (int i = 0; i <= s.size() - k; i += k)
                out.push_back(s.substr(i, k));
        }

        int tailLength = s.size() % k;
        if (tailLength) {
            string tmp(k - tailLength, fill);
            out.push_back(s.substr(s.size() - tailLength, tailLength) + tmp);
        }
        return out;
    }

    int minMoves(int target, int maxDoubles) {
        int count = 0;
        while (1 < target) {
            if (maxDoubles--) {
                count += target % 2 + 1;
                target /= 2;
            }
            else {
                count += target - 1;
                break;
            }
        }
        return count;
    }

    long long mostPoints1(vector<vector<int>>& questions) {
        return myMostPoints(questions, 0);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int length = questions.size();

        vector<long long> dp(length, 0);
        for (int i = 0; i < length; ++i) {
            int next = i + 1;
            if (next < length)
                dp[next] = max(dp[next], dp[i]);

            next = i + questions[i][1] + 1;
            dp[i] += questions[i][0];
            if (next < dp.size())
                dp[next] = max(dp[next], dp[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }

private:
    long long myMostPoints(vector<vector<int>>& questions, int index) {
        if (questions.size() <= index)
            return 0;

        long long points1 = myMostPoints(questions, index + questions[index][1] + 1);
        long long points2 = myMostPoints(questions, index + 1);
        return max(questions[index][0] + points1, points2);
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> out = s.divideString("1234567890", 10, 'x');
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.minMoves(19, 2) << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> questions = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    cout << s.mostPoints(questions) << endl;
    return 0;
}

int test4() {
    cout << "---------------------" << endl;
    Solution s;
//    cout << "" << endl;
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
