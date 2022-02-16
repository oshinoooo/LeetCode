#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) return false;
        int number = x;
        int reverse = 0;
        while (number > 0)
        {
            if (reverse > 214748364) return false;
            else if (reverse == 214748364 && number % 10 > 7) return false;
            reverse = reverse * 10 + number % 10;
            number /= 10;
        }
        return x == reverse;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    int in = 123321;
    cout << s.isPalindrome(in) << endl;
    cout << "-----------------------" << endl;
    return 0;
}
