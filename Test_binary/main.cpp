#include <iostream>
#include <vector>

using namespace std;

int binary_search(const vector<int>& numbers, int target)
{
    if (numbers.empty())
        return -1;

    int mid, left = 0, right = numbers.size() - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if(numbers[mid] == target)
            return mid;
        else if (mid > target)
            right = mid - 1;
        else if (mid < target)
            left = mid + 1;
    }
    return -1;
}

int binary_left_boundary(const vector<int>& numbers, int target)
{
    if (numbers.empty())
        return -1;

    int mid, left = 0, right = numbers.size();

    while (left < right)
    {
        mid = (left + right) / 2;
        if(numbers[mid] == target)
            right = mid;
        else if (mid > target)
            right = mid;
        else if (mid < target)
            left = mid + 1;
    }
    return left;
}

int binary_right_boundary(const vector<int>& numbers, int target)
{
    if (numbers.empty())
        return -1;

    int mid, left = 0, right = numbers.size();

    while (left < right)
    {
        mid = (left + right) / 2;
        if(numbers[mid] == target)
            left = mid + 1;
        else if (mid > target)
            right = mid;
        else if (mid < target)
            left = mid + 1;
    }
    return left - 1;
}

int main()
{
    cout << "---------------" << endl;
    vector<int> numbers = {0, 1, 2, 3, 3, 3, 3, 4, 5};
    cout << binary_search(numbers, 3) << endl;
    cout << binary_left_boundary(numbers, 3) << endl;
    cout << binary_right_boundary(numbers, 3) << endl;
    cout << "---------------" << endl;
    return 0;
}
