#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        int length = path.size();

        if (length == 0 || length == 1)
            return path;

        int ptr1;
        int ptr2 = 0;
        stack<string> directories;
        for (int i = 0; i < length; ++i)
        {
            if (path[i] == '/' && i != 0)
            {
                if (ptr2 == i - 1)
                    ptr2 = i;
                else
                {
                    ptr1 = ptr2;
                    ptr2 = i;
                    directories.push(path.substr(ptr1 + 1, ptr2 - ptr1 - 1));
                }
            }
            else if (i == length - 1)
                directories.push(path.substr(ptr2 + 1, length - 1 - ptr2));
        }

        string out;
        int num_pop = 0;
        while (!directories.empty())
        {
            if (directories.top() == ".")
                directories.pop();
            else if (directories.top() == "..")
            {
                ++num_pop;
                directories.pop();
            }
            else if (num_pop > 0)
            {
                --num_pop;
                directories.pop();
            }
            else
            {
                out.insert(out.begin(), directories.top().begin(), directories.top().end());
                out.insert(out.begin(), '/');
                directories.pop();
            }
        }

        if (out.empty())
            return "/";

        return out;
    }
};

int main()
{
    cout << "-----------------" << endl;
    Solution s;
    cout << s.simplifyPath("/a//b////c/d//././/..") << endl;
    cout << "-----------------" << endl;
    return 0;
}
