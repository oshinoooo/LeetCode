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
        vector<string> nums;
        string tmp;
        for (char c : queryIP) {
            if (isalnum(c))
                tmp.push_back(c);
            else {
                nums.push_back(tmp);
                tmp.clear();
                if (c != '.' && c != ':')
                    return "Neither";
            }
        }

        if (isIPv4(nums))
            return "IPv4";

        if (isIPv6(nums))
            return "IPv6";

        return "Neither";
    }

private:
    bool isIPv4(const vector<string>& nums) {
        for (string num : nums) {
            if (num == "0" || stoi(num) < 0 || 255 < stoi(num))
                return false;
        }
        return true;
    }

    bool isIPv6(const vector<string>& nums) {
        for (string num : nums) {
            if (num.size() < 1 || 4 < num.size())
                return false;
        }
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
