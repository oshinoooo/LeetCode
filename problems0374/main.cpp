#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int guessNumber(int n)
    {
        int ptr1 = 1;
        int ptr2 = n;

        while (ptr1 <= ptr2)
        {
            int mid = ((long long)ptr1 + (long long)ptr2) / 2;
            if (guess(mid) == 0)
                return mid;
            else if (guess(mid) == -1)
                ptr2 = mid - 1;
            else if (guess(mid) == 1)
                ptr1 = mid + 1;
        }

        return -1;
    }

private:
    int guess(int num)
    {
        int target = 4;
        if (num == target)
            return 0;
        else if (num < target)
            return 1;
        else if (target < num)
            return -1;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    cout << s.guessNumber(6) << endl;
    cout << "-------------------------" << endl;
    return 0;
}
