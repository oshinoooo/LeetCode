#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        vector<int> out(2);
        int sqr = sqrt(area);
        for (long long i = 1; i <= sqr; ++i)
        {
            if (area % i == 0)
            {
                out[0] = area / i;
                out[1] = i;
            }
        }
        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> out = s.constructRectangle(10);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
