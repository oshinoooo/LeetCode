#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter1(vector<int>& bits) {
        for (int i = 0; i < bits.size(); ++i) {
            if (i == bits.size() - 1)
                return true;
            if (bits[i] == 1)
                ++i;
        }
        return false;
    }

    bool isOneBitCharacter(vector<int>& bits) {

    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> bits = {1, 1, 1, 0};
    cout << s.isOneBitCharacter(bits) << endl;
    cout << "---------------------" << endl;
    return 0;
}
