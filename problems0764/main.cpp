#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines)
    {
        int max = 0;
        int distance = mines.size() % 2 == 1 ? mines.size() / 2 + 1 : mines.size() / 2;

        for (int i = 0; i < mines.size(); ++i)
        {
            for (int j = 0; j < mines.size(); ++j)
            {
                check(mines, i, j, i);
            }
        }
        return max;
    }

private:
    bool check(vector<vector<int>>& mines, int x, int y, int distance)
    {
        for (int i = x + 1 - distance; i < x + distance - 1; ++i)
        {
            if (mines[i][y] == 0)
                return false;
        }

        for (int i = y + 1 - distance; i < y + distance - 1; ++i)
        {
            if (mines[x][i] == 0)
                return false;
        }

        return true;
    }
};

int main()
{
    cout << "--------------------" << endl;
    Solution s;
    int n = 5;
    vector<vector<int>> mines = {{1, 1}, {1, 1}};
    cout << s.orderOfLargestPlusSign(n, mines) << endl;
    cout << "--------------------" << endl;
    return 0;
}
