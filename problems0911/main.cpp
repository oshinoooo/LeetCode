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

class TopVotedCandidate
{
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times)
    {
        m_times = times;
        int max_person = 0;
        map<int, int> m;
        for (int i = 0; i < times.size(); ++i)
        {
            if (m[max_person] <= ++m[persons[i]])
                max_person = persons[i];
            m_record.push_back(max_person);
        }
    }

    int q(int t)
    {
        int ptr1 = 0;
        int ptr2 = m_times.size() - 1;

        while (ptr1 <= ptr2)
        {
            int mid = (ptr1 + ptr2) / 2;
            if (m_times[mid] == t)
                return m_record[mid];
            else if (m_times[mid] < t)
                ptr1 = mid + 1;
            else
                ptr2 = mid - 1;
        }
        return m_record[ptr2];
    }

private:
    vector<int> m_record;
    vector<int> m_times;
};

int main()
{
    cout << "---------------------" << endl;
    vector<int> persons = {0, 1, 1, 0, 0, 1, 0};
    vector<int> times = {0, 5, 10, 15, 20, 25, 30};
    TopVotedCandidate t(persons, times);
    cout << t.q(3) << endl;
    cout << t.q(12) << endl;
    cout << t.q(25) << endl;
    cout << t.q(15) << endl;
    cout << t.q(24) << endl;
    cout << t.q(8) << endl;
    cout << "---------------------" << endl;
    return 0;
}
