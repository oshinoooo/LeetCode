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
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long planetMass = mass;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] <= planetMass)
                planetMass += asteroids[i];
            else
                return false;
        }
        return true;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    int mass = 10;
    vector<int> asteroids = {3,9,19,5,21};
    cout << s.asteroidsDestroyed(mass, asteroids) << endl;
    cout << "---------------------" << endl;
    return 0;
}
