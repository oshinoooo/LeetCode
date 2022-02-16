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
    int lastRemaining(int n) {
        int head = 1;
        int tail = n;
        int diff = 1;
        int count = n;

        while (count != 1) {
            head += diff;
            if (count % 2 == 1) {
                tail -= diff;
            }
            diff += diff;
            count /= 2;

            if (head == tail) {
                break;
            }

            tail -= diff;
            if (count % 2 == 1) {
                head += diff;
            }
            diff += diff;
            count /= 2;
        }

        return head;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.lastRemaining(6) << endl;
    cout << "---------------------" << endl;
    return 0;
}
