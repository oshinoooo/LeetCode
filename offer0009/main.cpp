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

class CQueue {
public:
    void appendTail(int value) {
        app.push(value);
    }

    int deleteHead() {
        if (del.empty()) {
            if (app.empty()) {
                return -1;
            }
            else {
                while (!app.empty()) {
                    del.push(app.top());
                    app.pop();
                }
            }
        }
        int out = del.top();
        del.pop();
        return out;
    }

private:
    stack<int> app;
    stack<int> del;
};

int main() {
    cout << "---------------------" << endl;
    CQueue cq;
    cout << cq.deleteHead() << endl;
    cq.appendTail(5);
    cq.appendTail(2);
    cout << cq.deleteHead() << endl;
    cout << cq.deleteHead() << endl;
    cout << "---------------------" << endl;
    return 0;
}
