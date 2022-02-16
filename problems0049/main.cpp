#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto& str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }

        vector<vector<string>> out;
        for (auto m : mp)
            out.push_back(m.second);
        return out;
    }

    vector<vector<string>> groupAnagrams2(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto& str: strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }

        vector<vector<string>> out;
        for (auto m : mp)
            out.emplace_back(m.second);
        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> out = s.groupAnagrams(strs);
    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
