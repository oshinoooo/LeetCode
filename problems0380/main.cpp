#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <ctime>
#include <map>

using namespace std;

class RandomizedSet
{
public:
    RandomizedSet()
    {
        srand(time(0));
    }

    bool insert(int val)
    {
        if (m_positions.count(val))
            return false;

        m_positions.insert({val, m_data.size()});
        m_data.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (!m_positions.count(val))
            return false;

        swap(m_data[m_positions[val]], m_data[m_data.size() - 1]);
        m_positions[m_data[m_positions[val]]] = m_positions[val];
        m_data.pop_back();
        m_positions.erase(val);
        return true;
    }

    int getRandom()
    {
        return m_data[rand() % m_data.size()];
    }

private:
    map<int, int> m_positions;
    vector<int> m_data;
};

int main()
{
    cout << "------------------" << endl;
    RandomizedSet r;
    cout << r.insert(1) << endl;
    cout << r.remove(2) << endl;
    cout << r.insert(2) << endl;
    cout << r.getRandom() << endl;
    cout << r.remove(1) << endl;
    cout << r.insert(2) << endl;
    cout << "------------------" << endl;
    return 0;
}