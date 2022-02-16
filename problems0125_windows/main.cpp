#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int ptr1 = 0;
        int ptr2 = s.size() - 1;

        while (ptr1 <= ptr2)
        {
            while (ptr1 <= ptr2 && !isalnum(s[ptr1]))
                ++ptr1;

            while (ptr1 <= ptr2 && !isalnum(s[ptr2]))
                --ptr2;

            if (tolower(s[ptr1]) != tolower(s[ptr2]))
                break;
            else
            {
                ++ptr1;
                --ptr2;
            }
        }

        if (ptr1 > ptr2)
            return true;
        else
            return false;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << "---------------------" << endl;
    return 0;
}
