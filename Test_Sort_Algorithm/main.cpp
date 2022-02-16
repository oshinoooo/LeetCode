#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void bubble_sort(vector<int>& in)
    {
        for (int i = 0; i < in.size() - 1; ++i)
        {
            for (int j = 0; j < in.size() - 1 - i; ++j)
            {
                if (in[j] > in[j + 1])
                {
                    int tmp = in[j];
                    in[j] = in[j + 1];
                    in[j + 1] = tmp;
                }
            }
        }
    }

    void quick_sort(vector<int>& in, int left, int right)
    {
        if (left >= right)
            return;

        int i = left;
        int j = right + 1;
        int flag = in[left];

        while (true)
        {
            while (in[++i] < flag && i != right) {}

            while (in[--j] > flag && j != left) {}

            if (i >= j) break;

            int tmp = in[i];
            in[i] = in[j];
            in[j] = tmp;
        }

        int tmp = in[j];
        in[j] = in[left];
        in[left] = tmp;
        quick_sort(in, left, j - 1);
        quick_sort(in, j + 1, right);
    }

    void quick_sort2(vector<int>& in, int left, int right)
    {
        if (in.empty() || in.size() == 1)
            return;

        if (left >= right)
            return;


    }
};

int main()
{
    cout << "--------------------" << endl;
    Solution s;
    vector<int> in = {5, 7, 0, 1, 9, 6, 3, 4, 8, 2};

//    s.bubble_sort(in);
    s.quick_sort(in, 0, in.size() - 1);

    for (auto i : in)
        cout << i << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}
