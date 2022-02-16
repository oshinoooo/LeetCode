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
    vector<int> asteroidCollision1(vector<int>& asteroids)
    {
        if (asteroids.size() <= 1)
            return asteroids;

        int i;
        for (i = 0; i < asteroids.size() - 1; ++i)
        {
            if (asteroids[i] > 0 && asteroids[i + 1] < 0)
            {
                int mass1 = abs(asteroids[i]);
                int mass2 = abs(asteroids[i + 1]);
                vector<int> tmp;
                if (mass1 == mass2)
                {
                    tmp.insert(tmp.begin(), asteroids.begin(), asteroids.begin() + i);
                    tmp.insert(tmp.end(), asteroids.begin() + i + 2, asteroids.end());
                }
                else if (mass1 > mass2)
                {
                    tmp.insert(tmp.begin(), asteroids.begin(), asteroids.begin() + i + 1);
                    tmp.insert(tmp.end(), asteroids.begin() + i + 2, asteroids.end());
                }
                else
                {
                    tmp.insert(tmp.begin(), asteroids.begin(), asteroids.begin() + i);
                    tmp.insert(tmp.end(), asteroids.begin() + i + 1, asteroids.end());
                }
                swap(tmp, asteroids);
                return asteroidCollision(asteroids);
            }
        }

        if (i == asteroids.size() - 1)
            return asteroids;
        return {};
    }

    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        vector<int> out;
        for (int i = 0; i < asteroids.size(); ++i)
        {
            if (asteroids[i] > 0)
                out.push_back(asteroids[i]);
            else if (out.empty())
                out.push_back(asteroids[i]);
            else if (!out.empty())
            {
                if (abs(asteroids[i]) == abs(out.back()))
                    out.pop_back();
                else if (abs(asteroids[i]) > abs(out.back()))
                {
                    out.pop_back();
                    out.push_back(asteroids[i]);
                    return asteroidCollision(out);
                }
            }
        }
        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> asteroids = {10, 2, -5};
    vector<int> out = s.asteroidCollision(asteroids);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
