#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string pre = "1";
        string cur = "1";

        for (int i = 2; i <= n; ++i)
        {
            cur.clear();

            int count = 0;
            for (int j = 0; j < pre.size(); ++j)
            {
                if (j == 0 || pre[j] == pre[j - 1])
                    ++count;

                if (j != 0 && pre[j] != pre[j - 1])
                {
                    cur.append(to_string(count));
                    cur.push_back(pre[j - 1]);
                    count = 1;
                }

                if (j == pre.size() - 1)
                {
                    cur.append(to_string(count));
                    cur.push_back(pre[j]);
                    count = 1;
                }
            }

            pre = cur;
        }

        return cur;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.countAndSay(4) << endl;
    cout << "---------------------" << endl;
    return 0;
}
