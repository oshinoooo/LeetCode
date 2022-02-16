#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int perimeter = 0;

        int rows = grid.size();
        int columns = grid[0].size();

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (grid[i][j] == 1)
                {
                    perimeter += 4;

                    if (i != 0 && grid[i - 1][j] == 1)
                        --perimeter;

                    if (i != rows - 1 && grid[i + 1][j] == 1)
                        --perimeter;

                    if (j != 0 && grid[i][j - 1] == 1)
                        --perimeter;

                    if (j != columns - 1 && grid[i][j + 1] == 1)
                        --perimeter;
                }
            }
        }

        return perimeter;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> board = {{0,1,0,0},
                                 {1,1,1,0},
                                 {0,1,0,0},
                                 {1,1,0,0}};

    cout << s.islandPerimeter(board) << endl;
    cout << "---------------------" << endl;
    return 0;
}
