#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    string numberToWords(int num)
    {
        vector<string> singles   = {"",     "One",      "Two",      "Three",    "Four",     "Five",     "Six",      "Seven",        "Eight",    "Nine"};
        vector<string> teens     = {"Ten",  "Eleven",   "Twelve",   "Thirteen", "Fourteen", "Fifteen",  "Sixteen",  "Seventeen",    "Eighteen", "Nineteen"};
        vector<string> tens      = {"",     "Ten",      "Twenty",   "Thirty",   "Forty",    "Fifty",    "Sixty",    "Seventy",      "Eighty",   "Ninety"};
        vector<string> thousands = {"",     "Thousand", "Million",  "Billion"};


    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    cout << s.numberToWords(3) << endl;
    cout << "-------------------------" << endl;
    return 0;
}
