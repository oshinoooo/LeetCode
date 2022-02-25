#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void bubble(vector<int>& in) {

    }

    void quick(vector<int>& in, int head, int tail) {

    }

    void merge(vector<int>& in, int head, int tail) {

    }

    void selection_sort(vector<int>& in) {

    }

    void insertion_sort(vector<int>& arr) {

    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {5, 7, 0, 1, 9, 6, 3, 4, 8, 2};

    s.bubble(nums);
    s.quick(nums, 0, nums.size() - 1);
    s.merge(nums, 0, nums.size() - 1);
    s.selection_sort(nums);
    s.insertion_sort(nums);

    for (const int& num : nums)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}
