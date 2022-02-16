#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long long ptr1 = 1;
        long long ptr2 = n;
        while (ptr1 < ptr2)
        {
            long long mid = (ptr1 + ptr2) / 2;
            if (isBadVersion(mid))
                ptr2 = mid;
            else
                ptr1 = mid + 1;
        }
        return ptr2;
    }

private:
    bool isBadVersion(int version)
    {
        if (version >= 4)
            return true;
        else
            return false;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.firstBadVersion(8) << endl;
    cout << "---------------------" << endl;
    return 0;
}
