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
#include <ctime>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(0));
    }

    bool insert(int val) {
        if (m_s.count(val))
            return false;
        m_s.insert(val);
        return true;
    }

    bool remove(int val) {
        if (!m_s.count(val))
            return false;
        m_s.erase(val);
        return true;
    }

    int getRandom() {
        auto it = m_s.begin();
        advance(it, rand() % m_s.size());
        return *it;
    }

private:
    unordered_set<int> m_s;
};

int main() {
    cout << "---------------------" << endl;
    RandomizedSet randomizedSet;
    cout << "" << endl;
    cout << "---------------------" << endl;
    return 0;
}
