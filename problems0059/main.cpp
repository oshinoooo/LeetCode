#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        if (n == 0)
            return {};

        int cur_num = 1;
        int cur_row = 0;
        int cur_cal = 0;
        int destination = n / 2;

        vector<vector<bool>> visit(n, vector<bool>(n, false));
        vector<vector<int>> out(n, vector<int>(n));

        while (!visit[destination][destination])
        {
            while (cur_cal < n && !visit[cur_row][cur_cal])
            {
                out[cur_row][cur_cal] = cur_num;
                visit[cur_row][cur_cal] = true;
                ++cur_cal;
                ++cur_num;
            }
            --cur_cal;
            ++cur_row;

            while (cur_row < n && !visit[cur_row][cur_cal])
            {
                out[cur_row][cur_cal] = cur_num;
                visit[cur_row][cur_cal] = true;
                ++cur_row;
                ++cur_num;
            }
            --cur_row;
            --cur_cal;

            while (-1 < cur_cal && !visit[cur_row][cur_cal])
            {
                out[cur_row][cur_cal] = cur_num;
                visit[cur_row][cur_cal] = true;
                --cur_cal;
                ++cur_num;
            }
            ++cur_cal;
            --cur_row;

            while (-1 < cur_row && !visit[cur_row][cur_cal])
            {
                out[cur_row][cur_cal] = cur_num;
                visit[cur_row][cur_cal] = true;
                --cur_row;
                ++cur_num;
            }
            ++cur_row;
            ++cur_cal;
        }

        return out;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    vector<vector<int>> out = s.generateMatrix(3);
    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "-------------------------" << endl;
    return 0;
}
