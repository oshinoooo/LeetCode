#include <iostream>
#include <set>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        set<int> seen;
        while (n != 1 && !seen.count(n))
        {
            seen.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }

private:
    int getNext(int n)
    {
        int totalSum = 0;
        while (n > 0)
        {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    cout << s.isHappy(123) << endl;
    cout << "-------------------------" << endl;
    return 0;
}
