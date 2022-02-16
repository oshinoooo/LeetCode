#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string out;

        int count = num / 1000;
        for (int i = 0; i < count; ++i)
            out.append("M");
        num %= 1000;

        count = num / 100;
        if (count == 9)
            out.append("CM");
        else if (count == 4)
            out.append("CD");
        else
        {
            if (count >= 5)
            {
                out.append("D");
                count -= 5;
            }

            for (int i = 0; i < count; ++i)
                out.append("C");
        }
        num %= 100;

        count = num / 10;
        if (count == 9)
            out.append("XC");
        else if (count == 4)
            out.append("XL");
        else
        {
            if (count >= 5)
            {
                out.append("L");
                count -= 5;
            }

            for (int i = 0; i < count; ++i)
                out.append("X");
        }
        num %= 10;

        if (num == 9)
            out.append("IX");
        else if (num == 4)
            out.append("IV");
        else
        {
            if (num >= 5)
            {
                out.append("V");
                num -= 5;
            }

            for (int i = 0; i < num; ++i)
                out.append("I");
        }

        return out;
    }

    string intToRoman2(int num)
    {
        const vector<pair<int, string>> Romans = { {1000, "M"},
                                                   {900,  "CM"},
                                                   {500,  "D"},
                                                   {400,  "CD"},
                                                   {100,  "C"},
                                                   {90,   "XC"},
                                                   {50,   "L"},
                                                   {40,   "XL"},
                                                   {10,   "X"},
                                                   {9,    "IX"},
                                                   {5,    "V"},
                                                   {4,    "IV"},
                                                   {1,    "I"}};

        string out;
        for (const auto& Roman : Romans)
        {
            while (num >= Roman.first)
            {
                out.append(Roman.second);
                num -= Roman.first;
            }
            if (num == 0)
                break;
        }
        return out;
    }
};

int main()
{
    std::cout << "---------------" << std::endl;
    Solution s;
//    cout << s.intToRoman(58) << endl;
    cout << s.intToRoman2(58) << endl;
    std::cout << "---------------" << std::endl;
    return 0;
}
