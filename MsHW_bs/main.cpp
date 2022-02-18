#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

//string standerd(string path)
//{
//    if (path.empty())
//        return "";
//
//    stack<string> sta;
//    string tmp = "/";
//    for (int i = 0; i < path.size(); ++i)
//    {
//
//        if (('a' <= path[i] && path[i] <= 'z') || path[i] == '.')
//        {
//            tmp.push_back(path[i]);
//
//            if (i == path.size() - 1)
//                sta.push(tmp);
//        }
//
//        if (path[i] == '.')
//        {
//            if (tmp == "..")
//                return "/";
//
//            if (0 <= i - 1 && ('a' <= path[i - 1] && path[i - 1] <= 'z') ||
//                i + 1 < path.size() && ('a' <= path[i + 1] && path[i + 1] <= 'z'))
//                return "/";
//        }
//
//        if (path[i] == '/')
//        {
//            if (i + 1 < path.size() && path[i + 1] == '/')
//                return "/";
//
//            if (tmp != "/")
//            {
//                sta.push(tmp);
//                tmp = "/";
//            }
//        }
//    }
//
//    string out;
//    int count = 0;
//    while (!sta.empty())
//    {
//        if (sta.top() == "/.")
//            sta.pop();
//        else if (sta.top() == "/..")
//        {
//            ++count;
//            sta.pop();
//        }
//        else if (count)
//        {
//            --count;
//            sta.pop();
//        }
//        else
//        {
//            out.insert(out.begin(), sta.top().begin(), sta.top().end());
//            sta.pop();
//        }
//    }
//
//    if (count)
//        return "/";
//
//    return out;
//}
//
//int main1()
//{
//    string input;
//    while (cin >> input)
//        cout << standerd(input) << endl;
//    return 0;
//}

vector<string> seperate(string input)
{
    vector<string> inputs;
    string tmp;

    for (int i = 0; i < input.size(); ++i)
    {
        if ()
    }

    return inputs;
}

vector<string> count(string input)
{
    vector<string> inputs = seperate(input);

    vector<bool> valid(inputs.size(), true);

    for (int i = 0; i < inputs.size(); ++i)
    {
        for (auto c : inputs[i])
        {
            if (c < 'a' || 'z' < c)
            {
                valid[i] = false;
                break;
            }
        }
    }

    map<string, int> words_cout;
    for (int i = 0; i < inputs.size(); ++i)
    {
        if (valid[i])
            ++words_cout[inputs[i]];
    }

    int max = words_cout.rbegin()->second;

    vector<string> max_words;
    for (auto word : words_cout)
    {
        if (word.second == max)
            max_words.push_back(word.first);
    }

    vector<string> out;
    for (auto max_word : max_words)
    {
        string tmp;
        for (int i = 0; i < inputs.size(); ++i)
        {
            if (inputs[i] == max_word)
            {
                if (i - 1 >= 0 && valid[i - 1])
                {
                    tmp.append(inputs[i - 1]);
                    tmp.push_back(' ');
                    tmp.append(max_word);
                    out.push_back(tmp);
                    tmp.clear();
                }

                if (i + 1 < inputs.size() && valid[i + 1])
                {
                    tmp.append(max_word);
                    tmp.push_back(' ');
                    tmp.append(inputs[i + 1]);
                    out.push_back(tmp);
                    tmp.clear();
                }
            }
        }
    }

    return out;
}

int main()
{
    string input;
    while (getline(cin, input))
    {
        vector<string> out = count(input);
        for (auto str : out)
            cout << str << endl;
    }
    return 0;
}

//int calculate(int m, int n, int x, vector<pair<int, int>> locations)
//{
//    vector<vector<bool>> fields(m, vector<bool>(n, false));
//
//    for (auto location : locations)
//        fields[location.first][location.second] = true;
//
//    int count = 0;
//    for (int i = 0; i < fields.size(); ++i)
//    {
//        for (int j = 0; j < fields[0].size(); ++j)
//        {
//            if (fields[i][j])
//            {
//                ++count;
//                for (int k = 0; k < 3; ++k)
//                {
//                    for (int l = 0; l < 3; ++l)
//                    {
//                        if (i + k < fields.size() && j + l < fields[0].size())
//                            fields[i + k][j + l] = false;
//                    }
//                }
//            }
//        }
//    }
//
//    return count;
//}
//
//int main()
//{
//    int m;
//    int n;
//    int x;
//    int row;
//    int col;
//
//    while (cin >> m >> n >> x)
//    {
//        vector<pair<int, int>> locations;
//        for (int i = 0; i < x; ++i)
//        {
//            cin >> row >> col;
//            locations.push_back({row, col});
//        }
//
//        cout << calculate(m, n, x, locations) << endl;
//    }
//}
