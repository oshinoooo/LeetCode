#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack
{
public:
    MinStack()
    {

    }

    void push(int val)
    {
        m_data.push(val);
        if (m_min.empty())
            m_min.push(val);
        else if (m_min.top() > val)
            m_min.push(val);
        else
            m_min.push(m_min.top());
    }

    void pop()
    {
        m_data.pop();
        m_min.pop();
    }

    int top()
    {
        return m_data.top();
    }

    int getMin()
    {
        return m_min.top();
    }

private:
    stack<int> m_data;
    stack<int> m_min;
};

int main()
{
    cout << "---------------------" << endl;
    MinStack s;
    cout << "---------------------" << endl;
    return 0;
}
