#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
翻转字符串
时间限制： 1000MS
内存限制： 65536KB
题目描述：
在一张透明的纸上，用笔写下一个字符串。然后将纸翻面，请你判断正面和背面看到的字符串是否一样。 请注意，字符串在正反面看上去一样，必须要求每个字符是左右对称的，比如'W'字符是左右对称的，而'N'不是。



输入描述
输入包含多组数据，每组数据一行，包含一个全由大写字母构成的字符串S。

输出描述
如果正面和背面看到的字符串一样。输出YES，否则输出NO


样例输入
ABA
AHA
HHA
样例输出
NO
YES
NO

提示
|S|≤1000，数据组数不会超过20
ABA在背面看过去的时候，B是反着写的，所以不一样。
HHA在背面看过去为AHH
*/

/*
黑白翻转
时间限制： 3000MS
内存限制： 589824KB
题目描述：
有n个黑白棋子，它们的一面是黑色，一面是白色。它们被排成一行，位置可以用标号1~n来表示。一开始，所有的棋子都是黑色向上，有q次操作，每次操作将位置标号在区间[L, R]内的所有棋子翻转（原来黑色变白色，原来白色变黑色）。请在每次操作后，求这n个棋子中，黑色向上的棋子个数。



输入描述
第一行两个整数 n, q，1 <= n <= 1018, q <= 300;

后面q行，每行两个整数 L,R，1 <= L <=R <= n。

输出描述
q行，每行一个整数，表示每次操作后黑色向上的棋子个数。


样例输入
100 2
1 30
21 40
样例输出
70
70
*/

void test1() {
    string word;
    while (cin >> word) {
        string tmp = word;
        reverse(tmp.begin(), tmp.end());

        if (tmp != word) {
            cout << "NO" << endl;
            continue;
        }

        bool flag = true;
        for (char c : tmp) {
            if (c != 'A' && c != 'H' && c != 'I' &&
                c != 'M' && c != 'O' && c != 'T' &&
                c != 'U' && c != 'V' && c != 'W' &&
                c != 'X' && c != 'Y') {
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if (!flag)
            continue;

        cout << "YES" << endl;
    }
}

//1000000000000000000 2
//1 1000000000000000000
//1 1000000000000000000

void test2() {
    long long n;
    cin >> n;

    long long q;
    cin >> q;

    vector<vector<long long>> operations;
    for (long long i = 0; i < q; ++i) {
        long long l;
        cin >> l;

        long long r;
        cin >> r;

        operations.push_back({l, r});
    }

    long long black = n;
    vector<long long> nums(n, 1);

    for (long long i = 0; i < operations.size(); ++i) {
        long long l = operations[i][0] - 1;
        long long r = operations[i][1] - 1;

        for (long long j = l; j <= r; ++j) {
            if (nums[j] == 1) {
                nums[j] = 0;
                --black;
            }
            else {
                nums[j] = 1;
                ++black;
            }
        }

        cout << black << endl;
    }
}

int main() {
//    test1();
    test2();
    return 0;
}
