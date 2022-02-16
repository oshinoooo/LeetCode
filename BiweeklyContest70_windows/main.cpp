#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());

        int sum = 0;
        int flag = 1;
        for (int i = cost.size() - 1; 0 <= i; --i) {
            if (flag++ % 3 == 0)
                continue;
            sum += cost[i];
        }
        return sum;
    }

    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long max_num = 0;
        long long min_num = 0;
        long long sum = 0;

        for (int i = 0; i < differences.size(); ++i) {
            sum += differences[i];
            max_num = max(max_num, sum);
            min_num = min(min_num, sum);
        }

        int range1 = abs(upper - lower);
        int range2 = abs(max_num - min_num);

        if (range1 < range2)
            return 0;

        return range1 - range2 + 1;
    }

    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        queue<vector<int>> que;
        que.push({start[0], start[1], 0});
        grid[start[0]][start[1]] = -grid[start[0]][start[1]];
        vector<vector<int>> goods;

        while (!que.empty()) {
            int x = que.front()[0];
            int y = que.front()[1];
            int step = que.front()[2];
            que.pop();

            if(pricing[0] <= -grid[x][y] && -grid[x][y] <= pricing[1])
                goods.push_back({step, -grid[x][y], x, y});

            for (int i = 0; i < 4; ++i) {
                int nextX = x + dx[i];
                int nextY = y + dy[i];
                if (0 <= nextX && nextX < grid.size() && 0 <= nextY && nextY < grid[0].size() && 0 < grid[nextX][nextY]) {
                    grid[nextX][nextY] = -grid[nextX][nextY];
                    que.push({nextX, nextY, step + 1});
                }
            }
        }

        sort(goods.begin(), goods.end());
        vector<vector<int>> out;
        for (int i = 0; i < min(k, (int)goods.size()); ++i)
            out.push_back({goods[i][2], goods[i][3]});
        return out;
    }

    int numberOfWays(string corridor) {
        vector<vector<int>> seatsPositions;
        vector<int> seats;
        for (int i = 0; i < corridor.size(); ++i) {
            if (corridor[i] == 'S') {
                seats.push_back(i);
                if (seats.size() == 2) {
                    seatsPositions.push_back(seats);
                    seats.clear();
                }
            }
        }

        if (seatsPositions.empty() || !seats.empty())
            return 0;

        if (seatsPositions.size() == 1)
            return 1;

        long long count = 1;
        for (int i = 1; i < seatsPositions.size(); ++i)
            count = ((seatsPositions[i][0] - seatsPositions[i - 1][1]) * count) % 1000000007;
        return count;
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> cost = {6,5,7,9,2,2};
    cout << s.minimumCost(cost) << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> differences = {-40};
    cout << s.numberOfArrays(differences, -46, 53) << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> grid = {{1,2,0,1},{1,3,0,1},{0,2,5,1}};
    vector<int> pricing = {2, 5};
    vector<int> start = {0, 0};
    int k = 3;
    vector<vector<int>> out = s.highestRankedKItems(grid, pricing, start, k);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    return 0;
}

int test4() {
    cout << "---------------------" << endl;
    Solution s;
    string corridor = "PPPPPSPPSPPSPPPSPPPPSPPPPSPPPPSPPSPPPSPSPPPSPSPPPSPSPPPSPSPPPPSPPPPSPPPSPPSPPPPSPSPPPPSPSPPPPSPSPPPSPPSPPPPSPSPSS";
    cout << s.numberOfWays(corridor) << endl;
    return 0;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    cout << "---------------------" << endl;
    return 0;
}
