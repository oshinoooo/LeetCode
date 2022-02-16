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
#include <list>

using namespace std;

class doubleList {
public:
    doubleList() {
        pre = nullptr;
        next = nullptr;
        key = 0;
        value = 0;
    }

    doubleList(int k, int v) {
        pre = nullptr;
        next = nullptr;
        key = k;
        value = v;
    }

public:
    doubleList* pre;
    doubleList* next;
    int key;
    int value;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
        head = new doubleList();
        tail = new doubleList();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (m.count(key)) {
            auto node = m[key];
            moveToEnd(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.count(key)) {
            auto node = m[key];
            node->value = value;
            moveToEnd(node);
        }
        else {
            if (m.size() == m_capacity) {
                m.erase(head->next->key);
                head->next = head->next->next;
                head->next->pre = head;
            }

            auto node = new doubleList(key, value);
            m[key] = node;

            node->pre = tail->pre;
            node->pre->next = node;

            node->next = tail;
            tail->pre = node;
        }
    }

private:
    void moveToEnd(doubleList* node) {
        auto pre = node->pre;
        auto next = node->next;

        pre->next = next;
        next->pre = pre;

        node->pre = tail->pre;
        node->pre->next = node;

        node->next = tail;
        tail->pre = node;
    }

private:
    int m_capacity;
    doubleList* head;
    doubleList* tail;
    unordered_map<int, doubleList*> m;
};

int main() {
    cout << "---------------------" << endl;
    LRUCache lruCache(2);

    lruCache.put(1, 0);
    lruCache.put(2, 2);

    cout << lruCache.get(1) << endl;

    lruCache.put(3, 3);

    cout << lruCache.get(2) << endl;

    lruCache.put(4, 4);

    cout << lruCache.get(1) << endl;
    cout << lruCache.get(3) << endl;
    cout << lruCache.get(4) << endl;
    cout << "---------------------" << endl;
    return 0;
}
