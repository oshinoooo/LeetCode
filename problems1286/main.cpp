#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>

using namespace std;

class CombinationIterator
{
public:
    CombinationIterator(string characters, int combinationLength)
    {
        cur = 0;
        sort(characters.begin(), characters.end());
        string tmp;
        generate(characters, combinationLength, tmp, arrangement);
    }

    string next()
    {
        return arrangement[cur++];
    }

    bool hasNext()
    {
        return cur < arrangement.size();
    }

private:
    void generate(string& characters, int& combinationLength, string& tmp, vector<string>& out)
    {
        if (tmp.size() == combinationLength)
        {
            out.push_back(tmp);
            return;
        }

        if (characters.empty())
            return;

        string tmp_characters = characters.substr(1, characters.size() - 1);

        tmp.push_back(characters[0]);
        generate(tmp_characters, combinationLength, tmp, out);

        tmp.pop_back();
        generate(tmp_characters, combinationLength, tmp, out);
    }

private:
    int cur;
    vector<string> arrangement;
};

//class CombinationIterator {
//private:
//    vector<int> pos;
//    string s;
//    bool finished;
//
//public:
//    CombinationIterator(string characters, int combinationLength) {
//        s = characters;
//        pos.resize(combinationLength);
//        iota(pos.begin(), pos.end(), 0);
//        finished = false;
//    }
//
//    string next() {
//        string ans;
//        for (int p: pos) {
//            ans += s[p];
//        }
//        int i = -1;
//        for (int k = pos.size() - 1; k >= 0; --k) {
//            if (pos[k] != s.size() - pos.size() + k) {
//                i = k;
//                break;
//            }
//        }
//        if (i == -1) {
//            finished = true;
//        }
//        else {
//            ++pos[i];
//            for (int j = i + 1; j < pos.size(); ++j) {
//                pos[j] = pos[j - 1] + 1;
//            }
//        }
//        return ans;
//    }
//
//    bool hasNext() {
//        return !finished;
//    }
//};

int main()
{
    cout << "---------------------" << endl;
    CombinationIterator c("bca", 2);
    cout << c.next() << endl;
    cout << c.hasNext() << endl;
    cout << c.next() << endl;
    cout << c.hasNext() << endl;
    cout << c.next() << endl;
    cout << c.hasNext() << endl;
    cout << "---------------------" << endl;
    return 0;
}
