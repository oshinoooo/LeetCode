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
    int divide(int a, int b) {
        if (a == 0)
            return 0;

        if (b == 1)
            return a;

        if (b == -1) {
            if (a == INT_MIN) {
                return INT_MAX;
            }
            else {
                return -a;
            }
        }

        int sign = 1;
        if (a > 0) {
            a = -a;
            sign = -sign;
        }

        if (b > 0) {
            b = -b;
            sign = -sign;
        }

        return my_divide(a, b) * sign;
    }

private:
    int my_divide(int a, int b) {
        if (b < a) {
            return 0;
        }

        int count = 1;
        int sum = b;
        while (-1073741824 <= sum && a <= sum + sum) {
            count += count;
            sum += sum;
        }

        return count + my_divide(a - sum, b);
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.divide(2147483647, 2)<< endl;
    cout << "---------------------" << endl;
    return 0;
}
