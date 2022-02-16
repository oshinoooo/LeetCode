#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    int minimumMoves(string s)
    {
        if (s.empty())
            return 0;

        int count = 0;
        int loop_count = 0;

        bool first_x = true;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'X')
            {
                if (first_x)
                {
                    ++count;
                    first_x = false;
                }

                ++loop_count;
            }
            else if (s[i] == 'O' && first_x == false)
                ++loop_count;

            if (loop_count == 3)
            {
                loop_count = 0;
                first_x = true;
            }
        }

        return count;
    }

    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
        int m = rolls.size();
        int sum_m = accumulate(rolls.begin() , rolls.end() , 0);
        int total_sum = mean * (m + n);
        int sum_n = total_sum - sum_m;

        if (sum_n < n || n * 6 < sum_n)
            return {};

        vector<int> out(n, sum_n / n);
        for (int i = 0; i < sum_n % n; ++i)
            ++out[i];

        return out;
    }
};

void test1()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.minimumMoves("OXOX") << endl;
}

void test2()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> rolls = {1, 2, 3, 4};
    int mean = 6;
    int n = 4;
    vector<int> out = s.missingRolls(rolls, mean, n);
    for (auto o : out)
        cout << o << " ";
    cout << endl;
}

int main()
{
    test1();
    test2();
    cout << "---------------------" << endl;
    return 0;
}
