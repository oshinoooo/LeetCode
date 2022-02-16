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
    int countVowelSubstrings(string word)
    {
        int n = word.size();
        int count = 0;

        for (int i = 0; i < n - 4; ++i)
        {
            map<char, int> m;
            for (int j = i; j < n; ++j)
            {
                if (word[j] != 'a' && word[j] != 'e' && word[j] != 'i' && word[j] != 'o' && word[j] != 'u')
                    break;
                ++m[word[j]];
                if (5 <= m.size())
                    ++count;
            }
        }

        return count;
    }

    long long countVowels(string word)
    {
        long long n = word.size();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        long long sum = 0;
        for (long long i = 0; i < n; ++i)
        {
            if (vowels.count(word[i]))
                sum += (i + 1) * ((n + 1) - (i + 1));
        }
        return sum;
    }

    int minimizedMaximum(int n, vector<int>& quantities)
    {
        int speed1 = 1;
        int speed2 = INT_MAX;
        while (speed1 < speed2)
        {
            int mid = speed1 + (speed2 - speed1) / 2;
            int tmp = 0;
            for (auto quantitie : quantities)
                tmp += (quantitie - 1) / mid + 1;

            if (n < tmp)
                speed1 = mid + 1;
            else
                speed2 = mid;
        }
        return speed1;
    }
};

int test1()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.countVowelSubstrings("cuaieuouac") << endl;
    return 0;
}

int test2()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.countVowels("aba") << endl;
    return 0;
}

int test3()
{
    cout << "---------------------" << endl;
    Solution s;
    int n = 6;
    vector<int> quantities = {11, 6};
    cout << s.minimizedMaximum(n, quantities) << endl;
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
