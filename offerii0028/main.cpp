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

struct Node {
    int val;
    Node* prev;
    Node *next;
    Node *child;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head)
            return nullptr;

        stack<Node*> nodes;
        nodes.push(head);
        
        Node* cur = new Node(0);
        while (!nodes.empty()) {
            cur->next = nodes.top();
            nodes.top()->prev = cur;
            nodes.pop();

            while (true) {
                if (cur->child) {
                    if (cur->next)
                        nodes.push(cur->next);
                    cur->next = cur->child;
                    cur->next->prev = cur;
                    cur->child = nullptr;
                }
                if (!cur->next)
                    break;
                cur = cur->next;
            }
        }

        head->prev = nullptr;

        return head;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;
    n5->prev = n4;
    n6->prev = n5;

    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);

    n7->next = n8;
    n8->next = n9;
    n9->next = n10;

    n8->prev = n7;
    n9->prev = n8;
    n10->prev = n9;

    Node* n11 = new Node(11);
    Node* n12 = new Node(12);

    n11->next = n12;

    n12->prev = n11;

    n3->child = n7;
    n8->child = n11;

    Node* n0 = s.flatten(n1);
    while (n0 != nullptr) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;

    n0 = n6;
    while (n0 != nullptr) {
        cout << n0->val << " ";
        n0 = n0->prev;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
