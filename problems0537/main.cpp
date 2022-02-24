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
    string complexNumberMultiply(string num1, string num2) {
        string real1;
        string imaginary1;
        separate(num1, real1, imaginary1);

        string real2;
        string imaginary2;
        separate(num2, real2, imaginary2);

        string out;
        out += to_string(stoi(real1) * stoi(real2) - stoi(imaginary1) * stoi(imaginary2));
        out += "+";
        out += to_string(stoi(real1) * stoi(imaginary2) + stoi(real2) * stoi(imaginary1));
        out += "i";
        return out;
    }

private:
    void separate(string num, string& real, string& imaginary) {
        bool flag = true;
        for (int i = 0; i < num.size() - 1; ++i) {
            char c = num[i];
            if (c == '+')
                flag = false;
            else if (flag)
                real.push_back(c);
            else
                imaginary.push_back(c);
        }
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.complexNumberMultiply("1+-1i", "0+0i") << endl;
    cout << "--------------------" << endl;
    return 0;
}
