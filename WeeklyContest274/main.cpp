#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int length = s.size();

        int ptr1 = -1;
        while (ptr1 < length - 1 && s[ptr1 + 1] == 'a') {
            ++ptr1;
        }

        int ptr2 = s.size();
        while (0 < ptr2 && s[ptr2 - 1] == 'b') {
            --ptr2;
        }

        return ptr1 + 1 == ptr2;
    }

    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].size();

        int total = 0;
        int pre_count = 0;
        for (auto& line : bank) {
            int cur_count = 0;
            for (auto& c : line) {
                if (c == '1') {
                    ++cur_count;
                }
            }

            if (cur_count) {
                total += pre_count * cur_count;
                pre_count = cur_count;
            }
        }

        return total;
    }

    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long new_mass = mass;
        for (auto& asteroid : asteroids) {
            if (asteroid <= new_mass) {
                new_mass += asteroid;
            }
            else {
                return false;
            }
        }
        return true;
    }

    int maximumInvitations(vector<int>& favorite) {
        int out = 0;


        return out;
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.checkString("aaabbb") << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> bank = {"011001","000000","010100","001000"};
    cout << s.numberOfBeams(bank) << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution s;
    int mass = 10;
    vector<int> asteroids = {3,9,19,5,21};
    cout << s.asteroidsDestroyed(mass, asteroids) << endl;
    return 0;
}

int test4() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> favorite = {2,2,1,2};
    cout << s.maximumInvitations(favorite) << endl;
    return 0;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    cout << "---------------------" << endl;
    return 0;
}
