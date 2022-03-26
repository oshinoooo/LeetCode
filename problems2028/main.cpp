#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int allSum = (n + m) * mean;
        int tmpSum = accumulate(rolls.begin(), rolls.end(), 0);
        int gapSum = allSum - tmpSum;

        if (gapSum < n || n * 6 < gapSum)
            return {};

        int base = gapSum / n;
        int bias = gapSum % n;

        vector<int> out(n, base);
        for (int i = 0; i < bias; ++i)
            ++out[i];

        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> rolls = {1, 5, 6};
    vector<int> out = s.missingRolls(rolls, 3, 4);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}