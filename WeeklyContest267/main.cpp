#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int timeRequiredToBuy(vector<int>& tickets, int k)
    {
        int time = 0;

        while (true)
        {
            for (int i = 0; i < tickets.size(); ++i)
            {
                if (0 < tickets[i])
                {
                    --tickets[i];
                    ++time;
                }

                if (i == k && tickets[k] == 0)
                    return time;
            }
        }

        return time;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head)
    {
        int count = 0;
        int num = 1;

        ListNode* cur = head;
        ListNode* pre;

        while (cur)
        {
            ++count;

            if (!cur->next && count % 2 == 0)
            {
                ListNode* next = cur->next;
                reverse(pre->next, cur);
                pre->next->next = next;
                pre->next = cur;
                break;
            }

            if (count == num)
            {
                if (num % 2 == 1)
                {
                    pre = cur;
                    cur = cur->next;
                }

                if (num % 2 == 0)
                {
                    ListNode* next_pre = pre->next;
                    ListNode* next = cur->next;

                    reverse(pre->next, cur);
                    pre->next->next = next;
                    pre->next = cur;

                    pre = next_pre;
                    cur = next;
                }

                count = 0;
                ++num;
            }
            else
                cur = cur->next;
        }

        return head;
    }

    string decodeCiphertext(string encodedText, int rows)
    {
        int cols = encodedText.size() / rows;
        vector<vector<char>> grid(rows, vector<char>(cols));

        int pos = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
                grid[i][j] = encodedText[pos++];
        }

        int x = 0;
        int y = 0;
        int next_y = 1;
        string originalText;

        while (y < cols)
        {
            originalText.push_back(grid[x][y]);
            if (rows <= ++x || cols <= ++y)
            {
                x = 0;
                y = next_y;
                ++next_y;
            }
        }

        while (!originalText.empty() && originalText.back() == ' ')
            originalText.pop_back();
        return originalText;
    }

private:
    void reverse(ListNode* head, ListNode* tail)
    {
        ListNode* new_head = new ListNode(0);
        ListNode* cur = head;

        while (cur)
        {
            ListNode* tmp = new_head->next;
            new_head->next = cur;

            if (cur == tail)
            {
                new_head->next->next = tmp;
                break;
            }

            cur = cur->next;
            new_head->next->next = tmp;
        }
    }
};

int test1()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> tickets = {5,1,1,1};
    int k = 0;
    cout << s.timeRequiredToBuy(tickets, k) << endl;
    return 0;
}

int test2()
{
    cout << "---------------------" << endl;
    Solution s;

    ListNode* n1 = new ListNode(0);
    ListNode* n2 = new ListNode(4);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(1);
    ListNode* n5 = new ListNode(3);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode* n0 = s.reverseEvenLengthGroups(n1);

    while (n0 != nullptr)
    {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    return 0;
}

int test3()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.decodeCiphertext("coding", 1) << endl;
    return 0;
}

int main()
{
    test1();
    test2();
    test3();
    cout << "---------------------" << endl;
    return 0;
}
