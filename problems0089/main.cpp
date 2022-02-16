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
    vector<int> grayCode(int n) {
        if (n == 0)
            return {0};

        vector<int> out = {0, 1};
        int length = pow(2, n);
        int adder = 0b10;

        while (out.size() < length) {
            out.insert(out.end(), out.rbegin(), out.rend());
            for (int i = out.size() / 2; i < out.size(); ++i)
                out[i] += adder;
            adder <<= 1;
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> out = s.grayCode(3);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
