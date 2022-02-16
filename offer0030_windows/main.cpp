#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack
{
public:
    void push(int x)
    {
        m_data.push(x);
        if (m_min.empty())
            m_min.push(x);
        else
        {
            if (x < m_min.top())
                m_min.push(x);
            else
                m_min.push(m_min.top());
        }
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

    int min()
    {
        return m_min.top();
    }

private:
    stack<int> m_data;
    stack<int> m_min;
};

int main()
{
    cout << "-------------------------" << endl;
    MinStack m;
    m.push(-2);
//    m.push(0);
//    m.push(-3);
//    m.min();
//    m.pop();
    m.top();
    m.min();
    cout << "-------------------------" << endl;
    return 0;
}
