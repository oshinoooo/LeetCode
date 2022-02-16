#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> nextLargerNodes1(ListNode* head)
    {
        vector<int> out;
        while (head != nullptr)
        {
            ListNode* tmp = head->next;

            while (tmp != nullptr)
            {
                if (head->val < tmp->val)
                    break;
                tmp = tmp->next;
            }

            if (tmp == nullptr)
                out.push_back(0);
            else
                out.push_back(tmp->val);
            head = head->next;
        }
        return out;
    }

    vector<int> nextLargerNodes(ListNode* head)
    {
        vector<int>nums;
        while(head)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        vector<int> ans(n);
        stack<int> stk;

        for(int i = n - 1; i >= 0; --i)
        {
            while(!stk.empty() && nums[stk.top()] <= nums[i])
                stk.pop();

            if(stk.empty())
                ans[i] = 0;
            else
                ans[i] = nums[stk.top()];

            stk.push(i);
        }
        return ans;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    vector<int> out = s.nextLargerNodes(n1);
    for (auto o : out)
        cout << o << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
