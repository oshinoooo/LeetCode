#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution
{
public:
    Node* flatten(Node* head)
    {
        if (head == nullptr)
            return nullptr;

        stack<Node*> sta;
        sta.push(head);

        while (!sta.empty())
        {
            if (sta.top() == nullptr)
            {
                sta.pop();
            }

            Node* tmp = sta.top();
            while (tmp != nullptr)
            {
                sta.push(tmp->child);
                tmp = tmp->child;
            }
        }
    }
};

int main()
{
    std::cout << "---------------" << std::endl;
    Solution s;
    Node* n1 = new Node();
    cout << s.flatten(n1) << endl;
    std::cout << "---------------" << std::endl;
    return 0;
}
