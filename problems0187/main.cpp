#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> strs;
        for (int i = 0; i <= s.size() - 10; ++i)
            strs.push_back(s.substr(i, 10));

        vector<string> out;

        return out;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    vector<string> out = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (auto ou : out)
        cout << ou << endl;
    cout << "-------------------------" << endl;
    return 0;
}
