#include <iostream>
#include <unordered_map>

using namespace std;

struct doubleList {
    int key;
    int value;
    doubleList* prev;
    doubleList* next;

    doubleList() : key(0), value(0), prev(nullptr), next(nullptr) {}
    doubleList(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
    doubleList(int _key, int _value, doubleList* _prev, doubleList* _next) : key(_key), value(_value), prev(_prev), next(_next) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new doubleList();
        tail = new doubleList();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (index.count(key)) {
            moveToEnd(index[key]);
            return index[key]->value;
        }
        return -1;
    }

    void put(int key, int value) {
        doubleList* node;
        if (index.count(key)) {
            node = index[key];
            node->value = value;
        }
        else {
            if (capacity <= index.size()) {
                doubleList* tmp = head->next;
                index.erase(head->next->key);
                head->next = head->next->next;
                head->next->prev = head;
                delete tmp;
            }

            node = new doubleList(key, value);
            index[key] = node;
        }

        moveToEnd(node);
    }

private:
    void moveToEnd(doubleList* node) {
        if (node->prev && node->next) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }

private:
    int capacity;
    unordered_map<int, doubleList*> index;
    doubleList* head;
    doubleList* tail;
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