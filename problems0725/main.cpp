#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

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
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        int count = 0;
        ListNode* tmp = head;
        while (tmp != nullptr)
        {
            ++count;
            tmp = tmp->next;
        }

        int number = count / k;
        int add = count % k;
        if (number == 0)
        {
            number = 1;
            add = 0;
        }

        vector<ListNode*> out;
        tmp = head;
        ListNode* pre = nullptr;
        for (int i = 0; i < k; ++i)
        {
            if (pre != nullptr)
                pre->next = nullptr;
            out.push_back(tmp);

            if (tmp == nullptr)
                continue;

            for (int j = 0; j < (i < add ? number + 1 : number); ++j)
            {
                pre = tmp;
                tmp = tmp->next;
            }
        }

        return out;
    }
};

int main()
{
    cout << "---------------" << endl;
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

    int k = 3;

    vector<ListNode*> out = s.splitListToParts(n1, k);

    for (auto ou : out)
    {
        if (ou == nullptr)
            cout << "nullptr " << endl;
        else
        {
            while (ou != nullptr)
            {
                cout << ou->val << " ";
                ou = ou->next;
            }
            cout << endl;
        }
    }
    cout << "---------------" << endl;
    return 0;
}
