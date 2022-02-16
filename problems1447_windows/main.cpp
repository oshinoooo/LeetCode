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
#include <ctime>

using namespace std;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> out;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (__gcd(j, i) == 1)
                    out.push_back(to_string(j) + "/" + to_string(i));
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> out = s.simplifiedFractions(6);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
