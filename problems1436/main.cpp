#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>>& paths)
    {
        for (int i = 0; i < paths.size(); ++i)
        {
            int j;
            for (j = 0; j < paths.size(); ++j)
            {
                if (i == j)
                    continue;
                if (paths[i][1] == paths[j][0])
                    break;
            }
            if (j == paths.size())
                return paths[i][1];
        }
        return "";
    }

    string destCity2(vector<vector<string>> &paths)
    {
        unordered_set<string> citiesA;
        for (auto &path : paths)
            citiesA.insert(path[0]);

        for (auto &path : paths)
        {
            if (!citiesA.count(path[1]))
                return path[1];
        }
        return "";
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    vector<vector<string>> paths = {{"London","New York"}, {"New York","Lima"}, {"Lima","Sao Paulo"}};
    cout << s.destCity(paths) << endl;
    cout << "---------------" << endl;
    return 0;
}
