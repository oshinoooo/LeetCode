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
    int catMouseGame(vector<vector<int>>& graph) {
        int out = 0;



        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> graph = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
    cout << s.catMouseGame(graph) << endl;
    cout << "---------------------" << endl;
    return 0;
}
