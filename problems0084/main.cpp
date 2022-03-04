#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left(n);
        stack<int> left_stack;
        for (int i = 0; i < n; ++i) {
            while (!left_stack.empty() && heights[i] <= heights[left_stack.top()])
                left_stack.pop();

            left[i] = (left_stack.empty() ? -1 : left_stack.top());
            left_stack.push(i);
        }

        vector<int> right(n);
        stack<int> right_stack;






        int maxArea = 0;



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
