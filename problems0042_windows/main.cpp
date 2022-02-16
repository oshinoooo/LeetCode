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
    int trap1(vector<int>& height) {
        int sum = 0;
        stack<int> stk;

        for (int i = 0; i < height.size(); ++i) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int index = stk.top();
                stk.pop();
                if (stk.empty())
                    break;

                int w = i - stk.top() - 1;
                int h = min(height[stk.top()], height[i]) - height[index];
                sum += h * w;
            }
            stk.push(i);
        }

        return sum;
    }

    int trap2(vector<int>& height) {
        int size = height.size();

        vector<int> leftMax(size, 0);
        for (int i = 1; i < size; ++i)
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);

        vector<int> rightMax(size, 0);
        for (int i = size - 2; 0 <= i; --i)
            rightMax[i] = max(rightMax[i + 1], height[i + 1]);

        int sum = 0;

        for (int i = 1; i < size - 1; ++i) {
            if (height[i] < leftMax[i] && height[i] < rightMax[i])
                sum += min(leftMax[i], rightMax[i]) - height[i];
        }

        return sum;
    }

    int trap(vector<int>& height) {
        int head = 0;
        int tail = height.size() - 1;
        int headMax = 0;
        int tailMax = 0;

        int sum = 0;

        while (head < tail) {
            headMax = max(headMax, height[head]);
            tailMax = max(tailMax, height[tail]);

            if (height[head] < height[tail])
                sum += headMax - height[head++];
            else
                sum += tailMax - height[tail--];
        }

        return sum;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(height) << endl;
    cout << "---------------------" << endl;
    return 0;
}
