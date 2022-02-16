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

class RecentCounter {
public:
    int ping(int t) {
        while (!nums.empty() && nums.front() < t - 3000)
            nums.pop();
        nums.push(t);
        return nums.size();
    }

private:
    queue<int> nums;
};

int main() {
    cout << "---------------------" << endl;
    RecentCounter recentCounter;
    cout << recentCounter.ping(1) << endl;
    cout << recentCounter.ping(100) << endl;
    cout << recentCounter.ping(3001) << endl;
    cout << recentCounter.ping(3002) << endl;
    cout << "---------------------" << endl;
    return 0;
}
