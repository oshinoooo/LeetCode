#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string out;
        int count = 0;
        bool start = false;
        for (int i = 0; i < s.size(); ++i)
        {
            if ('a' <= s[i] && s[i] <= 'z')
            {
                start = true;
                ++count;
            }
            else if (start)
            {
//                i != 0 && (' ' == s[i] || i == s.size() - 1)
                

                count = 0;
                start = false;
            }
        }
        return out;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    cout << s.reverseWords("the sky is blue") << endl;
    cout << "-------------------------" << endl;
    return 0;
}
