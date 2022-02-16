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
    Solution(vector<int>& w) {
        srand(time(0));
        int sum = 0;
        for (auto& num : w) {
            sum += num;
            interval.push_back(sum);
        }
    }

    int pickIndex() {
        int randomNum = rand() % interval.back() + 1;

//        return lower_bound(interval.begin(), interval.end(), randomNum) - interval.begin();

        int head = 0;
        int tail = interval.size() - 1;

        while (head <= tail) {
            int mid = head + (tail - head) / 2;

            if (randomNum <= interval[mid])
                tail = mid - 1;
            else
                head = mid + 1;
        }

        return head;
    }

private:
    vector<int> interval;
};

int main() {
    cout << "---------------------" << endl;
    vector<int> w = {1, 3};
    Solution s(w);
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << "---------------------" << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << "---------------------" << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << "---------------------" << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << "---------------------" << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << "---------------------" << endl;
    return 0;
}
