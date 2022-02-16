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
    bool detectCapitalUse(string word)
    {
        int length = word.size();
        if (length == 1)
            return true;

        if (isupper(word[0]) && isupper(word[1]))
        {
            for (int i = 2; i < length; ++i)
            {
                if (islower(word[i]))
                    return false;
            }
        }
        else
        {
            for (int i = 1; i < length; ++i)
            {
                if (isupper(word[i]))
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.detectCapitalUse("F") << endl;
    cout << "---------------------" << endl;
    return 0;
}
