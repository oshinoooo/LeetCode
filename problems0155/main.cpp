#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

class MinStack {
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int x) {
        nor_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }

    void pop() {
        nor_stack.pop();
        min_stack.pop();
    }

    int top() {
        return nor_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }

private:
    stack<int> nor_stack;
    stack<int> min_stack;
};

class MinStack {
public:
    MinStack() {
        stk.push({INT_MAX, INT_MAX});
    }

    void push(int val) {
        stk.push({val, min(stk.top().second, val)});
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top().first;
    }

    int getMin() {
        return stk.top().second;
    }

private:
    stack<pair<int, int>> stk;
};

int main()
{
    cout << "---------------------" << endl;
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-1);
    cout << s.getMin() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.getMin() << endl;
    cout << "---------------------" << endl;
    return 0;
}
