#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        vector<int> fib = {0, 1};
        for (int i = 1; i < n; ++i)
            fib.push_back(fib[fib.size() - 2] + fib.back());
        return fib[n];
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.fib(0) << endl;
    cout << s.fib(1) << endl;
    cout << s.fib(2) << endl;
    cout << s.fib(3) << endl;
    cout << s.fib(4) << endl;
    cout << s.fib(5) << endl;
    cout << "---------------------" << endl;
    return 0;
}
