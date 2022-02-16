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

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        node->next = node;

        if (!head)
            return node;

        Node* cur = head;

        while (cur->next != head) {
            if (cur->val <= insertVal && insertVal <= cur->next->val)
                break;

            if ((cur->val <= insertVal || insertVal <= cur->next->val) && cur->next->val < cur->val)
                break;

            cur = cur->next;
        }

        node->next = cur->next;
        cur->next = node;

        return head;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;

//    Node* n3 = new Node(3);
//    Node* n4 = new Node(4);
    Node* n1 = new Node(1);

//    n3->next = n4;
//    n4->next = n1;
//    n1->next = n3;
    n1->next = n1;

    Node* n0 = s.insert(n1, 0);
    for (int i = 0; i < 4; ++i) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
