#include <iostream>
#include <map>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int value) : val(value), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
};

class Solution
{
public:
    ListNode* deleteDuplicates1(ListNode* head)
    {
        map<int, bool> count;
        ListNode* tmp = head;
        while (tmp != nullptr)
        {
            if (!count.count(tmp->val))
                count.insert(make_pair(tmp->val, false));
            else
                count[tmp->val] = true;
            tmp = tmp->next;
        }

        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* pre = new_head;

        while (head != nullptr)
        {
            if (count[head->val])
                pre->next = head->next;
            else
                pre = pre->next;
            head = head->next;
        }

        return new_head->next;
    }

    ListNode* deleteDuplicates2(ListNode* head)
    {
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* pre = newhead;
        ListNode* cur = head;
        int count = 0;

        while(cur != nullptr && cur->next != nullptr)
        {
            if(cur->val == cur->next->val)
            {
                cur->next = cur->next->next;//删除该元素
                count++;//将count次数加一再次进行判断
            }
            else
            {
                if(count > 0)
                {
                    pre->next = cur->next;//将该元素值全部删除
                    count = 0;
                }
                else
                    pre = cur;
                cur = cur->next;//递归条件
            }
        }
        if(count > 0)
            pre->next = cur->next;
        return newhead->next;
    }

    ListNode* deleteDuplicates3(ListNode* head)
    {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;

        while (cur != nullptr)
        {
            int count = 0;
            int tmp = cur->val;
            while (cur != nullptr)
            {
                if (tmp == cur->val)
                    ++count;
                else
                    break;
                cur = cur->next;
            }

            if (count > 1)
                pre->next = cur;
            else
                pre = pre->next;
        }

        return new_head->next;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
//    ListNode* l3 = new ListNode(2);
    l1->next = l2;
//    l2->next = l3;

    Solution s;
//    ListNode* out = s.deleteDuplicates1(l1);
//    ListNode* out = s.deleteDuplicates2(l1);
    ListNode* out = s.deleteDuplicates3(l1);

    while (out != nullptr)
    {
        cout << out->val << endl;
        out = out->next;
    }
    cout << "-----------------------" << endl;
    return 0;
}
