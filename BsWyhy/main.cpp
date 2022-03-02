#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits.h>

using namespace std;

/*int calculate(string number) {
    const vector<int> mul = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

    int sum = 0;
    vector<int> starsIdex;
    for (int i = 0; i < number.size(); ++i) {
        if (number[i] != '*') {
            sum += (number[i] - '0') * mul[i];
        }
        else {
            starsIdex.push_back(i);
        }
    }

    int count = 0;
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < starsIdex.size(); ++i) {
            sum += j * starsIdex[i]
        }


        if ((sum + j * starsIdex[i]) % 11 == number.back() - '0') {
            ++count;
        }
    }



    return count;
}

int main() {
    int num;
    cin >> num;
    vector<string> numbers;
    for (int i = 0; i < num; ++i) {
        string tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }

    for (int i = 0; i < numbers.size(); ++i) {
        cout << calculate(numbers[i]) << endl;
    }
//    cout << (4 * 14) % 11 + (4 * 234) % 11 << endl;
//    cout << (4 * 14 + 4 * 234) % 11 << endl;
    return 0;
}*/

/*int dfs(const vector<vector<int>>& tasks, int taskNumber) {
    int time = tasks[taskNumber][0];

    int maxTime = 0;
    for (int i = 2; i < tasks[taskNumber].size(); ++i) {
        maxTime = max(maxTime, dfs(tasks, tasks[taskNumber][i] - 1));
    }
    time += maxTime;

    return time;
}

int test(vector<vector<int>>& tasks, int taskNumber) {
    int time = tasks[taskNumber][0];
    int maxTime = 0;
    for (int i = 2; i < tasks[taskNumber].size(); ++i) {
        maxTime = max(maxTime, tasks[tasks[taskNumber][i] - 1][0]);
    }
    time += maxTime;
    tasks[taskNumber][0] = time;
    return time;
}

int calculate(vector<vector<int>>& tasks) {
    int minTime = 0;

    for (int i = 0; i < tasks.size(); ++i) {
        minTime = max(minTime, test(tasks, i));
    }

    return minTime;
}

int main() {
    int T;
    cin >> T;

    vector<vector<vector<int>>> tasks;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;

        vector<vector<int>> task;
        for (int i = 0; i < N; ++i) {
            vector<int> tmp;
            int num;

            cin >> num;
            tmp.push_back(num);

            cin >> num;
            tmp.push_back(num);

            for (int j = 0; j < tmp[1]; ++j) {
                cin >> num;
                tmp.push_back(num);
            }

            task.push_back(tmp);
        }

        tasks.push_back(task);
    }

//    auto func = [](vector<int> a, vector<int> b) {
//        return a[1] < b[1];
//    };
//
//    for (int i = 0; i < tasks.size(); ++i) {
//        sort(tasks[i].begin(), tasks[i].end(), func);
//    }

    for (int i = 0; i < tasks.size(); ++i) {
        cout << calculate(tasks[i]) << endl;
    }

    return 0;
}*/

struct test {
    int N;
    vector<vector<int>> roads;
    vector<vector<int>> ports;
};

int calculate(const int& N, const vector<vector<int>>& roads, const vector<vector<int>>& ports) {
    unordered_map<int, vector<int>> m_roads;
    for (int i = 0; i < roads.size(); ++i) {
        if (roads[i][0] < roads[i][1])
            m_roads[roads[i][1]].push_back(roads[i][0]);
        else
            m_roads[roads[i][0]].push_back(roads[i][1]);
    }

    unordered_map<int, vector<int>> m_ports;
    for (int i = 0; i < ports.size(); ++i) {
        if (ports[i][0] < ports[i][1])
            m_ports[ports[i][1]].push_back(ports[i][0]);
        else
            m_ports[ports[i][0]].push_back(ports[i][1]);
    }

    vector<int> dp(N + 1, -1);
    vector<bool> flag(N + 1, false);
    dp[1] = 0;

    for (int i = 2; i < N + 1; ++i) {
        int tmp = INT_MAX;

        for (auto starts : m_roads[i]) {
            if (dp[starts] != -1)
                tmp = min(tmp, dp[starts] + 1);
        }

        for (auto starts : m_ports[i]) {
            if (dp[starts] != -1) {
                if (flag[starts] && dp[starts] + 1 < tmp) {
                    tmp = dp[starts] + 1;
                    flag[i] = true;
                }
                else if(!flag[i - 1] && dp[starts] < tmp) {
                    tmp = dp[starts];
                    flag[i] = true;
                }
            }
        }

        if (tmp != INT_MAX)
            dp[i] = tmp;
    }

    return dp.back();
}

int main() {
    int T;
    cin >> T;

    vector<test> tests;
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;

        int M1;
        cin >> M1;

        int M2;
        cin >> M2;

        vector<vector<int>> roads;
        for (int j = 0; j < M1; ++j) {
            int u;
            int v;
            cin >> u;
            cin >> v;
            roads.push_back({u, v});
        }

        vector<vector<int>> ports;
        for (int j = 0; j < M2; ++j) {
            int u;
            int v;
            cin >> u;
            cin >> v;
            ports.push_back({u, v});
        }

        tests.push_back({N, roads, ports});
    }

    for (int i = 0; i < tests.size(); ++i) {
        cout << calculate(tests[i].N, tests[i].roads, tests[i].ports) << endl;
    }

    return 0;
}