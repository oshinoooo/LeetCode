#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    string shiftingLetters(string s, vector<int>& shifts)
    {
        int count = 0;
        for (int i = shifts.size() - 1; i >= 0; --i)
        {
            count += shifts[i] % 26;
            s[i] = (s[i] -'a' + count) % 26 + 'a';
        }
        return s;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    string str = "bad";
    vector<int> shifts = {10, 20, 30, 40};
    cout << s.shiftingLetters(str, shifts) << endl;
    cout << "-----------------------" << endl;
    return 0;
}
