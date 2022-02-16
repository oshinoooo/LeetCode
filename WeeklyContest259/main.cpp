#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

class Solution
{
public:
    int finalValueAfterOperations(vector<string>& operations)
    {
        int value = 0;
        for (int i = 0; i < operations.size(); ++i)
        {
            if (operations[i] == "--X" || operations[i] == "X--")
                --value;
            if (operations[i] == "++X" || operations[i] == "X++")
                ++value;
        }
        return value;
    }

    int sumOfBeauties(vector<int>& nums)
    {
        if (nums.empty()) return 0;

        int beauty = 0;
        int left_max = INT_MIN;
        int right_min = INT_MAX;
        stack<int> stack_min;
        for (int i = nums.size() - 1; i >= 2; --i)
        {
            right_min = min(right_min, nums[i]);
            stack_min.push(right_min);
        }

        for (int i = 1; i < nums.size() - 1; ++i)
        {
            left_max = max(left_max, nums[i - 1]);
            if (left_max < nums[i] && nums[i] < stack_min.top())
                beauty += 2;
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                ++beauty;
            stack_min.pop();
        }

        return beauty;
    }
};

struct point
{
    int x;
    int y;
    int number;
};
/*
class DetectSquares
{
public:
    DetectSquares() {}

    void add(vector<int> point)
    {
        // check square
        if (plane.size() >= 2)
        {
            map<pair<int, int>, int>::iterator it1;
            map<pair<int, int>, int>::iterator it2;
            for (it1 = plane.begin(); it1 != plane.end(); ++it1)
            {
                for (it2 = (it1 + sizeof(map<pair<int, int>, int>)); it2 != plane.end(); ++it2)
                {

                }
            }
        }

        // insert
        for (int i = 0; i < plane.size(); ++i)
        {
            if (plane[i].x == point[0] && plane[i].y == point[1])
                ++plane[i].number;
        }
    }

    int count(vector<int> point)
    {
        for (auto p : goodPoint)
        {
            if (p.x == point[0] && p.y == point[1])
                return p.number;
        }
    }

private:
    int isSquare(pair<int, int> point)
    {
        if ()
        int count = 0;

        return count;
    }

private:
    vector<point> plane;
    vector<point> goodPoint;
};
*/
int test1()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<string> operations = {"--X","X++","X++"};
    cout << s.finalValueAfterOperations(operations) << endl;
    return 0;
}

int test2()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3};
    cout << s.sumOfBeauties(nums) << endl;
    return 0;
}

int test3()
{
    cout << "---------------------" << endl;
//    DetectSquares d;
//    d.add({0, 0});
//    d.add({0, 1});
//    d.add({1, 0});
////    d.add({1, 0});
//    cout << d.count({1, 1}) << endl;
    return 0;
}

int main()
{
    test1();
    test2();
//    test3();
    cout << "---------------------" << endl;
    return 0;
}
