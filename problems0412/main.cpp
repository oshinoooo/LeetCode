#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> out;
        for (int i = 1; i <= n; ++i)
        {
            string tmp;
            if (i % 3 == 0)
                tmp.append("Fizz");
            if (i % 5 == 0)
                tmp.append("Buzz");
            if (tmp.empty())
                tmp.append(to_string(i));
            out.emplace_back(tmp);
        }
        return out;
    }
};

int main()
{
    cout << "-----------------" << endl;
    Solution s;
    vector<string> out = s.fizzBuzz(15);
    for (auto ou : out)
        cout << ou << endl;
    cout << "-----------------" << endl;
    return 0;
}
