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
    int numberOfMatches(int n) {
        int count = 0;
        while (1 < n) {
            count += n / 2;
            n -= n / 2;
        }
        return count;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.numberOfMatches(5) << endl;
    cout << "---------------------" << endl;
    return 0;
}
