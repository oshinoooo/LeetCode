#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>
#include <ctime>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray1(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> count;
        for (auto& num : arr1)
            ++count[num];

        vector<int> out;
        for (auto& num : arr2) {
            for (int i = 0; i < count[num]; ++i)
                out.emplace_back(num);
            count.erase(num);
        }

        for (auto [num, times] : count) {
            for (int i = 0; i < times; ++i)
                out.emplace_back(num);
        }

        return out;
    }

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> rank;
        for (int i = 0; i < arr2.size(); ++i)
            rank[arr2[i]] = i;

        sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            if (rank.count(x))
                return rank.count(y) ? rank[x] < rank[y] : true;
            else
                return rank.count(y) ? false : x < y;
        });
        return arr1;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> out = s.relativeSortArray(arr1, arr2);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
