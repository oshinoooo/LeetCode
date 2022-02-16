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
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> num_days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

        int distance = 0;
        distance += (year - 1971) * 365 + (year - 1969) / 4;
        distance += num_days[month - 1];
        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && 3 <= month)
            distance += 1;
        distance += day;

        return week[(distance + 4) % 7];
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.dayOfTheWeek(31, 8, 2100) << endl;
    cout << "---------------------" << endl;
    return 0;
}
