#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string out;
        while (columnNumber > 0)
        {
            int tmp = (columnNumber - 1) % 26 + 1;
            out.insert(out.begin(), tmp - 1 + 'A');
            columnNumber = (columnNumber - tmp) / 26;
        }
        return out;
    }
};

int main()
{
    std::cout << "---------------" << std::endl;
    Solution s;
    cout << s.convertToTitle(26) << endl;
    std::cout << "---------------" << std::endl;
    return 0;
}
