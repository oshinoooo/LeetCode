#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int prefix = 1;
        --k;

        while (0 < k) {
            int count = getCount(prefix, n);
            if (k <= count - 1) {
                --k;
                prefix *= 10;
            }
            else {
                k -= count;
                ++prefix;
            }
        }

        return prefix;
    }

private:
    int getCount(int prefix, int n) {
        long long count = 0;

        long long curr = prefix;
        long long next = prefix + 1;
        while (curr <= n) {
            count += min(next, (long long)n + 1) - curr;
            curr *= 10;
            next *= 10;
        }

        return count;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.findKthNumber(13, 9) << endl;
    cout << "---------------------" << endl;
    return 0;
}
