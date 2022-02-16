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
    string toLowerCase(string s)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if (isupper(s[i]))
                s[i] = tolower(s[i]);
        }
        return s;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.toLowerCase("Hello") << endl;
    cout << "---------------------" << endl;
    return 0;
}
