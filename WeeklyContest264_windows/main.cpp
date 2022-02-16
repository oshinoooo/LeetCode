#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

class Solution
{
public:
    int countValidWords(string sentence)
    {
        int count = 0;
        bool valid = true;
        bool start = false;
        bool has_hyphens = false;

        for (int i = 0; i < sentence.size(); ++i)
        {
            if (' ' == sentence[i])
            {
                if (start && valid)
                    ++count;
                valid = true;
                start = false;
                has_hyphens = false;
                continue;
            }

            if (!valid)
                continue;

            if ('0' <= sentence[i] && sentence[i] <= '9')
                valid = false;
            else if ('a' <= sentence[i] && sentence[i] <= 'z')
                start = true;
            else if ('-' == sentence[i])
            {
                if (has_hyphens)
                    valid = false;

                if (i - 1 < 0 || sentence[i - 1] < 'a' || 'z' < sentence[i - 1])
                    valid = false;

                if (i + 1 == sentence.size() || sentence[i + 1] < 'a' || 'z' < sentence[i + 1])
                    valid = false;

                has_hyphens = true;
            }
            else if ('!' == sentence[i] || ',' == sentence[i] || '.' == sentence[i])
            {
                if (i + 1 != sentence.size() && sentence[i + 1] != ' ')
                    valid = false;

                if (!start)
                {
                    if (i + 1 == sentence.size())
                        ++count;
                    if (i + 1 != sentence.size() && ' ' == sentence[i + 1])
                        ++count;
                }
            }

            if (i == sentence.size() - 1 && start && valid)
                ++count;
        }

        return count;
    }

    int nextBeautifulNumber(int n)
    {
        if (n == 0) return 1;
        int i = n+1;
        for (; i < INT_MAX; ++i)
        {
            if (isBalance(i))
                break;
        }
        return i;
    }

private:
    bool isBalance(int nums)
    {
        int hash[8] = {0};
        while (nums)
        {
            if (nums % 10 > 7 || nums % 10 == 0)
                return false;
            ++hash[nums % 10];
            nums /= 10;
        }

        for (int i = 1; i <= 7; ++i)
        {
            if (hash[i] && hash[i] != i)
                return false;
        }

        return true;
    }
};

int test1()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.countValidWords("cat and  dog") << endl;
    return 0;
}

int test2()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.nextBeautifulNumber(3000) << endl;
    return 0;
}

int main()
{
    test1();
    test2();
    cout << "---------------------" << endl;
    return 0;
}
