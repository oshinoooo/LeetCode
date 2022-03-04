#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea1(vector<int>& heights) {
        int n = heights.size();

        vector<int> left(n);
        stack<int> sta;
        for (int i = 0; i < n; ++i) {
            while (!sta.empty() && heights[i] <= heights[sta.top()])
                sta.pop();
            left[i] = sta.empty() ? -1 : sta.top();
            sta.push(i);
        }

        vector<int> right(n);
        sta = stack<int>();
        for (int i = n - 1; 0 <= i; --i) {
            while (!sta.empty() && heights[i] <= heights[sta.top()])
                sta.pop();
            right[i] = sta.empty() ? n : sta.top();
            sta.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; ++i)
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left(n);
        vector<int> right(n, n);
        stack<int> sta;

        for (int i = 0; i < n; ++i) {
            while (!sta.empty() && heights[i] <= heights[sta.top()]) {
                right[sta.top()] = i;
                sta.pop();
            }
            left[i] = (sta.empty() ? -1 : sta.top());
            sta.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; ++i)
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));

        return maxArea;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {2,1,5,6,2,3};
    cout << s.largestRectangleArea(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
