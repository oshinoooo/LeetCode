#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findOriginalArray(vector<int>& changed)
    {
        if (changed.size() < 2 || changed.size() % 2 == 1)
            return {};

        sort(changed.begin(),changed.end());

        queue<int> q;
        vector<int> res;

        for(int i = 0; i < changed.size(); ++i)
        {
            if(q.empty())
                q.push(changed[i]);
            else
            {
                if(q.front() * 2 == changed[i])
                {
                    res.push_back(q.front());
                    q.pop();
                }
                else
                    q.push(changed[i]);
            }
        }
        if(!q.empty())
            return {};
        return res;
    }
};

int main()
{
    cout << "---------------------------" << endl;
    Solution s;
    vector<int> changed = {1,3,4,2,6,8};
    vector<int> out = s.findOriginalArray(changed);
    for (auto ou : out)
        cout << ou << " ";
    cout << endl;
    cout << "---------------------------" << endl;
    return 0;
}
