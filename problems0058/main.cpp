#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.empty()) return 0;
        int length = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if ((s[i] != ' ' && i == 0) || (s[i] != ' ' && s[i - 1] == ' '))
                length = 1;
            else if (s[i] != ' ')
                ++length;
        }
        return length;
    }
};

int main()
{
    std::cout << "---------------" << std::endl;
    Solution s;
    cout << s.lengthOfLastWord("   1234  12345  123  ") << endl;
    std::cout << "---------------" << std::endl;
    return 0;
}
