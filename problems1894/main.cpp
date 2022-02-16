#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int chalkReplacer(vector<int>& chalk, int k)
    {
        long long sum = 0;
        for (auto ch : chalk) sum +=ch;
        k %= sum;

        for (int i = 0; i < chalk.size(); ++i)
        {
            if (chalk[i] > k) return i;
            else k -= chalk[i];
        }
        return -1;
    }
};

int main()
{
    cout << "--------------------" << endl;
    Solution s;
    vector<int> chalk = {3, 4, 1, 2};
    int k = 25;
    cout << s.chalkReplacer(chalk, k) << endl;
    cout << "--------------------" << endl;
    return 0;
}
