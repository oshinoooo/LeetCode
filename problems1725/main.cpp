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
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int count = 0;
        int maxLength = 0;

        for (auto& rectangle : rectangles) {
            int length = min(rectangle[0], rectangle[1]);
            if (length == maxLength)
                ++count;
            else if (maxLength < length) {
                maxLength = length;
                count = 1;
            }
        }

        return count;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> rectangles = {{5, 8}, {3, 9}, {5, 12}, {16, 5}};
    cout << s.countGoodRectangles(rectangles) << endl;
    cout << "---------------------" << endl;
    return 0;
}
