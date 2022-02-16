#include <iostream>
#include <vector>
#include <algorithm>

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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == nullptr || k == 0 || head->next == nullptr)
            return head;

        ListNode* cur = head;
        int length = 0;
        while (true)
        {
            ++length;
            if (cur->next == nullptr)
            {
                cur->next = head;
                break;
            }
            cur = cur->next;
        }

        cur = head;
        for (int i = 0; i < length - k % length - 1; ++i)
            cur = cur->next;

        ListNode* out = cur->next;
        cur->next = nullptr;
        return out;
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
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    int k = 10;

    ListNode* n0 = s.rotateRight(n1, k);
    while (n0 != nullptr)
    {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "-------------------------" << endl;
    return 0;
}
