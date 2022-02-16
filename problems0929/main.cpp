#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int numUniqueEmails(vector<string>& emails)
    {
        set<string> addresses;

        for (auto email : emails)
        {
            string tmp_address;
            bool domain = false;
            bool jump = false;

            for (auto c : email)
            {
                if (c == '@')
                    domain = true;

                if (!domain)
                {
                    if (c == '+')
                        jump = true;

                    if (jump || c == '.')
                        continue;
                }
                tmp_address.push_back(c);
            }
            addresses.insert(tmp_address);
        }

        return addresses.size();
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<string> emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    cout << s.numUniqueEmails(emails) << endl;
    cout << "---------------------" << endl;
    return 0;
}
