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

        for (auto& asteroid : asteroids) {
            if (out.empty() || asteroid > 0 || out.back() < 0) {
                out.push_back(asteroid);
            }
            else if (asteroid < 0) {
                while (!out.empty() && out.back() > 0) {
                    if (out.back() > abs(asteroid)) {
                        break;
                    }
                    else if (out.back() == abs(asteroid)) {
                        out.pop_back();
                        break;
                    }
                    else {
                        out.pop_back();
                        if (out.empty() || out.back() < 0) {
                            out.push_back(asteroid);
                        }
                    }
                }
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> asteroids = {-2,-2,1,-2};
    vector<int> out = s.asteroidCollision(asteroids);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
