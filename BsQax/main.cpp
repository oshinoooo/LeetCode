#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
// q1
    int LSubSequence(int N, vector<int>& sequence) {
        vector<int> tmp = {INT_MIN};
        return myLSubSequence(sequence, tmp, 0);
    }

    int myLSubSequence(const vector<int>& sequence, vector<int>& tmp, int index) {
        int n = sequence.size();

        if (n <= index)
            return tmp.size() - 1;

        int maxLength = tmp.size() - 1;

        for (int i = index; i < n; ++i) {
            if (tmp.back() >= sequence[i])
                continue;

            tmp.push_back(sequence[i]);
            maxLength = max(maxLength, myLSubSequence(sequence, tmp, i + 1));
            tmp.pop_back();
        }

        return maxLength;
    }

// q2
    int count(vector<string>& arr) {
        int count = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (valid(arr[i]))
                ++count;
        }

        return count;
    }

    bool valid(string str) {
        if (str.empty())
            return false;

        stack<char> stk;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(') {
                stk.push(str[i]);
            }
            else if (stk.empty()) {
                return false;
            }
            else {
                stk.pop();
            }
        }

        return stk.empty();
    }
};

void test1() {
    Solution s;
    vector<int> sequence = {1, 7, 3, 5, 9, 4, 8};
    cout << s.LSubSequence(7, sequence);
}

void test2() {
    Solution s;
    vector<string> arr = {"(((())))", "()"};
    cout << s.count(arr);
}

int main() {
    test1();
//    test2();
    return 0;
}
