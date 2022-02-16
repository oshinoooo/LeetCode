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

class Solution {
public:
    vector<double> dicesProbability(int n) {
        map<int, int> m = {{1, 1}, {2, 1}, {3, 1},
                           {4, 1}, {5, 1}, {6, 1}};

        for (int i = 1; i < n; ++i) {
            map<int, int> tmp;
            for (int j = 1; j <= 6; ++j) {
                for (auto& it : m) {
                    tmp[it.first + j] += it.second;
                }
            }
            m.swap(tmp);
        }

        vector<double> out;
        for (auto& it : m) {
            out.push_back((double)it.second / (double)pow(6, n));
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<double> out = s.dicesProbability(2);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
