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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* curr = head;
        while (curr) {
            v.push_back(curr);
            curr = curr->next;
        }

        for (int i = v.size() - 1; (v.size() + 2) / 2 <= i; --i) {
            ListNode* tmp = v[v.size() - 1 - i]->next;
            v[v.size() - 1 - i]->next = v[i];
            v[i - 1]->next = nullptr;
            v[i]->next = tmp;
        }

        return;
    }
};

int main() {
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

    s.reorderList(n1);

    while (n1 != nullptr) {
        cout << n1->val << " ";
        n1 = n1->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
