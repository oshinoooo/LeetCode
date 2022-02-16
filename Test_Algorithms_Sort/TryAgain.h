//
// Created by Youlong Liu on 1/21/22.
//

#ifndef TEST_ALGORITHMS_SORT_TRYAGAIN_H
#define TEST_ALGORITHMS_SORT_TRYAGAIN_H

#include <vector>

using namespace std;

class TryAgain {
public:
    static void bubble_sort(vector<int>& nums);
    static void quick_sort(vector<int>& nums, int left, int right);
    static int quick_sort_recursive(vector<int>& nums, int left, int right);
    static void select_sort(vector<int>& nums);
    static void insert_sort(vector<int>& nums);
    static void merge_sort(vector<int>& nums, int left, int right);
};

#endif //TEST_ALGORITHMS_SORT_TRYAGAIN_H
