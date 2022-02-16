#include <iostream>
#include <vector>

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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* new_head = nullptr;

        while (head != nullptr)
        {
            ListNode* tmp = new_head;
            new_head = head;
            head = head->next;
            new_head->next = tmp;
        }
        return new_head;
    }
};

int main()
{
    cout << "-------------------------" << endl;
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

    ListNode* out = s.reverseList(n1);
    while (out != nullptr)
    {
        cout << out->val << " ";
        out = out->next;
    }
    cout << endl;
    cout << "-------------------------" << endl;
    return 0;
}
