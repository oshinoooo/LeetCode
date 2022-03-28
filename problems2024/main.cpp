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
        int n = answerKey.length();
        int maxLength = 0;

        for (int left = 0, right = 0, sum = 0; right < n; right++) {
            sum += answerKey[right] != c;
            while (sum > k)
                sum -= answerKey[left++] != c;
            maxLength = max(maxLength, right - left + 1);
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