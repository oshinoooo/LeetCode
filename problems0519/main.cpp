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

class Solution
{
public:
    Solution(int m, int n)
    {
        m_m = m;
        m_n = n;
        m_total = m * n;
        srand(time(nullptr));
    }

    vector<int> flip()
    {
        int x = rand() % m_total;
        vector<int> ans;
        --m_total;

        if (m_map.count(x))
            ans = {m_map[x] / m_n, m_map[x] % m_n};
        else
            ans = {x / m_n, x % m_n};

        if (m_map.count(m_total))
            m_map[x] = m_map[m_total];
        else
            m_map[x] = m_total;

        return ans;
    }

    void reset()
    {
        m_total = m_m * m_n;
        m_map.clear();
    }

private:
    int m_m;
    int m_n;
    int m_total;
    unordered_map<int, int> m_map;
};

int main()
{
    cout << "---------------------" << endl;
    Solution s(2, 3);
    vector<int> position;

    position = s.flip();
    cout << position[0] << ", " << position[1] << endl;

    position = s.flip();
    cout << position[0] << ", " << position[1] << endl;

    position = s.flip();
    cout << position[0] << ", " << position[1] << endl;

    position = s.flip();
    cout << position[0] << ", " << position[1] << endl;

    position = s.flip();
    cout << position[0] << ", " << position[1] << endl;

    position = s.flip();
    cout << position[0] << ", " << position[1] << endl;

    cout << "---------------------" << endl;
    return 0;
}
