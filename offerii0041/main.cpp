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

class MovingAverage {
public:
    MovingAverage(int size) {
        windowSize = size;
        sum = 0;
    }

    double next(int val) {
        if (windowSize <= nums.size()) {
            sum -= nums.front();
            nums.pop();
        }
        sum += val;
        nums.push(val);

        return (double)sum / (double)nums.size();
    }

private:
    queue<int> nums;
    int windowSize;
    int sum;
};

int main() {
    cout << "---------------------" << endl;
    MovingAverage movingAverage(3);
    cout << movingAverage.next(1) << endl;
    cout << movingAverage.next(10) << endl;
    cout << movingAverage.next(3) << endl;
    cout << movingAverage.next(5) << endl;
    cout << "---------------------" << endl;
    return 0;
}
