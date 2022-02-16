#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";

        string out;
        int integer = numerator / denominator;

        float decimal = 0;

        char tmp[10];
        itoa(integer, tmp, 10);


        out.push_back();


        return out;
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    cout << s.fractionToDecimal(1, 1) << endl;
    cout << "---------------" << endl;
    return 0;
}
