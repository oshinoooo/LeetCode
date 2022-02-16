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
    int numberOfSteps(int num) {
        int count = 0;
        while (0 < num) {
            if (num % 2)
                --num;
            else
                num /= 2;
            ++count;
        }
        return count;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.numberOfSteps(14) << endl;
    cout << "---------------------" << endl;
    return 0;
}
