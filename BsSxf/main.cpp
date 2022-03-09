#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits.h>

using namespace std;

class Solution {
public:
    void test1() {
        int n;
        cin >> n;

        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            nums.push_back(tmp);
        }
        sort(nums.begin(), nums.end());

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;

            for (int j = i + 1; j < n; ++j) {
                if (j != i + 1 && nums[j - 1] == nums[j])
                    continue;

                for (int k = j + 1; k < n; ++k) {
                    if (k != j + 1 && nums[k - 1] == nums[k])
                        continue;

                    if (nums[i] + nums[j] > nums[k] &&
                        nums[i] + nums[k] > nums[j] &&
                        nums[j] + nums[k] > nums[i])
                        ++count;
                }
            }
        }

        cout << count << endl;
    }

    void test2() {
        cin >> n;

        totalWeight = 0;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            totalWeight += tmp;
            nums.push_back(tmp);
        }

        int tmpBear1Weight = 0;
        int minDiff = INT_MAX;
        myTest2(tmpBear1Weight, 0, 0, minDiff);

        cout << bear1Weight << " " << bear2Weight << endl;
    }

private:
    void myTest2(int& tmpBear1Weight, int index, int count, int& minDiff) {
        if (n <= index)
            return;

        if (n / 2 == count) {
            int tmp1 = tmpBear1Weight;
            int tmp2 = totalWeight - tmp1;
            int tmpDiff = abs(tmp1 - tmp2);

            if (tmpDiff < minDiff) {
                bear1Weight = min(tmp1, tmp2);
                bear2Weight = max(tmp1, tmp2);
                minDiff = tmpDiff;
            }

            return;
        }

        myTest2(tmpBear1Weight, index + 1, count, minDiff);

        tmpBear1Weight += nums[index];
        myTest2(tmpBear1Weight, index + 1, count + 1, minDiff);
        tmpBear1Weight -= nums[index];
    }

private:
    int n;
    vector<int> nums;

    int totalWeight;
    int bear1Weight;
    int bear2Weight;
};

int main() {
    Solution s;
//    s.test1();
    s.test2();
    return 0;
}
