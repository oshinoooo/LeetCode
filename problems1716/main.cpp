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
    int totalMoney(int n) {
        return (n / 7 + 1 + n / 7 + n % 7) * (n % 7) / 2 + (28 + 21 + n / 7 * 7) * (n / 7) / 2;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.totalMoney(3) << endl;
    cout << "---------------------" << endl;
    return 0;
}
