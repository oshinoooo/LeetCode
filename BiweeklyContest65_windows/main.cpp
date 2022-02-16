#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool checkAlmostEquivalent(string word1, string word2)
    {
        map<char, pair<int, int>> m;
        for (auto& c : word1)
            ++m[c].first;

        for (auto& c : word2)
            ++m[c].second;

        for (auto& c : m)
        {
            if (abs(c.second.first - c.second.second) > 3)
                return false;
        }
        return true;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
    {
        sort(items.begin(), items.end());

        vector<int> max_beauties;
        for (auto& item : items)
        {
            if (max_beauties.empty())
                max_beauties.push_back(item[1]);
            else
            {
                if (max_beauties.back() < item[1])
                    max_beauties.push_back(item[1]);
                else
                    max_beauties.push_back(max_beauties.back());
            }
        }

        vector<int> answer;

        for (auto& target : queries)
        {
            int ptr1 = 0;
            int ptr2 = items.size() - 1;

            while (ptr1 <= ptr2)
            {
                int mid = (ptr1 + ptr2) / 2;
                if (target < items[mid][0])
                    ptr2 = mid - 1;
                else
                    ptr1 = mid + 1;
            }

            if (0 <= ptr2 && ptr2 < items.size())
                answer.push_back(max_beauties[ptr2]);
            else
                answer.push_back(0);
        }

        return answer;
    }
};

class Robot
{
public:
    Robot(int width, int height)
    {
        w = width;
        h = height;
        perimeter = 2 * w + 2 * h - 4;
        x = 0;
        y = 0;
        d = 0;
    }

    void move(int num)
    {
        num %= perimeter;

        if(!num)
        {
            if(x == 0 && y == 0)
                d = 3;
            if(x == w-1 && y == 0)
                d = 0;
            if(x == w-1 && y == h-1)
                d = 1;
            if(x == 0 && y == h-1)
                d = 2;
        }

        while(num--)
        {
            int nx = dx[d] + x, ny = dy[d] + y;
            if(nx < 0 || nx >= w || ny < 0 || ny >= h)
            {
                d++, d %= 4;
                nx = dx[d] + x, ny = dy[d] + y;
            }
            x = nx, y = ny;
        }
    }

    vector<int> getPos()
    {
        return  {x, y};
    }

    string getDir()
    {
        return dir[d];
    }

private:
    int w, h;
    int x, y, d;
    int perimeter;
    string dir[4] = {"East", "North", "West", "South"};
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};
};

int test1()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.checkAlmostEquivalent("abcdeef", "abaaacc") << endl;
    return 0;
}

int test2()
{
    cout << "---------------------" << endl;
    Robot r(3, 3);

    r.move(27);
    r.move(47);
    r.move(27);
    r.move(30);
    r.move(50);

    r.move(37);
    r.move(33);
    r.move(47);
    r.move(47);
    r.move(42);

    r.move(49);
    r.move(25);
    r.move(24);
    r.move(19);
    r.move(3);

    r.move(15);
    r.move(22);
    r.move(17);
    r.move(6);
    r.move(47);

    r.move(1);
    r.move(12);
    r.move(50);
    r.move(46);
    r.move(34);

    r.move(16);

    cout << "{" << r.getPos()[0] << ", " << r.getPos()[1] << "}" << endl;
    cout << r.getDir() << endl;
    return 0;
}

int test3()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> items = {{10, 1000}};
    vector<int> queries = {5};
    vector<int> out = s.maximumBeauty(items, queries);
    for (auto& num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int main()
{
    test1();
    test2();
    test3();
    cout << "---------------------" << endl;
    return 0;
}
