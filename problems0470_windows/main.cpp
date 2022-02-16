#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iomanip>

using namespace std;

class Solution
{
public:
    Solution()
    {
        srand(time(0));
    }

    int rand10()
    {
        int idx;
        while (true)
        {
            idx = rand7() + (rand7() - 1) * 7;
            if (idx <= 40)
                break;
        }
        return 1 + (idx - 1) % 10;
    }

private:
    int rand7()
    {
        return rand() % 7 + 1;
    }
};

int main()
{
    cout << "---------------------------------------" << endl;
    Solution s;
    for (int i = 0; i < 100; ++i)
    {
        if (i % 10 == 0 && i != 0)
            cout << endl;
        cout << right << setw(2) << s.rand10() << " ";
    }
    cout << endl;
    cout << "---------------------------------------" << endl;
    return 0;
}
