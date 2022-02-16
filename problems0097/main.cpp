#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isInterleave1(string s1, string s2, string s3)
    {
        int ptr1 = 0;
        int ptr2 = 0;
        int cur = 0;

        while (cur < s3.size())
        {
            while (ptr1 < s1.size() && cur < s3.size() && s3[cur] == s1[ptr1])
            {
                ++cur;
                ++ptr1;
            }

            if (ptr2 == s2.size())
                break;

            while (ptr2 < s2.size() && cur < s3.size() && s3[cur] == s2[ptr2])
            {
                ++cur;
                ++ptr2;
            }

            if (ptr1 == s1.size())
                break;

            if (s3[cur] != s1[ptr1] && s3[cur] != s2[ptr2])
                break;
        }

        bool ret = ptr1 == s1.size() && ptr2 == s2.size() && cur == s3.size();

        ptr1 = 0;
        ptr2 = 0;
        cur = 0;

        while (cur < s3.size())
        {
            while (ptr2 < s2.size() && cur < s3.size() && s3[cur] == s2[ptr2])
            {
                ++cur;
                ++ptr2;
            }

            if (ptr1 == s1.size())
                break;

            while (ptr1 < s1.size() && cur < s3.size() && s3[cur] == s1[ptr1])
            {
                ++cur;
                ++ptr1;
            }

            if (ptr2 == s2.size())
                break;

            if (s3[cur] != s1[ptr1] && s3[cur] != s2[ptr2])
                break;
        }

        ret = ret || ptr1 == s1.size() && ptr2 == s2.size() &&cur == s3.size();

        return ret;
    }

    bool isInterleave(string s1, string s2, string s3)
    {

    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    cout << s.isInterleave("aa", "ab", "aaba") << endl;
    cout << "-----------------------" << endl;
    return 0;
}
