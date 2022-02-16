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
    ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
        ListNode* newHead = new ListNode();
        ListNode* cur = newHead;

        while (list1 || list2) {
            if (list1 && list2) {
                if (list1->val < list2->val) {
                    cur->next = list1;
                    list1 = list1->next;
                }
                else {
                    cur->next = list2;
                    list2 = list2->next;
                }
            }
            else if (list1) {
                cur->next = list1;
                break;
            }
            else {
                cur->next = list2;
                break;
            }
            cur = cur->next;
        }

        return newHead->next;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 && list2) {
            if (list1->val < list2->val) {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            }
            else {
                list2->next = mergeTwoLists(list1, list2->next);
                return list2;
            }
        }
        else if (list1)
            return list1;

        return list2;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;

    ListNode* n4 = new ListNode(2);
    ListNode* n5 = new ListNode(4);
    ListNode* n6 = new ListNode(6);
    n4->next = n5;
    n5->next = n6;

    ListNode* n0 = s.mergeTwoLists(n1, n4);
    while (n0 != nullptr) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
