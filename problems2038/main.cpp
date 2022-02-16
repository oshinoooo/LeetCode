#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int count_A = 0;
        int count_B = 0;

        for (int i = 1; i < colors.size() - 1; ++i)
        {
            if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A')
                ++count_A;
            else if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B')
                ++count_B;
        }
        return count_A > count_B;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    cout << s.winnerOfGame("AAABABB") << endl;
    cout << "-----------------------" << endl;
    return 0;
}
