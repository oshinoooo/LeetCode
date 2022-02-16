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
#include <ctime>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        int index = -1;
        int minNum = INT_MAX;

        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] && lists[i]->val < minNum) {
                index = i;
                minNum = lists[i]->val;
            }
        }

        if (index == -1)
            return nullptr;

        ListNode* out = lists[index];

        lists[index] = lists[index]->next;
        out->next = mergeKLists(lists);

        return out;
    }

    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        auto function = [](ListNode*& node1, ListNode*& node2) {
            return node1->val > node2->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(function)> pq(function);

        for (auto& root : lists) {
            while (root) {
                pq.push(root);
                root = root->next;
            }
        }

        ListNode* newHead = new ListNode();
        ListNode* cur = newHead;
        while (!pq.empty()) {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            cur->next = nullptr;
        }

        return newHead->next;
    }

    ListNode* mergeKLists3(vector<ListNode*>& lists) {
        ListNode* newHead = new ListNode();

        for (auto& root : lists)
            newHead->next = myMerge(root, newHead->next);

        return newHead->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        if (lists.size() == 1)
            return lists[0];

        vector<ListNode*> nextLists1(lists.begin(), lists.begin() + lists.size() / 2);
        vector<ListNode*> nextLists2(lists.begin() + lists.size() / 2, lists.end());

        return myMerge(mergeKLists(nextLists1), mergeKLists(nextLists2));
    }

private:
    ListNode* myMerge(ListNode* root1, ListNode* root2) {
        ListNode* newHead = new ListNode();
        ListNode* cur = newHead;

        while (root1 || root2) {
            if (root1 && root2) {
                if (root1->val < root2->val) {
                    cur->next = root1;
                    root1 = root1->next;
                }
                else {
                    cur->next = root2;
                    root2 = root2->next;
                }
            }
            else if (root1) {
                cur->next = root1;
                break;
            }
            else {
                cur->next = root2;
                break;
            }
            cur = cur->next;
        }

        auto out = newHead->next;
        delete newHead;
        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(4);
    ListNode* n3 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;

    ListNode* n4 = new ListNode(1);
    ListNode* n5 = new ListNode(3);
    ListNode* n6 = new ListNode(4);
    n4->next = n5;
    n5->next = n6;

    ListNode* n7 = new ListNode(2);
    ListNode* n8 = new ListNode(6);
    n7->next = n8;

    vector<ListNode*> lists = {n1, n4, n7};

    ListNode* n0 = s.mergeKLists(lists);
    while (n0 != nullptr) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
