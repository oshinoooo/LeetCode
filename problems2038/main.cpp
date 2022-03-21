#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        vector<int> freq = {0, 0};
        char cur = 'C';
        int cnt = 0;
        for (const char& c : colors) {
            if (c != cur) {
                cur = c;
                cnt = 1;
            }
            else if (3 <= ++cnt) {
                ++freq[cur - 'A'];
            }
        }
        return freq[0] > freq[1];
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.winnerOfGame("AAABABB") << endl;
    cout << "--------------------" << endl;
    return 0;
}
