#include <iostream>
#include <vector>
#include <queue>

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
    // 归并
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        return myMergeKLists(lists, 0, lists.size() - 1);
    }

    // 优先队列
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto func = [](ListNode* node1, ListNode* node2){
            return node1->val > node2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(func)> pq(func);

        for (ListNode* head : lists) {
            while (head) {
                pq.push(head);
                head = head->next;
            }
        }

        ListNode* newHead = new ListNode();
        ListNode* cur = newHead;
        while (!pq.empty()) {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
        }

        cur->next = nullptr;
        ListNode* out = newHead->next;
        delete newHead;
        return out;
    }

private:
    ListNode* myMergeKLists(vector<ListNode*>& lists, int head, int tail) {
        if (head == tail)
            return lists[head];
        int mid = (head + tail) / 2;
        ListNode* list1 = myMergeKLists(lists, head, mid);
        ListNode* list2 = myMergeKLists(lists, mid + 1, tail);
        return merge(list1, list2);
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* newHead = new ListNode();
        ListNode* cur = newHead;

        while (head1 && head2) {
            if (head1->val < head2->val) {
                cur->next = head1;
                head1 = head1->next;
            }
            else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }

        if (head1)
            cur->next = head1;
        if (head2)
            cur->next = head2;

        ListNode* out = newHead->next;
        delete newHead;
        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);

    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);

    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);
    ListNode* n9 = new ListNode(9);

    n1->next = n2;
    n2->next = n3;

    n4->next = n5;
    n5->next = n6;

    n7->next = n8;
    n8->next = n9;

    vector<ListNode*> lists = {n1, n4, n7};

    Solution s;
    ListNode* n0 = s.mergeKLists(lists);
    while (n0) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}