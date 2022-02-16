#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string pre = "1";
        string cur;
        int count = 0;
        for (int i = 1; i < n; ++i)
        {
            for (int i = 0; i < pre.size(); ++i)
            {
                if (i == 0 || pre[i - 1] == pre[i])
                    ++count;
                else
                {
                    cur.append(to_string(count));
                    cur.push_back(pre[i - 1]);
                    count = 1;
                }

                if (i == pre.size() - 1)
                {
                    cur.append(to_string(count));
                    cur.push_back(pre[i]);
                }
            }
            pre = cur;
            cur.clear();
            count = 0;
        }

        return pre;
    }
};

int main()
{
    cout << "-----------------" << endl;
    Solution s;
    cout << s.countAndSay(5) << endl;
    cout << "-----------------" << endl;
    return 0;
}
