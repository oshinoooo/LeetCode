#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class ListNode {
public:
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) {}
    ListNode(int val) : value(val), next(nullptr) {}
    ListNode(int val, ListNode* n) : value(val), next(n) {}
};

void test1() {
    string str;
    cin >> str;

    if (10 < str.size()) {
        cout << "error" << endl;
        return;
    }

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] < '0' || '9' < str[i]) {
            cout << "error" << endl;
            return;
        }
    }

    if ("2147483647" < str) {
        cout << "error" << endl;
        return;
    }

    if (str.size() != 1 && str[0] == '0') {
        cout << "error" << endl;
        return;
    }

    while (str.back() == '0') {
        str.pop_back();
    }

    reverse(str.begin(), str.end());

    cout << str << endl;
}

ListNode* findMid(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode* prev;
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast)
            fast = fast->next;
    }

    prev->next = nullptr;

    return slow;
}

ListNode* reverse(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode* newHead = new ListNode();

    ListNode* curr = newHead;
    while (head1 && head2) {
        curr->next = head1;
        head1 = head1->next;
        curr = curr->next;

        curr->next = head2;
        head2 = head2->next;
        curr = curr->next;
    }

    if (head2) {
        curr->next = head2;
    }

    return newHead->next;
}

void test2() {
    string input;
    getline(cin, input);

    ListNode* newHead = new ListNode();
    ListNode* curr = newHead;
    for (int i = 8; i < input.size(); i += 2) {
        curr->next = new ListNode(input[i] - '0');
        curr = curr->next;
    }

    ListNode* head1 = newHead->next;
    ListNode* head2 = reverse(findMid(head1));
    ListNode* head3 = merge(head1, head2);

    cout << "[";
    curr = head3;
    while (curr) {
        if (curr != head3)
            cout << ",";
        cout << head3->value;
    }
    cout << "]";
}

void test3() {
    string input;
    getline(cin, input);

    if (input.size() < 10) {
        cout << "error" << endl;
        return;
    }

    if (input.substr(0, 8) != "head = [") {
        cout << "error" << endl;
        return;
    }

    if (input.back() != ']') {
        cout << "error" << endl;
        return;
    }

    if (input[8] < '0' || '9' < input[8]) {
        cout << "error" << endl;
        return;
    }

    string subInput = input.substr(8, input.size() - 9);
    string tmp;
    vector<int> nums;
    for (int i = 0; i < subInput.size(); ++i) {
        if (subInput[i] == ',')
            continue;

        if (subInput[i] < '0' || '9' < subInput[i]) {
            cout << "error" << endl;
            return;
        }

        tmp.push_back(subInput[i]);

        if (i == subInput.size() - 1 || subInput[i + 1] == ',') {
            if (tmp.empty()) {
                cout << "error" << endl;
                return;
            }

            nums.push_back(stoi(tmp));
            tmp.clear();
        }
    }

    int ptr1 = 0;
    int ptr2 = nums.size() - 1;

    cout << "[";

    while (ptr1 < nums.size() / 2 && nums.size() / 2 <= ptr2) {
        if (ptr1 != 0)
            cout << ",";
        cout << nums[ptr1++];
        cout << ",";
        cout << nums[ptr2--];
    }

    if (nums.size() / 2 <= ptr2) {
        cout << ",";
        cout << nums[ptr2];
    }

    cout << "]";
}

int main() {
//    test1();
//    test2();
    test3();
    return 0;
}
