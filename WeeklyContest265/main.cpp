#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int smallestEqual(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i % 10 == nums[i])
                return i;
        }
        return -1;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        vector<bool> critical_points;
        ListNode* cur = head;
        int pre = head->val;
        int count = 0;

        while (cur != nullptr)
        {
            if (cur == head)
            {
                cur = cur->next;
                continue;
            }

            if (cur->next == nullptr)
                break;

            if ((pre < cur->val && cur->next->val < cur->val) ||
                (cur->val < pre && cur->val < cur->next->val))
            {
                ++count;
                critical_points.push_back(true);
            }
            else
                critical_points.push_back(false);

            pre = cur->val;
            cur = cur->next;
        }

        if (count < 2)
            return {-1, -1};

        int first = -1;
        int last = -1;
        int min = INT_MAX;
        for (int i = 0; i < critical_points.size(); ++i)
        {
            if (critical_points[i])
            {
                if (first == -1)
                    first = i;

                if (last != -1 && i - last < min)
                    min = i - last;
                last = i;
            }
        }

        return {min, last - first};
    }

    int minimumOperations(vector<int>& nums, int start, int goal)
    {
        return 0xf0 ^ 0x0f;
    }
};

void test1()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {0, 1, 2};
    cout << s.smallestEqual(nums) << endl;
}

void test2()
{
    cout << "---------------------" << endl;
    Solution s;
    ListNode* n1 = new ListNode(5);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(1);
    ListNode* n4 = new ListNode(2);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(1);
    ListNode* n7 = new ListNode(2);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    vector<int> out = s.nodesBetweenCriticalPoints(n1);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
}

void test3()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 3};
    int start = 6;
    int goal = 4;
    cout << s.minimumOperations(nums, start, goal) << endl;
}

int main()
{
    test1();
    test2();
    test3();
    cout << "---------------------" << endl;
    return 0;
}
