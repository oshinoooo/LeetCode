#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> isMax(const vector<int>& stations, const int& extraStations) {
    vector<bool> out;

    int maxNum = 0;
    for (int i = 0; i < stations.size(); ++i) {
        maxNum = max(maxNum, stations[i]);
    }

    for (int i = 0; i < stations.size(); ++i) {
        if (maxNum <= stations[i] + extraStations)
            out.push_back(true);
        else
            out.push_back(false);
    }

    return out;
}

void test1() {
    string nums;
    getline(cin, nums);

    int start = 0;
    vector<int> stations;
    for (int i = 0; i < nums.size(); ++i) {
        if (i == nums.size() - 1 || nums[i + 1] == ' ') {
            stations.push_back(stoi(nums.substr(start, i - start + 1)));
            start = i + 2;
        }
    }

    int extraStations;
    cin >> extraStations;

    vector<bool> out = isMax(stations, extraStations);

    cout << '[';
    for (int i = 0; i < out.size(); ++i) {
        if (i != 0)
            cout << ", ";
        if (out[i])
            cout << "True";
        else
            cout << "False";
    }
    cout << ']' << endl;
}

long long getMax(const vector<vector<long long>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

//    vector<long long> rowSum(m, 1);
//    vector<long long> calSum(n, 1);
//
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            rowSum[i] *= grid[i][j];
//            calSum[j] *= grid[i][j];
//        }
//    }

    long long maxNum = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            long long tmp = 1;

            for (int k = 0; k < m; ++k) {
                if (k != i) {
                    tmp *= grid[k][j];
                }
            }

            for (int k = 0; k < n; ++k) {
                if (k != j) {
                    tmp *= grid[i][k];
                }
            }

            maxNum = max(maxNum, tmp);
        }
    }

    return maxNum;
}

void test2() {
    int m;
    cin >> m;

    int n;
    cin >> n;

    vector<vector<long long>> grid;
    for (int i = 0; i < m; ++i) {
        vector<long long> tmpGrid;
        for (int j = 0; j < n; ++j) {
            long long tmp;
            cin >> tmp;
            tmpGrid.push_back(tmp);
        }
        grid.push_back(tmpGrid);
    }

    cout << getMax(grid) << endl;
}

class Solution {
public:
    string chinese_number(int n) {
        if (n == 0)
            return "0";

        vector<string> units = {"", "s", "b", "q", "w", "ws", "wb", "wq"};

        string out;
        int digit = 0;

        while (n) {
            int tmp = n % 10;
            if (tmp) {
                out += units[digit++];

                if (digit != 0 || tmp != 1)
                    out.push_back(tmp + '0');
            }

            n /= 10;
        }

        reverse(out.begin(), out.end());

        return out;
    }
};

void test3() {
    Solution s;
    cout << s.chinese_number(111) << endl;
}

int main() {
//    test1();
//    test2();
    test3();
    return 0;
}
