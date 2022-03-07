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

class base {
public:
    base() {
        cout << "base()" << endl;
    }

    base(const base& b) {
        cout << "base(const base& b)" << endl;
    }

    virtual ~base() {
        cout << "~base()" << endl;
    }
};

class son : public base {
public:
    son() {
        cout << "son()" << endl;
    }

    ~son() {
        cout << "~son()" << endl;
    }
};

int main() {
    cout << "--------------------" << endl;
    {
        base b1;
        base b2(b1);
        b2 = b1;
    }
    cout << "--------------------" << endl;
    return 0;
}
