#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (num == 0)
            return true;

        if (num % 10 == 0)
            return false;
        else
            return true;
    }

    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> out;
        for (int i = 0; i < s.size(); ++i) {
            int count = 0;
            pair<int, int> pos = {startPos[0], startPos[1]};
            for (int j = i; j < s.size(); ++j) {
                if (s[j] == 'U') {
                    --pos.first;
                }
                else if (s[j] == 'D') {
                    ++pos.first;
                }
                else if (s[j] == 'L') {
                    --pos.second;
                }
                else if (s[j] == 'R') {
                    ++pos.second;
                }

                if (pos.first < n && 0 <= pos.first && pos.second < n && 0 <= pos.second) {
                    ++count;
                }
                else {
                    break;
                }
            }
            out.push_back(count);
        }
        return out;
    }

    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < arr.size(); ++i) {
            m[arr[i]].push_back(i);
        }

        vector<long long> out(arr.size());
        for (auto& num : m) {
            for (int i = 0; i < num.second.size(); ++i) {
                long long count = 0;
                for (int j = 0; j < num.second.size(); ++j) {
                    count += abs(num.second[i] - num.second[j]);
                }
                out[num.second[i]] = count;
            }
        }

        return out;
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.isSameAfterReversals(1800) << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    int n = 3;
    vector<int> startPos = {0, 1};
    string str = "RRDDLU";
    vector<int> out = s.executeInstructions(n, startPos, str);
    for (auto str : out)
        cout << str << " ";
    cout << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> arr = {2,1,3,1,2,3,3};
    vector<long long> out = s.getDistances(arr);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int main() {
    test1();
    test2();
    test3();
    cout << "---------------------" << endl;
    return 0;
}
