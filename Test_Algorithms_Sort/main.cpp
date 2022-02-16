#include <iostream>
#include <vector>
#include "Solution.h"
#include "TryAgain.h"

using namespace std;

void test1() {
    cout << "---------------------" << endl;
    vector<int> nums = {3, 5, 6, 0, 8, 4, 2, 7, 9, 1};

//    Solution::bubble_sort(nums);
//    Solution::quick_sort(nums, 0, nums.size() - 1);
//    Solution::select_sort(nums);
//    Solution::insert_sort(nums);
//    Solution::merge_sort(nums, 0, nums.size() - 1);
//    Solution::heap_sort(nums);
    Solution::shell_sort(nums);

    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
}

void test2() {
    cout << "---------------------" << endl;
    vector<int> nums = {3, 5, 6, 0, 8, 4, 2, 7, 9, 1};

    TryAgain::bubble_sort(nums);
//    TryAgain::quick_sort(nums, 0, nums.size() - 1);
//    TryAgain::select_sort(nums);
//    TryAgain::insert_sort(nums);
//    TryAgain::merge_sort(nums, 0, nums.size() - 1);

    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
}

int main() {
    test1();
//    test2();
}
