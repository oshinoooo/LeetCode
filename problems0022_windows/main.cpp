#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string current;
        generate(result, current, 0, 0, n);
        return result;
    }

private:
    void generate(vector<string>& ans, string& cur, int left, int right, int n)
    {
        if (right == n)
        {
            ans.push_back(cur);
            return;
        }

        if (left < n)
        {
            cur.push_back('(');
            generate(ans, cur, left + 1, right, n);
            cur.pop_back();
        }

        if (right < left)
        {
            cur.push_back(')');
            generate(ans, cur, left, right + 1, n);
            cur.pop_back();
        }
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<string> out = s.generateParenthesis(2);
    for (auto o : out)
        cout << o << endl;
    cout << "---------------------" << endl;
    return 0;
}
