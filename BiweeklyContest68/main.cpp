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
    int mostWordsFound(vector<string>& sentences) {
        int max_count = 0;
        for (auto& sentence : sentences) {
            int count = 0;
            if (!sentence.empty()) {
                for (auto& c : sentence) {
                    if (c == ' ') {
                        ++count;
                    }
                }
                ++count;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }

    vector<string> findAllRecipes1(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_set<string> sup;
        for (auto& supply : supplies) {
            sup.insert(supply);
        }

        vector<string> out;
        for (int i = 0; i < recipes.size(); ++i) {
            bool flag = true;
            for (auto& ingredient : ingredients[i]) {
                if (!sup.count(ingredient)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                out.push_back(recipes[i]);
                sup.insert(recipes[i]);
            }
        }

        return out;
    }

    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_map<string, int> ids;
        unordered_map<int, string> recipeIdToString;
        int t = 0;
        for (auto &s: recipes) {
            if (!ids.count(s)) {
                ids[s] = t;
                recipeIdToString[t] = s;
                t++;
            }
        }
        for (auto &ingredient: ingredients) {
            for (auto &s: ingredient) {
                if (!ids.count(s)) {
                    ids[s] = t++;
                }
            }
        }
        for (auto &s: supplies) {
            if (!ids.count(s)) {
                ids[s] = t++;
            }
        }
        vector<vector<int>> adjList(t);
        vector<int> inDeg(t, 0);
        int n = recipes.size();
        for (int i = 0; i < n; ++i) {
            int m = ingredients[i].size();
            for (int j = 0; j < m; ++j) {
                int u = ids[ingredients[i][j]], v = ids[recipes[i]];
                adjList[u].push_back(v);
                inDeg[v]++;
            }
        }
        queue<int> q;
        for (auto &s: supplies) {
            q.push(ids[s]);
        }
        vector<int> make;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            make.push_back(u);
            for (auto v: adjList[u]) {
                if (--inDeg[v] == 0) q.push(v);
            }
        }
        vector<string> ans;
        for (auto id: make) {
            if (recipeIdToString.count(id)) ans.push_back(recipeIdToString[id]);
        }
        return ans;
    }

    bool canBeValid(string s, string locked) {
        int length = s.size();
        if (length % 2)
            return false;

        int count = 0;
        for (int i = 0; i < length; ++i) {
            if (s[i] == ')' && locked[i] == '1') {
                ++count;
                if (i + 1 - count < count)
                    return false;
            }
        }

        count = 0;
        for (int i = length - 1; 0 <= i; --i) {
            if (s[i] == '(' && locked[i] == '1') {
                ++count;
                if (length - i - count < count)
                    return false;
            }
        }

        return true;
    }
};

int test1() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    cout << s.mostWordsFound(sentences) << endl;
    return 0;
}

int test2() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> recipes = {"sandwich", "bread"};
    vector<vector<string>> ingredients = {{"bread", "meat"}, {"yeast", "flour"}};
    vector<string> supplies = {"yeast", "flour", "meat"};
    vector<string> out = s.findAllRecipes(recipes, ingredients, supplies);
    for (auto str : out)
        cout << str << " ";
    cout << endl;
    return 0;
}

int test3() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.canBeValid("))()))", "010100") << endl;
    return 0;
}

int test4() {
//    cout << "---------------------" << endl;
//    Solution s;
//    vector<vector<int>> fruits = {{2, 8}, {6, 3}, {8, 6}};
//    int startPos = 5;
//    int k = 4;
//    cout << s.maxTotalFruits(fruits, startPos, k) << endl;
//    return 0;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    cout << "---------------------" << endl;
    return 0;
}
