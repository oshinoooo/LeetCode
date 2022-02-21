#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//工人在工地上搬砖。这里有N堆砖，第i堆中有stones[i] 块砖。监工已经离开了，将在 H 小时后回来。
//工人可以决定她搬砖的速度 K（单位：块/小时）。每个小时，她将会选择一堆砖，从中搬掉K快。
//如果这堆砖少于K块，他将搬完这堆所有的砖，然后这一小时内不会再搬更多的砖。
//工人喜欢慢慢搬，但仍然想在监工回来前搬完所有的砖。返回他可以在H小时内搬完所有的砖的最小速度K（K 为整数）。
//
//
//示例 1：
//输入: stones= [3,6,7,11], H = 8
//输出: 4
//
//示例 2：
//输入: stones= [30,11,23,4,20], H = 5
//输出: 30
//
//示例 3：
//输入: stones= [30,11,23,4,20], H = 6
//输出: 23
// 
//提示：
//1 <= stones.length <= 10^4
//stones.length <= H <= 10^9
//1 <= stones[i] <= 10^9

class Solution
{
public:
    int speed(vector<int> input, int h)
    {
        int max = INT_MIN;
        for (int i = 0; i < input.size(); ++i)
        {
            if (input[i] > max)
                max = input[i];
        }

        int sum = 0;
        for (int i = 0; i < input.size(); ++i)
        {
            for (int j = 1; j < max; ++j)
            {
                sum += j % input[i] + 1;
            }
        }

    }
};

int main()
{
    cout << "----------------" << endl;
    vector<int> in = {};
    Solution s;
    cout << s.speed({3,6,7,11}, 8) << endl;

    cout << "----------------" << endl;
    return 0;
}
