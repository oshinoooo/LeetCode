#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int out = 0;
        vector<int> points;

        for (auto &op : ops) {
            int n = points.size();
            switch (op[0]) {
                case '+':
                    out += points[n - 1] + points[n - 2];
                    points.push_back(points[n - 1] + points[n - 2]);
                    break;
                case 'D':
                    out += 2 * points[n - 1];
                    points.push_back(2 * points[n - 1]);
                    break;
                case 'C':
                    out -= points[n - 1];
                    points.pop_back();
                    break;
                default:
                    out += stoi(op);
                    points.push_back(stoi(op));
                    break;
            }
        }

        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<string> ops = {"5","2","C","D","+"};
    cout << s.calPoints(ops) << endl;
    cout << "--------------------" << endl;
    return 0;
}