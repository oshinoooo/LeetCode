#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        while (num1 != 0 && num2 != 0) {
            ++count;
            if (num1 >= num2) {
                num1 -= num2;
            }
            else
                num2 -=num1;
        }
        return count;
    }

    int minimumOperations(vector<int>& nums) {
        return 0;
    }

    long long minimumRemoval1(vector<int>& beans) {
        sort(beans.begin(), beans.end());

        long long out = INT_MAX;

        for (int i = 0; i < beans.size(); ++i) {
            long long tmp = 0;
            for (int j = 0; j < beans.size(); ++j) {
                if (j < i)
                    tmp += beans[j];
                else
                    tmp += beans[j] - beans[i];
            }
            out = min(out, tmp);
        }

        return out;
    }

    long long minimumRemoval(vector<int>& beans) {
        int size = beans.size();

        long long total = 0;
        for (auto& num : beans)
            total += num;

        sort(beans.begin(), beans.end());

        long long out = LONG_LONG_MAX;
        for (int i = 0; i < size; ++i)
            out = min(out, total - (size - i) * (long long)beans[i]);
        return out;
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {3,1,3,2,4,3};
    cout << s.minimumOperations(nums) << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    cout << "" << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> beans = {4,1,6,5};
    cout << s.minimumRemoval(beans) << endl;
    return 0;
}

int test4() {
    cout << "---------------------" << endl;
    Solution s;
    cout << "" << endl;
    return 0;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    cout << "---------------------" << endl;
    return 0;
}
