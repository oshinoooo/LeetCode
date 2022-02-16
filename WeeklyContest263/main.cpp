#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    bool areNumbersAscending(string s)
    {
        int pre = INT_MIN;
        int cur = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i)
        {
            if (isdigit(s[i]))
            {
                cur = cur * 10 + s[i] - '0';

                if (i == n - 1 || !isdigit(s[i + 1]))
                {
                    if(pre < cur)
                        pre = cur;
                    else
                        return false;
                    cur = 0;
                }
            }
        }
        return true;
    }
};

class Bank
{
public:
    Bank(vector<long long>& balance)
    {
        m_data.push_back(0);
        for (auto bal : balance)
            m_data.push_back(bal);
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (m_data.size() <= account1 || m_data.size() <= account2 || m_data[account1] < money)
            return false;

        m_data[account1] -= money;
        m_data[account2] += money;
        return true;
    }

    bool deposit(int account, long long money)
    {
        if (m_data.size() <= account)
            return false;
        m_data[account] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (m_data.size() <= account || m_data[account] < money)
            return false;

        m_data[account] -= money;
        return true;
    }

private:
    vector<long long> m_data;
};

void test1()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.areNumbersAscending("hello world 5 x 5") << endl;
}

void test2()
{
    cout << "---------------------" << endl;
    vector<long long> balance = {10, 100, 20, 50, 30};
    Bank b(balance);
    cout << b.withdraw(3, 10) << endl;
    cout << b.transfer(5, 1, 20) << endl;
    cout << b.deposit(5, 20) << endl;
    cout << b.transfer(3, 4, 15) << endl;
    cout << b.withdraw(10, 50) << endl;
}

int main()
{
    test1();
    test2();
    cout << "---------------------" << endl;
    return 0;
}
