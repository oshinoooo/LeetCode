#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
    Solution() {
        srand(time(0));
    }

    int rand10() {
        int index = 49;
        while (40 < index)
            index = (rand7() - 1) * 7 + rand7();
        return (index - 1) / 4 + 1;
    }

private:
    int rand7() {
        return rand() % 7 + 1;
    }
};

int main()
{
    cout << "---------------------------------------" << endl;
    Solution s;
    for (int i = 0; i < 10; ++i)
        cout << s.rand10() << " ";
    cout << endl;
    cout << "---------------------------------------" << endl;
    return 0;
}
