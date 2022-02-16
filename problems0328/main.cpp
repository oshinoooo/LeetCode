#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>

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
    ListNode* oddEvenList(ListNode* head)
    {
        ListNode* odd_head = new ListNode();
        ListNode* eve_head = new ListNode();

        ListNode* cur_odd = odd_head;
        ListNode* cur_eve = eve_head;

        int count = 0;
        while (head)
        {
            if (++count % 2 == 1)
            {
                cur_odd->next = head;
                cur_odd = cur_odd->next;
            }
            else
            {
                cur_eve->next = head;
                cur_eve = cur_eve->next;
            }
            head = head->next;
        }
        cur_eve->next = nullptr;
        cur_odd->next = eve_head->next;

        return odd_head->next;
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

    ListNode* n0 = s.oddEvenList(n1);
    while (n0 != nullptr)
    {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
