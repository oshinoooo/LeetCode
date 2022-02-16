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

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto& num : nums)
            add(num);
    }

    int add(int val) {
        que.push(val);
        if (k < que.size())
            que.pop();
        return que.top();
    }

private:
    priority_queue<int, vector<int>, greater<>> que;
    int k;
};

int main() {
    cout << "---------------------" << endl;
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(k, nums);
    cout << kthLargest.add(3) << endl;
    cout << kthLargest.add(5) << endl;
    cout << kthLargest.add(10) << endl;
    cout << kthLargest.add(9) << endl;
    cout << kthLargest.add(4) << endl;
    cout << "---------------------" << endl;
    return 0;
}
