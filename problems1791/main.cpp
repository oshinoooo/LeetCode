#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][1] == edges[1][0] ? edges[1][0] : edges[1][1];
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    cout << s.findCenter(edges) << endl;
    cout << "---------------------" << endl;
    return 0;
}
