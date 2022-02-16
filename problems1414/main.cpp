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
#include <ctime>

using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibonacciNumbers = {1, 1};

        while (fibonacciNumbers.back() < k)
            fibonacciNumbers.push_back(*fibonacciNumbers.rbegin() + *(fibonacciNumbers.rbegin() + 1));


        int count = 0;
        int ptr = fibonacciNumbers.size() - 1;
        while (0 < k) {
            while (k < fibonacciNumbers[ptr])
                --ptr;

            k -= fibonacciNumbers[ptr];
            ++count;
        }

        return count;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.findMinFibonacciNumbers(10) << endl;
    cout << "---------------------" << endl;
    return 0;
}
