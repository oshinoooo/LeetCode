#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution
{
public:
    Solution()
    {
        keyboard = {{'2', "abc"},
                    {'3', "def"},
                    {'4', "ghi"},
                    {'5', "jkl"},
                    {'6', "mno"},
                    {'7', "pqrs"},
                    {'8', "tuv"},
                    {'9', "wxyz"}};
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) return {};
        vector<string> output;
        combine(digits, 0, output);
        return output;
    }

    void combine(string& digits, int index, vector<string>& output)
    {
        string chars = keyboard[digits[index]];
        vector<string> tmp;
        tmp.swap(output);

        if (tmp.empty())
        {
            for (auto ch : chars)
            {
                string s(1, ch);
                output.push_back(s);
            }
        }
        else
        {
            for (auto str : tmp)
            {
                for (auto ch : chars)
                    output.push_back(str + ch);
            }
        }

        if (index == digits.size() - 1)
            return;
        else
            combine(digits, index + 1, output);
    }

private:
    map<char, string> keyboard;
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<string> out = s.letterCombinations("23");
    for (auto str : out)
        cout << str << endl;
    cout << "---------------------" << endl;
    return 0;
}
