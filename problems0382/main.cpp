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

//class Solution {
//public:
//    Solution(ListNode* head) {
//        srand(time(0));
//        while (head) {
//            nodes.push_back(head);
//            head = head->next;
//        }
//    }
//
//    int getRandom() {
//        return nodes[rand() % nodes.size()]->val;
//    }
//
//private:
//    vector<ListNode*> nodes;
//};

class Solution {
public:
    Solution(ListNode* head) {
        srand(time(0));
        m_head = head;
    }

    int getRandom() {
        int i = 1;
        int out;
        for (ListNode* cur = m_head; cur; cur = cur->next, ++i) {
            if (rand() % i == 0)
                out = cur->val;
        }
        return out;
    }

private:
    ListNode* m_head;
};

int main() {
    cout << "---------------------" << endl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution s(n1);
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << "---------------------" << endl;
    return 0;
}
