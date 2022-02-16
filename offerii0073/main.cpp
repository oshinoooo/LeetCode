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

        while (minSpeed < maxSpeed) {
            int speed = minSpeed + (maxSpeed - minSpeed) / 2;

            int totalTime = 0;
            for (auto& num : piles)
                totalTime += num / speed + (num % speed ? 1 : 0);

            if (totalTime <= h)
                maxSpeed = speed;
            else
                minSpeed = speed + 1;
        }

        return maxSpeed;
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
