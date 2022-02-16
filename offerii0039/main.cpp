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
    // 暴力
    int largestRectangleArea1(vector<int>& heights) {
        int length = heights.size();
        int maxArea = 0;
        for (int i = 0; i < length; ++i) {
            int minHeight = INT_MAX;
            for (int j = i; j < length; ++j) {
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea, minHeight * (j - i + 1));
            }
        }
        return maxArea;
    }

    // 单调栈
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int maxArea = 0;
        stack<int> stk;
        stk.push(-1);

        for (int i = 0; i < heights.size(); ++i) {
            while (1 < stk.size() && heights[i] < heights[stk.top()]) {
                int height = heights[stk.top()];
                stk.pop();
                int width = i - stk.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            stk.push(i);
        }

        return maxArea;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> heights = {2,1,5,6,2,3};
    cout << s.largestRectangleArea(heights) << endl;
    cout << "---------------------" << endl;
    return 0;
}
