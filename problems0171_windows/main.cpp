#include <iostream>

using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int number = 0;
        long multiple = 1;
        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            int k = columnTitle[i] - 'A' + 1;
            number += k * multiple;
            multiple *= 26;
        }
        return number;
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    string str = "FXSHRXW";
    cout << s.titleToNumber(str) << endl;
    cout << "---------------" << endl;
    return 0;
}
