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

class MaxStack {
public:
    MaxStack() {
        stk.push({INT_MIN, INT_MIN});
    }

    void push(int x) {
        stk.push({x, max(stk.top().second, x)});
    }

    int pop() {
        int out = stk.top().first;
        stk.pop();
        return out;
    }

    int top() {
        return stk.top().first;
    }

    int peekMax() {
        return stk.top().second;
    }

    int popMax() {
        stack<int> tmp;
        int maxNum = peekMax();

        while (top() != maxNum) {
            tmp.push(top());
            pop();
        }

        pop();

        while (!tmp.empty()) {
            push(tmp.top());
            tmp.pop();
        }

        return maxNum;
    }

private:
    stack<pair<int, int>> stk;
};

int main() {
    cout << "---------------------" << endl;
    MaxStack maxStack;
    cout << "" << endl;
    cout << "---------------------" << endl;
    return 0;
}
