#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else
            {
                if (st.empty())
                    return false;
                else if ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[') || (c == '}' && st.top() == '{'))
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    string in = "()[]{}";
    cout << s.isValid(in) << endl;
    cout << "-----------------------" << endl;
    return 0;
}
