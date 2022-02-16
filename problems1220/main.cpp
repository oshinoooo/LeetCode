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
    int countVowelPermutation1(int n) {
        int count = 0;
        count = (count + myCountVowelPermutation(n - 1, 'a')) % 1000000007;
        count = (count + myCountVowelPermutation(n - 1, 'e')) % 1000000007;
        count = (count + myCountVowelPermutation(n - 1, 'i')) % 1000000007;
        count = (count + myCountVowelPermutation(n - 1, 'o')) % 1000000007;
        count = (count + myCountVowelPermutation(n - 1, 'u')) % 1000000007;
        return count;
    }

    int countVowelPermutation(int n) {
        long long mod = 1000000007;
        vector<long long> pre(5, 1);
        vector<long long> cur(5, 0);

        while (0 < --n) {
            cur[0] = (pre[1] + pre[2] + pre[4]) % mod;
            cur[1] = (pre[0] + pre[2]) % mod;
            cur[2] = (pre[1] + pre[3]) % mod;
            cur[3] = (pre[2]) % mod;
            cur[4] = (pre[2] + pre[3]) % mod;
            pre = cur;
        }

        return accumulate(pre.begin(), pre.end(), 0) % mod;
    }

private:
    int myCountVowelPermutation(int n, char c) {
        if (n <= 0)
            return 1;

        int count = 0;
        if (c == 'a')
            count = (count + myCountVowelPermutation(n - 1, 'e')) % 1000000007;
        else if (c == 'e') {
            count = (count + myCountVowelPermutation(n - 1, 'a')) % 1000000007;
            count = (count + myCountVowelPermutation(n - 1, 'i')) % 1000000007;
        }
        else if (c == 'i') {
            count = (count + myCountVowelPermutation(n - 1, 'a')) % 1000000007;
            count = (count + myCountVowelPermutation(n - 1, 'e')) % 1000000007;
            count = (count + myCountVowelPermutation(n - 1, 'o')) % 1000000007;
            count = (count + myCountVowelPermutation(n - 1, 'u')) % 1000000007;
        }
        else if (c == 'o') {
            count = (count + myCountVowelPermutation(n - 1, 'i')) % 1000000007;
            count = (count + myCountVowelPermutation(n - 1, 'u')) % 1000000007;
        }
        else if (c == 'u')
            count = (count + myCountVowelPermutation(n - 1, 'a')) % 1000000007;

        return count;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.countVowelPermutation(4) << endl;
    cout << "---------------------" << endl;
    return 0;
}
