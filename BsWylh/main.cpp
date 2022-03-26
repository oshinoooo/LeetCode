#include <iostream>
#include <vector>
#include <map>

using namespace std;

void test1() {
    int n;
    cin >> n;

    int m;
    cin >> m;

    int x;
    cin >> x;

    int y;
    cin >> y;

    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> nums[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum += nums[i][j];
        }
    }

    sum = sum - nums[x - 1][y - 1] + 1;

    cout << sum << endl;
}

void test2() {
    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int n;
        cin >> n;

        map<int, int> nums;
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            ++nums[tmp];
        }

        map<char, int> flowers;
        for (int j = 0; j < n; ++j) {
            char tmp;
            cin >> tmp;
            ++flowers[tmp];
        }

        int out = 1;

        if (5 == n && nums.size() == 1) {
            out *= 15000;
        }
        else if (4 == n && nums.size() == 1) {
            out *= 150;
        }
        else if (5 == n && nums.size() == 2 && (nums.begin()->second == 4 || nums.begin()->second == 1)) {
            out *= 150;
        }
        else if (5 == n && nums.size() == 2 && (nums.begin()->second == 3 || nums.begin()->second == 2)) {
            out *= 40;
        }
        else {
            for (auto [num, count] : nums) {
                if (count == 3) {
                    out *= 6;
                    break;
                }

                if (count == 2) {
                    out *= 2;
                }
            }
        }

        bool consist = true;
        if (nums.size() != 5) {
            consist = false;
        }
        else {
            int prev = nums.begin()->second;
            auto it = nums.begin();
            ++it;
            for (; it != nums.end(); ++it) {
                if (it->first != prev + 1) {
                    consist = false;
                    break;
                }
                prev = it->first;
            }
        }

        if (5 == n && flowers.size() == 1 && consist) {
            out *= 8000;
        }
        else if (5 == n && flowers.size() == 1 && !consist) {
            out *= 300;
        }
        else if (consist) {
            out *= 20;
        }

        cout << out << endl;
    }
}

void test3() {
    int n;
    cin >> n;

    int m;
    cin >> m;

    string tmp;
    vector<string> words;
    while (cin >> tmp) {
        words.push_back(tmp);
    }




    vector<string> strs;


    cout << strs.size();
    for (int i = 0; i < strs.size(); ++i) {
        cout << strs[i] << endl;
    }
}

vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool dfs(const vector<vector<int>>& heights,
         int x, int y, int z, int w,
         vector<vector<bool>>& visited, int time) {
    if (x == z && y == w)
        return true;

    visited[x][y] = true;

    int n = heights.size();
    int m = heights[0].size();

    for (int i = 0; i < directions.size(); ++i) {
        int nextX = directions[i][0] + x;
        int nextY = directions[i][1] + y;

        if (0 <= nextX && nextX < n &&
            0 <= nextY && nextY < m &&
            heights[nextX][nextY] <= time &&
            !visited[nextX][nextY]) {
            if (dfs(heights, nextX, nextY, z, w, visited, time)) {
                return true;
            }
        }
    }

    return false;
}

void test4() {
    int n;
    cin >> n;

    int m;
    cin >> m;

    int x;
    cin >> x;

    int y;
    cin >> y;

    int z;
    cin >> z;

    int w;
    cin >> w;

    vector<vector<int>> heights(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> heights[i][j];
        }
    }

    --x;
    --y;
    --z;
    --w;

    int time = max(heights[x][y], heights[z][w]);
    for (; time < n * m; ++time) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[x][y] = true;
        if (dfs(heights, x, y, z, w, visited, time)) {
            break;
        }
    }

    cout << time << endl;
}

int main() {
//    test1();
    test2();
//    test3();
//    test4();
    return 0;
}