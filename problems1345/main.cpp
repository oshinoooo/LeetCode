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
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> nodes;
        for (int i = 0; i < arr.size(); ++i)
            nodes[arr[i]].push_back(i);

        unordered_set<int> visited;
        visited.emplace(0);

        queue<pair<int, int>> que;
        que.emplace(0, 0);

        while (!que.empty()) {
            auto [index, step] = que.front();
            que.pop();

            if (index == arr.size() - 1)
                return step;

            int value = arr[index];
            step++;

            if (nodes.count(value)) {
                for (auto & i : nodes[value]) {
                    if (!visited.count(i)) {
                        visited.emplace(i);
                        que.emplace(i, step);
                    }
                }
                nodes.erase(value);
            }

            if (index + 1 < arr.size() && !visited.count(index + 1)) {
                visited.emplace(index + 1);
                que.emplace(index + 1, step);
            }

            if (0 <= index - 1 && !visited.count(index - 1)) {
                visited.emplace(index - 1);
                que.emplace(index - 1, step);
            }
        }

        return -1;
    }

    void BFS(vector<int>& arr) {
        unordered_map<int, vector<int>> nodes;
        for (int i = 0; i < arr.size(); ++i)
            nodes[arr[i]].push_back(i);

        unordered_set<int> visited;
        visited.emplace(0);

        queue<int> que;
        que.emplace(0);

        while (!que.empty()) {
            int index = que.front();
            que.pop();

            cout << index << " : " << arr[index] << endl;

            if (0 <= index - 1 && !visited.count(index - 1)) {
                que.emplace(index - 1);
                visited.emplace(index - 1);
            }

            if (index + 1 < arr.size() && !visited.count(index + 1)) {
                que.emplace(index + 1);
                visited.emplace(index + 1);
            }

            for (auto& i : nodes[arr[index]]) {
                if (!visited.count(i)) {
                    que.push(i);
                    visited.emplace(i);
                }
            }
        }
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    cout << s.minJumps(arr) << endl;
    cout << "---------------------" << endl;
    s.BFS(arr);
    cout << "---------------------" << endl;
    return 0;
}
