#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int count = 0;

        for (int i = 0; i < seats.size(); ++i)
            count += abs(students[i] - seats[i]);

        return count;
    }

    bool winnerOfGame(string colors)
    {
        int count_A = 0;
        int count_B = 0;

        for (int i = 1; i < colors.size() - 1; ++i)
        {
            if (colors[i] == 'A')
                ++count_A;
            else if (colors[i] == 'B')
                ++count_B;
        }


    }
};

void test1()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> seats = {3, 1, 5};
    vector<int> students = {2, 7, 4};
    cout << s.minMovesToSeat(seats, students) << endl;
}

void test2()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.winnerOfGame("AAAABBBB") << endl;
}

int main()
{
    test1();
    test2();
    cout << "---------------------" << endl;
    return 0;
}
