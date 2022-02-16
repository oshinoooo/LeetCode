#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty()) return 0;
        else if (needle.size() > haystack.size()) return -1;
        for (int i = 0; i < haystack.size() - needle.size() + 1; ++i)
            if (haystack.substr(i, needle.size()) == needle) return i;
        return -1;
    }

    int strStr2(string haystack, string needle)
    {

    }
};

int main()
{
    cout << "--------------------" << endl;
    Solution s;
    string haystack = "hello";
    string needle = "ll";
    cout << s.strStr(haystack, needle) << endl;
//    cout << s.strStr2(haystack, needle) << endl;
    cout << "--------------------" << endl;
    return 0;
}
