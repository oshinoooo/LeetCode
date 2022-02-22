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
        if (!isalnum(queryIP[0]) || !isalnum(queryIP.back()))
            return "Neither";

        bool ipv4;
        for (char c : queryIP) {
            if (!isalnum(c)) {
                if (c == '.')
                    ipv4 = true;
                else if (c == ':')
                    ipv4 = false;
                else
                    return "Neither";
                break;
            }
        }

        vector<string> nums = separate(queryIP);

        if (ipv4) {
            if (nums.size() != 4)
                return "Neither";

            for (string num : nums) {
                if (num.empty())
                    return "Neither";

                if (3 < num.size())
                    return "Neither";

                if (1 < num.size() && num[0] == '0')
                    return "Neither";

                for (char c : num) {
                    if (c < '0' || '9' < c)
                        return "Neither";
                }

                if (255 < stoi(num))
                    return "Neither";
            }

            return "IPv4";
        }
        else {
            if (nums.size() != 8)
                return "Neither";

            for (string num : nums) {
                if (num.empty())
                    return "Neither";

                if (4 < num.size())
                    return "Neither";

                for (char c : num) {
                    if (isalpha(c) && !(('a' <= c && c <= 'f') || ('A' <= c && c <= 'F')))
                        return "Neither";
                }
            }
            return "IPv6";
        }

        return "Neither";
    }

private:
    vector<string> separate(const string& queryIP) {
        vector<string> out;

        string tmp;
        for (char c : queryIP) {
            if (isalnum(c))
                tmp.push_back(c);
            else {
                out.push_back(tmp);
                tmp.clear();
            }
        }
        out.push_back(tmp);

        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.validIPAddress("2001:db8:85a3:0::8a2E:0370:7334") << endl;
    cout << "--------------------" << endl;
    return 0;
}
