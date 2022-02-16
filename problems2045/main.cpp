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
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        int out = 0;



        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    int n = 5;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};
    int time = 3;
    int change = 5;
    cout << s.secondMinimum(n, edges, time, change) << endl;
    cout << "---------------------" << endl;
    return 0;
}
