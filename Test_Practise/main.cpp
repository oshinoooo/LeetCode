#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class TestPrint {
public:
    TestPrint() : ptr(0), str("12345"), printCount(100) {}

    void show(int i) {
        while (0 < printCount) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){return ptr % 5 == i || 0 == printCount;});
            if (printCount == 0)
                return;
            cout << "thread id: " << i << ", " << str[ptr] << ", count: " << printCount << endl;
            ptr = (ptr + 1) % 5;
            --printCount;
            cv.notify_all();
        }
    }

private:
    int ptr;
    const string str;
    int printCount;
    mutex m;
    condition_variable cv;
};

class Solution {
public:
    int count(const vector<int>& nums) {
        int count = 1;
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;
        int prev = nums[ptr1] < nums[ptr2] ? ptr1++ : ptr2--;

        while (ptr1 <= ptr2) {
            int tmp = nums[ptr1] < nums[ptr2] ? ptr1++ : ptr2--;
            if (nums[tmp] != nums[prev]) {
                ++count;
                prev = tmp;
            }
        }

        return count;
    }

    int count2(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] != nums[i])
                ++count;
        }
        return count;
    }

private:
    void quick_sort(vector<int>& nums, int head, int tail) {
        if (tail <= head)
            return;

        int pivot = nums[head];
        int tmpHead = head;
        int tmpTail = tail;

        while (tmpHead < tmpTail) {
            while (tmpHead < tmpTail && pivot <= nums[tmpTail])
                --tmpTail;
            nums[tmpHead] = nums[tmpTail];

            while (tmpHead < tmpTail && nums[tmpHead] <= pivot)
                ++tmpHead;
            nums[tmpTail] = nums[tmpHead];
        }

        nums[tmpHead] = pivot;
        quick_sort(nums, head, tmpHead - 1);
        quick_sort(nums, tmpHead + 1, tail);
    }
};

int test1() {
    cout << "----------------------------------------" << endl;
    TestPrint testPrint;

    vector<thread> threads;
    for (int i = 0; i < 5; ++i)
        threads.push_back(thread(&TestPrint::show, &testPrint, i));

    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();
    cout << "----------------------------------------" << endl;
    return 0;
}

int test2() {
    cout << "----------------------------------------" << endl;
    vector<int> nums = {1, 1, 3, 9, 10, 30, 11, 10, 2};
    Solution s;
    cout << s.count(nums) << endl;
    cout << "----------------------------------------" << endl;
    return 0;
}

int main() {
    cout << "----------------------------------------" << endl;
//    test1();
    test2();
    cout << "----------------------------------------" << endl;
    return 0;
}