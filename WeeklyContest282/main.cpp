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
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (const string& word : words) {
            if (pref == word.substr(0, pref.size()))
                ++count;
        }
        return count;
    }

    int minSteps(string s, string t) {
        unordered_map<char, int> m1;
        for (const char& c : s)
            ++m1[c];

        unordered_map<char, int> m2;
        for (const char& c : t)
            ++m2[c];

        for (auto [c, num] : m1)
            m2[c] -= num;

        int minStp = 0;
        for (auto [c, num] : m2)
            minStp += abs(m2[c]);

        return minStp;
    }

    long long minimumTime1(vector<int>& time, int totalTrips) {
        for (long long curTime = 1; curTime <= INT_MAX; ++curTime) {
            long long tmpTrips = 0;
            for (const int& t : time)
                tmpTrips += curTime / t;
            if (totalTrips <= tmpTrips)
                return curTime;
        }
        return -1;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long minTime = 1;
        long long maxTime = LONG_LONG_MAX;

        while (minTime <= maxTime) {
            long long midTime = minTime + (maxTime - minTime) / 2;

            long long tmpTrips = 0;
            for (const int& t : time) {
                tmpTrips += midTime / t;
                if (totalTrips <= tmpTrips)
                    break;
            }

            if (totalTrips <= tmpTrips)
                maxTime = midTime - 1;
            else
                minTime = midTime + 1;
        }

        return minTime;
    }

    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int minTime = INT_MAX;
        return minTime;
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> words = {"pay","attention","practice","attend"};
    cout << s.prefixCount(words, "at") << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.minSteps("leetcode", "coats") << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> time = {10000};
    int totalTrips = 10000000;
    cout << s.minimumTime(time, totalTrips) << endl;
    return 0;
}

int test4() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> tires = {{2, 3}, {3, 4}};
    int changeTime = 5;
    int numLaps = 4;
    cout << s.minimumFinishTime(tires, changeTime, numLaps) << endl;
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
