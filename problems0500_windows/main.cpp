#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <cctype>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<string> findWords(vector<string>& words)
    {
        set<char> line1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                           'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
        set<char> line2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                           'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
        set<char> line3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm',
                           'Z', 'X', 'C', 'V', 'B', 'N', 'M',};
        vector<set<char>> lines = {line1, line2, line3};

        vector<string> out;
        for (auto& word : words)
        {
            int line_num;
            if (line1.count(tolower(word[0])))
                line_num = 0;
            else if (line2.count(word[0]))
                line_num = 1;
            else if (line3.count(word[0]))
                line_num = 2;

            int i;
            for (i = 1; i < word.size(); ++i)
            {
                if (lines[line_num].count(word[i]) == 0)
                    break;
            }

            if (i == word.size())
                out.emplace_back(word);
        }

        return out;
    }
};

int main_backup()
{
    // list
    cout << "--------------------" << endl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // tree
    cout << "--------------------" << endl;
    //    TreeNode* n1 = new TreeNode(1);
    //    TreeNode* n2 = new TreeNode(2);
    //    TreeNode* n3 = new TreeNode(3);
    //    TreeNode* n4 = new TreeNode(4);
    //    TreeNode* n5 = new TreeNode(5);
    //    TreeNode* n6 = new TreeNode(6);
    //    TreeNode* n7 = new TreeNode(7);
    //
    //    n1->left = n2;
    //    n1->right = n3;
    //    n2->left = n4;
    //    n2->right = n5;
    //    n3->left = n6;
    //    n3->right = n7;

    // show
    cout << "--------------------" << endl;
//    vector<int> out;
//    for (auto num : out)
//        cout << num << " ";
//    cout << endl;

    vector<vector<int>> out;
    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }

    cout << "--------------------" << endl;
    return 0;
}

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<string> words = {"Hello","Alaska","Dad","Peace"};
    vector<string> out = s.findWords(words);
    for (auto num : out)
        cout << num << endl;
    cout << "---------------------" << endl;
    return 0;
}
