#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // 折半查找
    int binary_search(vector<int> in, int target)
    {
        int left = 0, right = in.size() - 1, mid;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (in[mid] == target)
                return mid;
            else if (in[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        };
        return -1;
    }

    int binary_search_recursive(vector<int> in, int target, int left, int right)
    {
        if (left > right)
            return -1;

        int mid = (left + right) / 2;
        if (target == in[mid])
            return mid;
        else if (target < in[mid])
            return binary_search_recursive(in, target, left, mid - 1);
        else
            return binary_search_recursive(in, target, mid + 1, right);
    }

    // 分块查找
    int block_search(vector<int> in, int target)
    {

    }
};

int main()
{
    cout << "-------------" << endl;
    Solution s;
    vector<int> in_ordered = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int t = 4;

    // 折半查找
//    cout << s.binary_search(in_ordered, t) << endl;
//    cout << "-------------" << endl;
//    cout << s.binary_search_recursive(in_ordered, t, 0, in_ordered.size() - 1) << endl;
//    cout << "-------------" << endl;

    // 分块查找
//    cout << s.block_search(in_ordered, t) << endl;
//    cout << "-------------" << endl;

    return 0;
}
