#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string convert1(string s, int numRows)
    {
        if (numRows == 1) return s;

        int circle = numRows * 2 - 2;
        int out_column = (s.size() / circle + 1) * (numRows - 1);
        vector<vector<pair<bool, char>>> z_array(numRows);
        for (auto arr : z_array)
            arr.resize(out_column);

        z_array[0].push_back({true, s[0]});
        int row = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (i % circle == 0 || i % circle >= numRows)
            {
                for (int j = 0; j < numRows - 2; ++j)
                {
                    z_array[row].push_back({false, 0});
                    ++row;
                    if (row >= numRows)
                        row %= numRows;
                }
            }

            z_array[row].push_back({true, s[i]});
            ++row;
            if (row >= numRows)
                row %= numRows;
        }

        string out;
        for (auto array : z_array)
        {
            for (auto arr : array)
            {
                if (arr.first)
                    out.push_back(arr.second);
            }
        }
        return out;
    }

    string convert2(string s, int numRows)
    {
        if (numRows == 1) return s;

        int circle = numRows * 2 - 2;
        int position[circle];
        int count = 0;
        for (int i = 0; i < circle; ++i)
        {
            if (i >= numRows)
                count += 2;
            position[i] = i - count;
        }

        vector<string> z_array;
        for (int i = 0; i < numRows; ++i)
            z_array.push_back("");

        for (int i = 0; i < s.size(); ++i)
            z_array[position[i % circle]].push_back(s[i]);

        string out;
        for (auto array : z_array) out += array;
        return out;
    }

    string convert3(string s, int numRows)
    {
        if (numRows == 1) return s;

        vector<string> rows(numRows);
        int curRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};

int main()
{
    cout << "-------------------" << endl;
    Solution s;
//    cout << s.convert1("PAYPALISHIRING", 3) << endl;
//    cout << s.convert2("PAYPALISHIRING", 3) << endl;
    cout << s.convert3("PAYPALISHIRING", 3) << endl;
    cout << "-------------------" << endl;
    return 0;
}
