#include <iostream>

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int lengthT = myMaxConsecutiveAnswers(answerKey, k, 'T');
        int lengthF = myMaxConsecutiveAnswers(answerKey, k, 'F');
        return max(lengthT, lengthF);
    }

private:
    int myMaxConsecutiveAnswers(const string& answerKey, const int& k, const char& c) {
        int maxLength = 0;
        int tmpLength = 0;
        int head = 0;
        int count = 0;

        int n = answerKey.size();
        for (int i = 0; i < n; ++i) {
            if (answerKey[i] == c) {
                ++count;
                while (k < count) {
                    ++head;
                }
            }

            maxLength = max(maxLength, i - head + 1);
        }

        return maxLength;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.maxConsecutiveAnswers("TTFF", 2) << endl;
    cout << "--------------------" << endl;
    return 0;
}