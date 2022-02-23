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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> out;

        for (int i = 0; i < asteroids.size(); ++i) {
            if (0 < asteroids[i])
                out.push_back(asteroids[i]);
            else if (0 > asteroids[i]) {
                while (!out.empty() && 0 < out.back() && abs(out.back()) < abs(asteroids[i]))
                    out.pop_back();

                if (!out.empty() && 0 < out.back()) {
                    if (abs(out.back()) == abs(asteroids[i]))
                        out.pop_back();
                }
                else
                    out.push_back(asteroids[i]);
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> asteroids = {-2, -2, 1, -2};
    vector<int> out = s.asteroidCollision(asteroids);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
