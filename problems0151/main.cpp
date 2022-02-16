#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string out;
        bool start = false;
        int count = 0;

        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] != ' ')
            {
                start = true;
                ++count;
            }
            else if (start)
            {
                if (!out.empty())
                    out.push_back(' ');
                out.append(s.substr(i + 1, count));
                count = 0;
                start = false;
            }
        }

        if (s[0] != ' ')
        {
            if (!out.empty())
                out.push_back(' ');
            out.append(s.substr(0, count));
        }

        return out;
    }
};

int main()
{
    cout << "------------------" << endl;
    Solution s;
    cout << "\"" << s.reverseWords("the sky is blue") << "\"" << endl;
    cout << "------------------" << endl;
    return 0;
}