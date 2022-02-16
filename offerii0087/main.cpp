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
#include <ctime>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> out;

        for (int i = 1; i <= 4; ++i) {
            for (int j = 1; j <= 4; ++j) {
                for (int k = 1; k <= 4; ++k) {
                    for (int l = 1; l <= 4; ++l) {
                        if (i + j + k + l == s.size()) {
                            string str1 = s.substr(0, i);
                            string str2 = s.substr(i, j);
                            string str3 = s.substr(i + j, k);
                            string str4 = s.substr(i + j + k, l);

                            if ((i != 1 && str1[0] == '0') ||
                                (j != 1 && str2[0] == '0') ||
                                (k != 1 && str3[0] == '0') ||
                                (l != 1 && str4[0] == '0'))
                                continue;

                            int tmp1 = stoi(str1);
                            int tmp2 = stoi(str2);
                            int tmp3 = stoi(str3);
                            int tmp4 = stoi(str4);

                            if (tmp1 < 0 || 255 < tmp1 ||
                                tmp2 < 0 || 255 < tmp2 ||
                                tmp3 < 0 || 255 < tmp3 ||
                                tmp4 < 0 || 255 < tmp4)
                                continue;

                            out.emplace_back(str1 + "." + str2 + "." + str3 + "." + str4);
                        }
                    }
                }
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> out = s.restoreIpAddresses("010010");
    for (auto str : out)
        cout << str << endl;
    cout << "---------------------" << endl;
    return 0;
}
