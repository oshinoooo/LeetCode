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
    vector<string> restoreIpAddresses1(string s) {
        int length = s.size();

        vector<string> out;

        for (int i = 1; i <= 4; ++i) {
            if (length < i + 3)
                break;
            if (9 < length - i)
                continue;

            for (int j = 1; j <= 4; ++j) {
                if (length < i + j + 2)
                    break;
                if (6 < length - i - j)
                    continue;

                for (int k = 1; k <= 4; ++k) {
                    if (length < i + j + k + 1)
                        break;
                    if (3 < length - i - j - k)
                        continue;

                    int l = length - i - j - k;

                    if (i != 1 && s[0] == '0' ||
                        j != 1 && s[i] == '0' ||
                        k != 1 && s[i + j] == '0' ||
                        l != 1 && s[i + j + k] == '0')
                        continue;

                    string str1(s.substr(0, i));
                    string str2(s.substr(i, j));
                    string str3(s.substr(i + j, k));
                    string str4(s.substr(i + j + k, l));

                    int tmp1 = stoi(str1);
                    int tmp2 = stoi(str2);
                    int tmp3 = stoi(str3);
                    int tmp4 = stoi(str4);

                    if (tmp1 < 0 || 255 < tmp1 ||
                        tmp2 < 0 || 255 < tmp2 ||
                        tmp3 < 0 || 255 < tmp3 ||
                        tmp4 < 0 || 255 < tmp4)
                        continue;

                    out.push_back(str1 + "." + str2 + "." + str3 + "." + str4);
                }
            }
        }

        return out;
    }

/*public:
    vector<string> restoreIpAddresses2(string s) {
        int length = s.size();



    }

private:
    void myRestoreIpAddresses() {

    }*/

public:
    vector<string> restoreIpAddresses(string s) {
        segments.resize(4);
        dfs(s, 0, 0);
        return out;
    }

private:
    void dfs(const string& s, int segId, int segStart) {
        // 如果找到了 4 段 IP 地址并且遍历完了字符串，那么就是一种答案
        if (segId == 4) {
            if (segStart == s.size()) {
                string ipAddr;
                for (int i = 0; i < 4; ++i) {
                    ipAddr += to_string(segments[i]);
                    if (i != 4 - 1) {
                        ipAddr += ".";
                    }
                }
                out.push_back(move(ipAddr));
            }
            return;
        }

        // 如果还没有找到 4 段 IP 地址就已经遍历完了字符串，那么提前回溯
        if (segStart == s.size())
            return;

        // 由于不能有前导零，如果当前数字为 0，那么这一段 IP 地址只能为 0
        if (s[segStart] == '0') {
            segments[segId] = 0;
            dfs(s, segId + 1, segStart + 1);
        }

        // 一般情况，枚举每一种可能性并递归
        int addr = 0;
        for (int segEnd = segStart; segEnd < s.size(); ++segEnd) {
            addr = addr * 10 + (s[segEnd] - '0');
            if (addr > 0 && addr <= 0xFF) {
                segments[segId] = addr;
                dfs(s, segId + 1, segEnd + 1);
            } else {
                break;
            }
        }
    }

private:
    vector<string> out;
    vector<int> segments;
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> out = s.restoreIpAddresses("25525511135");
    for (auto num : out)
        cout << num << endl;
    cout << "---------------------" << endl;
    return 0;
}
