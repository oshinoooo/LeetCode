#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        int r = numRows;
        if (r == 1 || r >= n)
            return s;

        string out;

        int t = r * 2 - 2;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j + i < n; j += t) {
                out += s[j + i];
                if (0 < i && i < r - 1 && j + t - i < n)
                    out += s[j + t - i];
            }
        }

        return out;
    }
};

/*
 * 01        07        13
 * 02      0608      1214
 * 03    05  09    11  15
 * 04  06    10  12    16
 * 05        11        17
 */

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.convert("01234567890123456789", 5) << endl;
    cout << "--------------------" << endl;
    return 0;
}