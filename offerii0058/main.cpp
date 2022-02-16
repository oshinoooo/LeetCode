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

class MyCalendar {
public:
    bool book(int start, int end) {
        auto it = m.lower_bound(start);

        if (it != m.end() && it->first < end)
            return false;

        if (it != m.begin() && start < --it->second)
            return false;

        m[start] = end;
        return true;
    }

private:
    map<int, int> m;
};

int main() {
    cout << "---------------------" << endl;
    MyCalendar myCalendar;
    cout << myCalendar.book(10, 20)<< endl;
    cout << myCalendar.book(15, 25)<< endl;
    cout << myCalendar.book(20, 30)<< endl;
    cout << "---------------------" << endl;
    return 0;
}
