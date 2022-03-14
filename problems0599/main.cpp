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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> index;
        for (int i = 0; i < list1.size(); i++)
            index[list1[i]] = i;

        vector<string> out;
        int minSum = INT_MAX;
        for (int i = 0; i < list2.size(); ++i) {
            if (index.count(list2[i])) {
                int tmpSum = i + index[list2[i]];
                if (tmpSum < minSum) {
                    out.clear();
                    out.push_back(list2[i]);
                    minSum = tmpSum;
                }
                else if (tmpSum == minSum)
                    out.push_back(list2[i]);
            }
        }

        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    vector<string> out = s.findRestaurant(list1, list2);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}
