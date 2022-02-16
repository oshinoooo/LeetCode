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

class Solution
{
public:
    int minEatingSpeed1(vector<int>& piles, int h)
    {
        int lo = 1;
        int hi = pow(10, 9);

        while (lo < hi)
        {
            int mi = lo + (hi - lo) / 2;
            if (!possible(piles, h, mi))
                lo = mi + 1;
            else
                hi = mi;
        }

        return lo;
    }

    bool possible(vector<int>& piles, int H, int K)
    {
        int time = 0;
        for (int p: piles)
            time += (p - 1) / K + 1;
        return time <= H;
    }

    int minEatingSpeed(vector<int>& piles, int h)
    {
        sort(piles.begin(), piles.end());

        int speed;
        int move_times = 0;
        for (speed = 1; speed <= piles.back(); ++speed)
        {
            for (auto pile : piles)
                move_times += (pile - 1) / speed + 1;
            if (move_times <= h)
                return speed;
        }

        return piles.back();
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout << s.minEatingSpeed(piles, h) << endl;
    cout << "---------------------" << endl;
    return 0;
}
