#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <math.h>

using namespace std;

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>>& points)
    {
        int sum = 0;
        for (auto &point1 : points)
        {
            unordered_map<int, int> count;
            for (auto &point2 : points)
            {
                int distance = pow((point1[0] - point2[0]), 2) + pow((point1[1] - point2[1]), 2);
                ++count[distance];
            }

            for (auto c : count)
                sum += c.second * (c.second - 1);
        }
        return sum;
    }
};

int main()
{
    cout << "-----------------" << endl;
    Solution s;
    vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
    cout << s.numberOfBoomerangs(points) << endl;
    cout << "-----------------" << endl;
    return 0;
}
