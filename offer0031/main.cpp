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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> store;
        int index = 0;

        for (auto& num : pushed)
        {
            store.push(num);
            while (!store.empty() && store.top() == popped[index])
            {
                store.pop();
                ++index;
            }
        }

        return store.empty();
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    cout << s.validateStackSequences(pushed, popped) << endl;
    cout << "---------------------" << endl;
    return 0;
}
