#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        vector<int> store = {0, 1, 1};

        for (int i = 3; i <= n; ++i)
            store.push_back(store[i - 3] + store[i - 2] + store[i - 1]);

        return store[n];
    }
};

int main()
{
    std::cout << "---------------" << std::endl;
    Solution s;
    cout << s.tribonacci(25) << endl;
    std::cout << "---------------" << std::endl;
    return 0;
}
