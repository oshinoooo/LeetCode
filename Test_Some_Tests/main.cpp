#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
    cout << "-----------------------" << endl;
    {
        vector<vector<int>> in = {{4, 2, 1},
                                  {1, 4, 2},
                                  {1, 2, 4}};

        for (auto nums : in)
        {
            if (nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] != nums[1] + nums[2] <= nums[0])
                cout << "true : " << nums[0] << " " << nums[1] << " " << nums[2] << endl;
            else
                cout << "false: " << nums[0] << " " << nums[1] << " " << nums[2] << endl;
        }
    }
    cout << "-----------------------" << endl;
    return 0;
}
