#include <iostream>

using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        while (left < right)
            right = right & (right - 1);
        return right;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    cout << s.rangeBitwiseAnd(5, 7) << endl;
    cout << "-------------------------" << endl;
    return 0;
}
