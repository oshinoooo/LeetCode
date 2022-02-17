#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

int main() {
    cout << "----------------------------------------" << endl;

    vector<int> nums1 = {0, 1, 2, 3, 4};

    int nums2[5] = {5, 6, 7, 8, 9};

    int* num3 = new int[5];
    num3[0] = 0;
    num3[1] = 0xff;
    num3[2] = 2;
    num3[3] = 3;
    num3[4] = 4;

    int a = 1;
    int b = 2;

    cout << "----------------------------------------" << endl;
    return 0;
}