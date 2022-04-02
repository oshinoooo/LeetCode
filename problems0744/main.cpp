#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char letter : letters) {
            if (letter > target)
                return letter;
        }
        return letters[0];
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    cout << s.nextGreatestLetter(letters, target) << endl;
    cout << "--------------------" << endl;
    return 0;
}