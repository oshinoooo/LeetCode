#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

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
    int countEven(int num) {
        int count = 0;
        for (int i = 2; i <= num; ++i) {
            if (isEven(i))
                ++count;
        }
        return count;
    }

    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead = new ListNode();
        ListNode* tail = newHead;

        int sum = 0;
        ListNode* curr = head;
        while (curr) {
            if (curr->val == 0 && sum != 0) {
                tail->next = new ListNode(sum);
                tail = tail->next;
                sum = 0;
            }
            else
                sum += curr->val;
            curr = curr->next;
        }

        return newHead->next;
    }

    string repeatLimitedString(string s, int repeatLimit) {
        string out;

        return out;
    }

private:
    bool isEven(int num) {
        int sum = 0;
        while (0 < num) {
            sum += num % 10;
            num /= 10;
        }
        return sum % 2 == 0;
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.countEven(5) << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    ListNode* n1 = new ListNode(0);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(0);
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(0);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    Solution s;
    ListNode* n0 = s.mergeNodes(n1);
    while (n0) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.repeatLimitedString("cczazcc", 3) << endl;
    return 0;
}

int test4() {
    cout << "---------------------" << endl;
    Solution s;
    cout << "" << endl;
    return 0;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    cout << "---------------------" << endl;
    return 0;
}
