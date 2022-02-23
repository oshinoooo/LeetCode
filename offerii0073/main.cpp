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
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1;
        int maxSpeed = INT_MAX;

        while (minSpeed <= maxSpeed) {
            int curSpeed = minSpeed + (maxSpeed - minSpeed) / 2;

            int totalTime = 0;
            for (const auto& num : piles)
                totalTime += num / curSpeed + (num % curSpeed ? 1 : 0);

            if (h < totalTime)
                minSpeed = curSpeed + 1;
            else
                maxSpeed = curSpeed - 1;
        }

        return minSpeed;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> piles = {30,11,23,4,20};
    int h = 5;
    cout << s.minEatingSpeed(piles, h) << endl;
    cout << "---------------------" << endl;
    return 0;
}
