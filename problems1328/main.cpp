#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        if (palindrome.size() < 2)
            return "";

        int i;
        for (i = 0; i < palindrome.size() / 2; ++i)
        {
            if (palindrome[i] > 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        if (i == palindrome.size() / 2)
        {
            palindrome[palindrome.size() - 1] = 'b';
            return palindrome;
        }

        return "";
    }
};

int main()
{
    std::cout << "---------------" << std::endl;
    Solution s;
    cout << s.breakPalindrome("aaaaa") << endl;
    std::cout << "---------------" << std::endl;
    return 0;
}
