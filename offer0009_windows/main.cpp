#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class CQueue
{
public:
    CQueue()
    {

    }

    void appendTail(int value)
    {
        sta1.push(value);
    }

    int deleteHead()
    {
        int ret;
        if (sta2.empty())
        {
            if (sta1.empty())
                return -1;

            while (!sta1.empty())
            {
                sta2.push(sta1.top());
                sta1.pop();
            }

            ret = sta2.top();
            sta2.pop();
        }
        else
        {
            ret = sta2.top();
            sta2.pop();
        }

        return ret;
    }

private:
    stack<int> sta1;
    stack<int> sta2;
};

int main()
{
    cout << "-------------------------" << endl;
    CQueue c;
    cout << endl;
    cout << "-------------------------" << endl;
    return 0;
}
