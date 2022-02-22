#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    string validIPAddress(string queryIP) {
        bool ipv4 = false;
        bool ipv6 = false;

        vector<string> nums;
        string tmp;
        for (int i = 0; i < queryIP.size(); ++i) {
            if (isalnum(queryIP[i]))
                tmp.push_back(queryIP[i]);
            else {
                nums.push_back(tmp);
                tmp.clear();

                if (queryIP[i] == '.')
                    ipv4 = true;
                else if (queryIP[i] == ':')
                    ipv6 = true;
                else
                    return "Neither";
            }
        }

        if (ipv4 && isIPv4(queryIP))
            return "IPv4";

        if (ipv6 && isIPv6(queryIP))
            return "IPv6";

        return "Neither";
    }

private:
    bool isIPv4(string queryIP) {
        for (int i = 1; i <= 4; ++i) {
            for (int j = 1; j <= 4; ++j) {
                for (int k = 1; k <= 4; ++k) {
                    for (int l = 1; l <= 4; ++l) {
                        if (i + j + k + l == queryIP.size()) {
                            if ((i == 1 && queryIP[0] == '0') ||
                                (j == 1 && queryIP[i] == '0') ||
                                (k == 1 && queryIP[i + j] == '0') ||
                                (l == 1 && queryIP[i + j + k] == '0'))
                                continue;

                            string str1 = queryIP.substr(0, i);
                            string str2 = queryIP.substr(i, j);
                            string str3 = queryIP.substr(i + j, k);
                            string str4 = queryIP.substr(i + j + k, l);

                            int tmp1 = stoi(str1);
                            int tmp2 = stoi(str2);
                            int tmp3 = stoi(str3);
                            int tmp4 = stoi(str4);

                            if (tmp1 < 0 || 255 < tmp1 ||
                                tmp2 < 0 || 255 < tmp2 ||
                                tmp3 < 0 || 255 < tmp3 ||
                                tmp4 < 0 || 255 < tmp4)
                                continue;

                            return true;
                        }
                    }
                }
            }
        }

        return true;
    }

    bool isIPv6(string queryIP) {



        return true;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.validIPAddress("172.16.254.1") << endl;
    cout << "--------------------" << endl;
    return 0;
}
