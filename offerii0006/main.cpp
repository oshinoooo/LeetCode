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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ptr1 = 0;
        int ptr2 = numbers.size() - 1;

        while (ptr1 < ptr2) {
            if (numbers[ptr1] + numbers[ptr2] == target) {
                return {ptr1, ptr2};
            }
            else if (numbers[ptr1] + numbers[ptr2] < target) {
                ++ptr1;
            }
            else {
                --ptr2;
            }
        }

        return {};
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> numbers = {1,2,4,6,10};
    int target = 8;
    vector<int> out = s.twoSum(numbers, target);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
