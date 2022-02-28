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
//        show();
    }

    virtual ~base() {
        cout << "~base()" << endl;
    }

    virtual void show() {
        cout << "01234" << endl;
    }

private:
    int a;
    int b;
    int c;
};

class son : public base {
public:
    son() {
        cout << "son()" << endl;
        show();
    }

    ~son() {
        cout << "~son()" << endl;
    }

    void show() {
        cout << "56789" << endl;
    }
};

int main() {
    cout << "--------------------" << endl;
    base* object = new son();
    delete object;
    cout << "--------------------" << endl;
    return 0;
}
