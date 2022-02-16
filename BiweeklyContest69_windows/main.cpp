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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    string capitalizeTitle(string title) {
        string out;
        string tmp;
        for (int i = 0; i < title.size(); ++i) {
            if (isalpha(title[i])) {
                tmp.push_back(tolower(title[i]));
            }

            if (title[i] == ' ' || i == title.size() - 1) {
                if (2 < tmp.size()) {
                    tmp[0] = toupper(tmp[0]);
                }

                if (!out.empty()) {
                    out.append(" ");
                }

                out.append(tmp);
                tmp.clear();
            }
        }

        return out;
    }

    int pairSum(ListNode* head) {
        vector<int> store;
        ListNode* tmp = head;
        while (tmp) {
            store.push_back(tmp->val);
            tmp = tmp->next;
        }

        int max_sum = 0;
        for (int i = 0; i < store.size() / 2; ++i) {
            max_sum = max(max_sum, store[i] + store[store.size() - 1 - i]);
        }

        return max_sum;
    }

    int longestPalindrome(vector<string>& words) {
        int count = 0;
        unordered_map<string, int> store;
        for (auto& word : words) {
            string reve = word.substr(1, 1) + word.substr(0, 1);
            if (store[reve]) {
                --store[reve];
                count += 4;
            }
            else {
                ++store[word];
            }
        }

        for (auto& word : store) {
            if (word.second % 2 && word.first[0] == word.first[1]) {
                count += 2;
                break;
            }
        }

        return count;
    }

    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size();
        int n = grid[0].size();

        int minHeight = INT_MAX;
        int minWidth = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (i != 0 && grid[i - 1][j] != 1)
                        minHeight = min(minHeight, i);

                    if (i != m - 1 && grid[i + 1][j] != 1)
                        minHeight = min(minHeight, m - 1 - i);

                    if (minHeight < stampHeight) {
                        return false;
                    }

                    if (j != 0 && grid[i][j - 1] != 1)
                        minWidth = min(minWidth, j);

                    if (j != n - 1 && grid[i][j + 1] != 1)
                        minWidth = min(minWidth, n - 1 - j);

                    if (minWidth < stampWidth) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.capitalizeTitle("capiTalIze tHe titLe") << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    cout << s.pairSum(n1) << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> words = {"bd"};
    cout << s.longestPalindrome(words) << endl;
    return 0;
}

int test4() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> grid = {{1,0,0,0}, {1,0,0,0}, {1,0,0,0}, {1,0,0,0}, {1,0,0,0}};
    int stampHeight = 4;
    int stampWidth = 3;
    cout << s.possibleToStamp(grid, stampHeight, stampWidth) << endl;
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
