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

struct ListNode1 {
    int key;
    int val;
    ListNode1 *prev;
    ListNode1 *next;
    ListNode1() : key(0), val(0), next(nullptr), prev(nullptr) {}
    ListNode1(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    ListNode1(int x, int y, ListNode1 *next, ListNode1 *prev) : key(x), val(y), next(next), prev(prev) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        m_head = new ListNode1();
        m_tail = new ListNode1();
        m_head->next = m_tail;
        m_tail->prev = m_head;
        m_capacity = capacity;
    }

    int get(int key) {
        if (m_data.count(key)) {
            m_data[key]->prev->next = m_data[key]->next;
            m_data[key]->next->prev = m_data[key]->prev;

            m_data[key]->prev = m_tail->prev;
            m_data[key]->prev->next = m_data[key];

            m_data[key]->next = m_tail;
            m_tail->prev = m_data[key];

            return m_data[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        ListNode1* node;
        if (!m_data.count(key)) {
            node = new ListNode1(key, value);
            if (m_capacity <= m_data.size()) {
                ListNode1* tmp = m_head->next;
                m_head->next = m_head->next->next;
                m_head->next->prev = m_head;

                m_data.erase(tmp->key);
                delete tmp;
            }
            m_data[key] = node;
        }
        else {
            m_data[key]->val = value;
            node = m_data[key];

            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->prev = m_tail->prev;
        node->prev->next = node;

        node->next = m_tail;
        m_tail->prev = node;
    }

private:
    ListNode1* m_head;
    ListNode1* m_tail;
    unordered_map<int, ListNode1*> m_data;
    int m_capacity;
};

int main() {
    cout << "---------------------" << endl;
    LRUCache lruCache(2);
    lruCache.put(2, 1);
    lruCache.put(1, 1);
    lruCache.put(2, 3);
    lruCache.put(4, 1);
    cout << lruCache.get(1) << endl;
    cout << lruCache.get(2) << endl;
    cout << "---------------------" << endl;
    return 0;
}
