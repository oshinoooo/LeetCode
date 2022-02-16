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

class DetectSquares {
public:
    void add(vector<int> point) {
        ++points[point[0]][point[1]];
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int count = 0;

        for (auto [newY, num] : points[x]) {
            int length = abs(y - newY);
            if (length == 0 || num == 0)
                continue;

            vector<int> xs = {x + length, x - length};
            for (auto& newX : xs) {
                int subCount = num;
                subCount *= points[newX][newY];
                subCount *= points[newX][y];
                count += subCount;
            }
        }

        return count;
    }

private:
    unordered_map<int, unordered_map<int, int>> points;
};

int main() {
    cout << "---------------------" << endl;
    DetectSquares detectSquares;
    detectSquares.add({3, 10});
    detectSquares.add({11, 2});
    detectSquares.add({3, 2});
    cout << detectSquares.count({11, 10}) << endl;
    cout << detectSquares.count({14, 8}) << endl;
    detectSquares.add({11, 2});
    cout << detectSquares.count({11, 10}) << endl;
    cout << "---------------------" << endl;
    return 0;
}
