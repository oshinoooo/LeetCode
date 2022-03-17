#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<pair<ListNode*, ListNode*>> heads = cut(head, k);

        for (int i = 0; i < heads.size(); ++i) {
            if (i != heads.size() - 1 || enough) {
                reverse(heads[i].first);
                swap(heads[i].first, heads[i].second);
            }
        }

        for (int i = 1; i < heads.size(); ++i)
            heads[i - 1].second->next = heads[i].first;

        return heads[0].first;
    }

private:
    vector<pair<ListNode*, ListNode*>> cut(ListNode* head, int k) {
        vector<pair<ListNode*, ListNode*>> heads;

        int count = 1;
        while (head) {
            if (count == 1)
                heads.emplace_back(head, nullptr);

            ListNode* tail = head;
            head = head->next;

            if (count == k) {
                tail->next = nullptr;
                heads.back().second = tail;
                count = 0;
            }

            ++count;
        }

        if (count == 1)
            enough = true;
        else
            enough = false;

        return heads;
    }

    ListNode* reverse(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

private:
    bool enough;
};

int main() {
    cout << "---------------------" << endl;
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

    ListNode* n0 = s.reverseKGroup(n1, 3);
    while (n0) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
