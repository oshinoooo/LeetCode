#include <iostream>
#include <vector>

using namespace std;

const int MAX_WIDTH = 100;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int width = 0;
        for (auto & c : s) {
            int need = widths[c - 'a'];
            width += need;
            if (width > MAX_WIDTH) {
                lines++;
                width = need;
            }
        }
        return {lines, width};
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> widths = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    vector<int> out = s.numberOfLines(widths, "bbbcccdddaaa");
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}