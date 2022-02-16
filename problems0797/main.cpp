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

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        tmp = {0};
        my_paths(graph, 0);
        return out;
    }

private:
    void my_paths(vector<vector<int>>& graph, int ptr)
    {
        if (ptr == graph.size() - 1)
        {
            out.push_back(tmp);
            return;
        }

        for (auto& node : graph[ptr])
        {
            tmp.push_back(node);
            my_paths(graph, node);
            tmp.pop_back();
        }
    }

private:
    vector<int> tmp;
    vector<vector<int>> out;
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> out = s.allPathsSourceTarget(graph);
    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
