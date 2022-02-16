#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        int length_x = min(ax2, bx2) - max(ax1, bx1);
        int length_y = min(ay2, by2) - max(ay1, by1);
        if (length_x > 0 && length_y > 0)
            area -= length_x * length_y;
        return area;
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    cout << s.computeArea(0, 0, 2, 2, 1, 1, 3, 3) << endl;
    cout << "---------------" << endl;
    return 0;
}
