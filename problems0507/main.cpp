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
    bool checkPerfectNumber(int num) {
        if (num == 1)
            return false;

        int sum = 0;
        for (int i = 1; i <= sqrt(num); ++i) {
            if (num % i == 0)
                sum += i + num / i;
        }

        if (sum - num == num)
            return true;
        return false;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.checkPerfectNumber(25) << endl;
    cout << "---------------------" << endl;
    return 0;
}
