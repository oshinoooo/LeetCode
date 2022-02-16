#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        vector<int> numbers;
        while (0 < num) {
            numbers.push_back(num % 10);
            num /= 10;
        }

        sort(numbers.begin(), numbers.end());

        int minSum = 0;
        for (int i = 0; i < numbers.size() - 1; ++i)
            minSum = minSum * 10 + numbers[i];
        minSum += numbers.back();

        auto itr = numbers.begin();
        minSum = min(minSum, (*itr + *(itr + 1)) * 10 + *(itr + 2) + *(itr + 3));

        return minSum;
    }

    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> greater;
        vector<int> smaller;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < pivot)
                smaller.push_back(nums[i]);
            else if (nums[i] > pivot)
                greater.push_back(nums[i]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i < smaller.size())
                nums[i] = smaller[i];
            else if (i < nums.size() - greater.size())
                nums[i] = pivot;
            else
                nums[i] = greater[i - nums.size() + greater.size()];
        }

        return nums;
    }

    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int out;
        if (600 == targetSeconds) {
            out = moveCost * 3 + pushCost * 3;
            if (9 == startAt)
                out -= moveCost;
            return out;
        }

        vector<int> time(4);
        time[0] = targetSeconds / 60 / 10;
        time[1] = targetSeconds / 60 % 10;
        time[2] = targetSeconds % 60 / 10;
        time[3] = targetSeconds % 60 % 10;

        

        return out;
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.minimumSum(4009) << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;
    vector<int> out = s.pivotArray(nums, pivot);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.minCostSetTime(1, 2, 1, 600) << endl;
    return 0;
}

int test4() {
    cout << "---------------------" << endl;
    Solution s;
//    string corridor = "PPPPPSPPSPPSPPPSPPPPSPPPPSPPPPSPPSPPPSPSPPPSPSPPPSPSPPPSPSPPPPSPPPPSPPPSPPSPPPPSPSPPPPSPSPPPPSPSPPPSPPSPPPPSPSPSS";
//    cout << s.numberOfWays(corridor) << endl;
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
