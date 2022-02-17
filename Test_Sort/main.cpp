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

    void selection_sort(vector<int>& in)
    {
        for (int i = 0; i < in.size() - 1; ++i)
        {
            int index = 0;
            for (int j = 0; j < in.size() - i; ++j)
            {
                if (in[j] >= in[index])
                    index = j;
            }
            swap(in[index], in[in.size() - i - 1]);
        }
    }

    void selection_sort2(vector<int>& arr)
    {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] < arr[min])
                    min = j;
            }
            std::swap(arr[i], arr[min]);
        }
    }

    void insertion_sort1(vector<int>& arr)
    {
        for (int i = 1; i < arr.size(); ++i)
        {
            int number = arr[i];
            int right = i - 1;
            while (right >= 0 && number < arr[right])
            {
                arr[right + 1] = arr[right];
                --right;
            }
            arr[right + 1] = number;
        }
    }

    void insertion_sort2(vector<int>& arr)
    {
        for (int i = 1; i < arr.size(); ++i)
        {
            int number = arr[i];
            int right = i - 1;
            while((right >= 0) && (number < arr[right]))
            {
                arr[right + 1] = arr[right];
                right--;
            }
            arr[right + 1] = number;
        }
    }
};

int main()
{
    cout << "--------------------" << endl;
    Solution s;
    vector<int> in1 = {5, 7, 0, 1, 9, 6, 3, 4, 8, 2};

//    s.bubble_sort(in1);
//    s.quick_sort(in1, 0, in.size() - 1);
//    s.selection_sort(in1);
//    s.selection_sort2(in1);
//    s.insertion_sort1(in1);
//    s.insertion_sort2(in1);

    for (auto i : in1)
        cout << i << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}
