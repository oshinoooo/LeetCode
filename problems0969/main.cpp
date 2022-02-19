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
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> out;

        for (int n = arr.size(); 1 < n; --n) {
            int index = max_element(arr.begin(), arr.begin() + n) - arr.begin();
            if (index == n - 1)
                continue;

            reverse(arr.begin(), arr.begin() + index + 1);
            reverse(arr.begin(), arr.begin() + n);
            out.push_back(index + 1);
            out.push_back(n);
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> arr = {3,2,4,1};
    vector<int> out = s.pancakeSort(arr);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
