#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string out;
        int ptra = a.size() - 1;
        int ptrb = b.size() - 1;
        int carry = 0;

        while (0 <= ptra || 0 <= ptrb) {
            if (0 <= ptra && 0 <= ptrb) {
                int sum = a[ptra] - '0' + b[ptrb] - '0' + carry;
                out.push_back(sum % 2 + '0');
                carry = sum / 2;
                --ptra;
                --ptrb;
            }
            else if (0 <= ptra) {
                int sum = a[ptra] - '0' + carry;
                out.push_back(sum % 2 + '0');
                carry = sum / 2;
                --ptra;
            }
            else {
                int sum = b[ptrb] - '0' + carry;
                out.push_back(sum % 2 + '0');
                carry = sum / 2;
                --ptrb;
            }
        }

        if (carry) {
            out.push_back('1');
        }

        reverse(out.begin(), out.end());

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.addBinary("11", "11") << endl;
    cout << "---------------------" << endl;
    return 0;
}
