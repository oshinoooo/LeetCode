#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        for (int i = 0; i < word.size(); ++i)
        {
            if (word[i] == ch)
            {
                string tmp;
                for (int j = i; j >= 0; --j)
                {
                    tmp.push_back(word[j]);
                }
                word = word.replace(0, tmp.size(), tmp);
                break;
            }
        }
        return word;
    }

    long long interchangeableRectangles(vector<vector<int>>& rectangles)
    {
        vector<double> ratio;
        for (auto rectangle : rectangles)
            ratio.push_back(double(rectangle[0]) / double(rectangle[1]));

        unordered_map<double, int> records;
        for (int i = 0; i < ratio.size(); ++i)
        {
            if (records.count(ratio[i]) == 0)
                records.insert(make_pair(ratio[i], 1));
            else
                records[ratio[i]] += 1;
        }

        long long count = 0;
        for (auto record : records)
        {
            for (int i = 1; i < record.second; ++i)
                count += i;
        }

        return count;
    }

    int maxProduct(string s)
    {





        return 0;
    }

    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums)
    {
        return {};
    }

private:
    string getPalindromes(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    pair<int, int> expandAroundCenter(const string& s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
};

void test1()
{
    cout << "-----------------" << endl;
    Solution s;
    cout << s.reversePrefix("qwer", 'r') << endl;
}

void test2()
{
    cout << "-----------------" << endl;
    Solution s;
    vector<vector<int>> rectangles = {{4, 8}, {3, 6}, {10, 20}, {15, 30}};
    cout << s.interchangeableRectangles(rectangles) << endl;
}

void test3()
{
    cout << "-----------------" << endl;
    Solution s;
    cout << s.maxProduct("rectangles") << endl;
}

void test4()
{
    cout << "-----------------" << endl;
    Solution s;
    vector<int> parents = {};
    vector<int> nums = {};
    vector<int> out = s.smallestMissingValueSubtree(parents, nums);
    for (auto o : out)
        cout << o << " ";
    cout << endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    cout << "-----------------" << endl;
    return 0;
}
