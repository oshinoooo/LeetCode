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
    int compareVersion1(string version1, string version2) {
        int start = 0;
        vector<string> s1;
        for (int i = 0; i < version1.size(); ++i) {
            if (i == version1.size() - 1 || version1[i + 1] == '.') {
                s1.push_back(version1.substr(start, i - start + 1));
                start = i + 2;
            }
        }

        start = 0;
        vector<string> s2;
        for (int i = 0; i < version2.size(); ++i) {
            if (i == version2.size() - 1 || version2[i + 1] == '.') {
                s2.push_back(version2.substr(start, i - start + 1));
                start = i + 2;
            }
        }

        int i = 0;
        while (i < s1.size() && i < s2.size()) {
            if (stoi(s1[i]) < stoi(s2[i]))
                return -1;
            else if (stoi(s1[i]) > stoi(s2[i]))
                return 1;
            ++i;
        }

        if (s1.size() < s2.size()) {
            for (int j = i; j < s2.size(); ++j) {
                if (0 < stoi(s2[j]))
                    return -1;
            }
        }

        else if (s1.size() > s2.size()) {
            for (int j = i; j < s1.size(); ++j) {
                if (0 < stoi(s1[j]))
                    return 1;
            }
        }

        return 0;
    }

    int compareVersion(string version1, string version2) {
        int size1 = version1.size();
        int size2 = version2.size();

        int start1 = 0;
        int start2 = 0;

        int ptr1 = 0;
        int ptr2 = 0;

        while (ptr1 < size1 || ptr2 < size2) {
            while (ptr1 < size1 - 1 && version1[ptr1 + 1] != '.')
                ++ptr1;

            while (ptr2 < size2 - 1 && version2[ptr2 + 1] != '.')
                ++ptr2;

            int tmp1 = 0;
            if (start1 < size1)
                tmp1 = stoi(version1.substr(start1, ptr1 - start1 + 1));

            int tmp2 = 0;
            if (start2 < size2)
                tmp2 = stoi(version2.substr(start2, ptr2 - start2 + 1));

            if (tmp1 < tmp2)
                return -1;
            else if (tmp1 > tmp2)
                return 1;

            ptr1 += 2;
            ptr2 += 2;

            start1 = ptr1;
            start2 = ptr2;
        }

        return 0;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.compareVersion("1.1", "1.1.0.0.0.1") << endl;
    cout << "---------------------" << endl;
    return 0;
}
