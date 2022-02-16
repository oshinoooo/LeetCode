#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        if (n < k)
            return {};

        vector<vector<int>> out;
        vector<int> tmp;
        recursive(n, k, tmp, out);

        return out;
    }

private:
    void recursive(int n, int k, vector<int> tmp, vector<vector<int>>& out)
    {
        if (n < 1)
            return;

        if (tmp.size() == k)
            out.push_back(tmp);

        recursive(n - 1, k, tmp, out);
        tmp.push_back(n);
        recursive(n - 1, k, tmp, out);
    }
};

int main()
{
    cout << "-----------------" << endl;
    Solution s;
    int n = 4;
    int k = 2;
    vector<vector<int>> out = s.combine(n, k);
    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "-----------------" << endl;
    return 0;
}
