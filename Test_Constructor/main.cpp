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

class Base {
public:
    Base(int a, int b) {
        cout << "Base()" << endl;
    }

    Base(const Base& b) {
        cout << "Base(const Base& b)" << endl;
    }

    Base(const Base&& b) {
        cout << "Base(const Base& b)" << endl;
    }

    Base operator=(const Base& b) {
        cout << "Base operator=(const Base& b)" << endl;
    }

    virtual ~Base() {
        cout << "~Base()" << endl;
    }
};

int main() {
    cout << "--------------------" << endl;
    {
        vector<Base> bases;
        bases.emplace_back(1, 2);
        bases.push_back({1, 2});
    }
    cout << "--------------------" << endl;
    return 0;
}
