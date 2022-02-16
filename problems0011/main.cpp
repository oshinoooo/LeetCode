#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea1(vector<int>& height)
    {
        int max = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            for (int j = i + 1; j < height.size(); ++j)
            {
                int area = (j - i) * min(height[j], height[i]);
                max = max < area ? area : max;
            }
        }
        return max;
    }

    int maxArea2(vector<int>& height)
    {
        int result = 0;
        int head = 0;
        int tail = height.size() - 1;

        while (head < tail)
        {
            int area = min(height[tail], height[head]) * (tail - head);
            result = max(result, area);
            height[head] > height[tail] ? --tail : ++head;
        }

        return result;
    }
};

int main()
{
    cout << "-------------------" << endl;
    Solution s;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
//    cout << s.maxArea1(height) << endl;
    cout << s.maxArea2(height) << endl;
    cout << "-------------------" << endl;
    return 0;
}
