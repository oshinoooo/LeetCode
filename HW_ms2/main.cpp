#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//输入： [3, -5, 6, -7, 4, -4]
//输出： [-5, -7]
//输入： [4, -2, -1, 6, -6, -4]
//输出： []

class Solution
{
public:
    vector<int> test(vector<int>& in)
    {
        vector<int> out;
        for (int i = 0; i < in.size(); ++i)
        {
            if (in[i] > 0)
                out.push_back(in[i]);
            else if (out.empty())
                out.push_back(in[i]);
            else if (in[i] < 0 && !out.empty())
            {
                if (abs(in[i]) == abs(out.back()))
                {
                    out.pop_back();
                }
                else if (abs(in[i]) > abs(out.back()))
                {
                    out.pop_back();
                    out.push_back(in[i]);
                }
            }
        }

        return out;
    }
};

int main()
{
    vector<int> in = {4, -2, -1, 6, -6, -4};
    Solution s;
    vector<int> out = s.test(in);
    for (auto num : out)
    {
        cout << num << " ";
    }
    cout<< endl;
    return 0;
}
