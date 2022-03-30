#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> out;

        for (int i = left; i <= right; i++) {
            if (mySelfDividingNumbers(i))
                out.emplace_back(i);
        }

        return out;
    }

private:
    bool mySelfDividingNumbers(int num) {
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit == 0 || num % digit != 0)
                return false;
            temp /= 10;
        }
        return true;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> out = s.selfDividingNumbers(1, 2);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}