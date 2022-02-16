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
    int mySqrt(int x) {
        long head = 0;
        long tail = x;

        while (head < tail) {
            long mid = tail + (head - tail) / 2;

            if (mid * mid <= x)
                head = mid;
            else
                tail = mid - 1;
        }

        return head;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.mySqrt(4) << endl;
    cout << "---------------------" << endl;
    return 0;
}
