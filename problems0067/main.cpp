#include <iostream>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int ptr1 = a.size() - 1;
        int ptr2 = b.size() - 1;
        int carry = 0;
        string out;

        while (ptr1 >= 0 || ptr2 >= 0)
        {
            if (ptr1 >= 0 && ptr2 >= 0)
            {
                out.insert(out.begin(),a[ptr1] + b[ptr2] - '0' + carry);
                --ptr1;
                --ptr2;
            }
            else if (ptr2 < 0)
            {
                out.insert(out.begin(), a[ptr1] + carry);
                --ptr1;
            }
            else if (ptr1 < 0)
            {
                out.insert(out.begin(), b[ptr2] + carry);
                --ptr2;
            }

            if (out[0] > '1')
            {
                carry = 1;
                out[0] -= 2;
            }
            else
                carry = 0;
        }

        if (carry == 1)
            out.insert(out.begin(), '1');
        return out;
    }
};

int main()
{
    std::cout << "---------------" << std::endl;
    Solution s;
    cout << s.addBinary("1111", "1111") << endl;
    std::cout << "---------------" << std::endl;
    return 0;
}
