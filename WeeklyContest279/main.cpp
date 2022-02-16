#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 1)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }

        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 1)
                nums[i] = odd[i / 2];
            else
                nums[i] = even[i / 2];
        }

        return nums;
    }

    long long smallestNumber(long long num) {
        if (num == 0)
            return 0;

        long long tmpNum = num;
        vector<int> nums;
        while (0 != tmpNum) {
            nums.push_back(tmpNum % 10);
            tmpNum /= 10;
        }
        sort(nums.begin(), nums.end());

        if (0 < num) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] != 0) {
                    swap(nums[0], nums[i]);
                    break;
                }
            }
        }

        long long out = 0;
        for (const auto &item: nums)
            out = out * 10 + item;

        return out;
    }

    int minimumTime(string s) {

    }
};

class Bitset {
public:
    Bitset(int size) {
        oneCount = 0;
        originalData = string(size, '0');
        reversedData = string(size, '1');
    }

    void fix(int idx) {
        if (originalData[idx] == '0') {
            ++oneCount;
            originalData[idx] = '1';
            reversedData[idx] = '0';
        }
    }

    void unfix(int idx) {
        if (originalData[idx] == '1') {
            --oneCount;
            originalData[idx] = '0';
            reversedData[idx] = '1';
        }
    }

    void flip() {
        swap(originalData, reversedData);
        oneCount = originalData.size() - oneCount;
    }

    bool all() {
        return oneCount == originalData.size();
    }

    bool one() {
        return 0 < oneCount;
    }

    int count() {
        return oneCount;
    }

    string toString() {
        return originalData;
    }

private:
    int oneCount;
    string originalData;
    string reversedData;
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {4,1,2,3};
    vector<int> out = s.sortEvenOdd(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.smallestNumber(301) << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Bitset bitset(2);

    bitset.flip();
    bitset.unfix(1);
    cout << bitset.all() << endl;
    bitset.fix(1);
    bitset.fix(1);

    bitset.unfix(1);
    cout << bitset.all() << endl;
    cout << bitset.count() << endl;
    cout << bitset.toString() << endl;
    cout << bitset.toString() << endl;

    cout << bitset.toString() << endl;
    bitset.unfix(0);
    bitset.flip();
    cout << bitset.all() << endl;
    bitset.unfix(0);

    cout << bitset.one() << endl;
    cout << bitset.one() << endl;
    cout << bitset.all() << endl;
    bitset.fix(0);
    bitset.unfix(0);
    return 0;
}

int test4() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.minimumTime("1100101") << endl;
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
