#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows <= 0) return {};
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1, 1}};

        vector<vector<int>> ret = {{1}, {1, 1}};
        for (int i = 2; i < numRows; ++i)
        {
            vector<int> tmp = {1};
            for (int j = 1; j < i; ++j)
                tmp.push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
            tmp.push_back(1);
            ret.push_back(tmp);
        }

        return ret;
    }
};

int main()
{
    cout << "----------------"<< endl;
    Solution s;
    vector<vector<int>> out = s.generate(5);

    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "----------------"<< endl;
    return 0;
}
