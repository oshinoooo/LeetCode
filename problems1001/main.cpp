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
#include <ctime>

using namespace std;

class Solution {
public:
    vector<int> gridIllumination1(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> m;
        for (auto& lamp : lamps)
            m[lamp[0]] = lamp[1];



        vector<vector<int>> isLighted(n, vector<int>(n, 0));

        lightUp(isLighted, lamps);


        vector<int> out;

        return out;
    }

    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries) {
        unordered_map<int, int> row, col, diagonal, antiDiagonal;
        auto hash_p = [](const pair<int, int> &p) -> size_t {
            static hash<long long> hash_ll;
            return hash_ll(p.first + (static_cast<long long>(p.second) << 32));
        };

        unordered_set<pair<int, int>, decltype(hash_p)> points(0, hash_p);
        for (auto &lamp : lamps) {
            if (points.count({lamp[0], lamp[1]}) > 0) {
                continue;
            }
            points.insert({lamp[0], lamp[1]});
            row[lamp[0]]++;
            col[lamp[1]]++;
            diagonal[lamp[0] - lamp[1]]++;
            antiDiagonal[lamp[0] + lamp[1]]++;
        }
        vector<int> ret(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int r = queries[i][0], c = queries[i][1];
            if (row.count(r) > 0 && row[r] > 0) {
                ret[i] = 1;
            } else if (col.count(c) > 0 && col[c] > 0) {
                ret[i] = 1;
            } else if (diagonal.count(r - c) > 0 && diagonal[r - c] > 0) {
                ret[i] = 1;
            } else if (antiDiagonal.count(r + c) > 0 && antiDiagonal[r + c] > 0) {
                ret[i] = 1;
            }
            for (int x = r - 1; x <= r + 1; x++) {
                for (int y = c - 1; y <= c + 1; y++) {
                    if (x < 0 || y < 0 || x >= n || y >= n) {
                        continue;
                    }
                    auto p = points.find({x, y});
                    if (p != points.end()) {
                        points.erase(p);
                        row[x]--;
                        col[y]--;
                        diagonal[x - y]--;
                        antiDiagonal[x + y]--;
                    }
                }
            }
        }
        return ret;
    }

private:
    void lightUp(vector<vector<int>>& isLighted, vector<vector<int>>& lamps) {
        int n = isLighted.size();
        vector<pair<int, int>> directions = {{1, 1}, {-1, -1},
                                             {1, -1}, {-1, 1},
                                             {1, 0}, {-1, 0},
                                             {0,1 }, {0, -1}};
        for (auto& lamp : lamps) {
            for (int i = 0; i < directions.size(); ++i) {
                int x = lamp[0];
                int y = lamp[1];
                while (0 <= x && x < n && 0 <= y && y < n) {
                    isLighted[x][y] = 1;
                    x += directions[i].first;
                    y += directions[i].second;
                }
            }
        }
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    int n = 5;
    vector<vector<int>> lamps = {{0, 0}, {4, 4}};
    vector<vector<int>> queries = {{1, 1}, {1, 0}};
    vector<int> out = s.gridIllumination(n, lamps, queries);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
