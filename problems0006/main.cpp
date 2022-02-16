#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector<vector<int>> out;
        for (int i = 0; i < numRows; ++i)
            out.push_back({});

        int circle = numRows * 2 - 2;

        for (int i = 0; i < s.size(); ++i)
        {
            int position = i % circle;
            if (position > numRows || position == 0)
            {
                out
            }
        }


    }
};

int main()
{
    cout << "------------------" << endl;
    Solution s;
    string in = "PAYPALISHIRING";
    int numRows = 3;
    cout << s.convert(in, numRows) << endl;
    cout << "------------------" << endl;
    return 0;
}

/*
 * 01        07        13
 * 02      0608      1214
 * 03    05  09    11  15
 * 04  06    10  12    16
 * 05        11        17
 */