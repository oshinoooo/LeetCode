
/*
时间限制： 1000MS
内存限制： 65536KB
题目描述：
小团最近在玩手机上的四川麻将。四川麻将的一种玩法是玩家摸完牌之后选择三张花色一样的牌按某种顺序换给其他人。
为了尽可能破坏对手的游戏体验，小团每次都会选择不连续的三张牌换出去。
比如小团手上有14568这5张条子，则他可能会选择158这三张条子换出去。爱思考的小团马上对这个问题进行了推广。

小团把这个问题进行了简化，现在他给了你一个可重集合，
并希望你从中选出一个尽可能大的子集使得其中没有两个数是“连续”的（连续是指即这两个数之差的绝对值不超过1）。



输入描述
        第一行有一个整数n（1<=n<=100000），代表小团给你的可重集大小。

第二行有n个空格隔开的整数（范围在1到200000之间），代表小团给你的可重集。

输出描述
        输出满足条件的最大子集的大小。


样例输入
6
1 2 3 5 6 7
*/

/*
最大子段和
时间限制： 3000MS
内存限制： 589824KB
题目描述：
最大子段和是一个经典问题，即对于一个数组找出其和最大的子数组。

现在允许你在求解该问题之前翻转这个数组的连续一段（如翻转{1,2,3,4,5,6}的第三个到第五个元素组成的子数组得到的是{1,2,5,4,3,6}），则翻转后该数组的最大子段和最大能达到多少？

输入描述
第一行有一个正整数n(1<=n<=100000)，代表数组长度。

第二行有n个空格隔开的整数(-1000<=ai<=1000)，代表给出数组。

输出描述
输出一个整数，代表若允许你翻转一个子数组 ，则翻转后所得数组的最大子段和最大能到多少。


样例输入
6
-1 3 -5 2 -1 3
样例输出
7

提示
样例解释

如样例中可以翻转第二个到第三个元素组得到{-1,-5,3,2,-1,3}，此时最大子段和为3+2-1+3=7。

也可以翻转第三个到第六个元素组得到{-1,3,3,-1,2,-5}，此时最大子段和为3+3-1+2=7。

若翻转第一个到第三个元素组得到{-5,3,-1,2,-1,3}，则最大子段和为3-1+2-1+3=6。
 */

/*
切豆腐
时间限制： 3000MS
内存限制： 589824KB
题目描述：
小美在学做麻婆豆腐。但她的刀工不是很好，切豆腐的时候容易切歪。为了切出更均匀的豆腐，小美想在每一次下刀之后知道切出来的豆腐块中体积最大的那块有多大。



输入描述
第一行有两个空格隔隔开的整数n,m(1<=n,m<=1000)，代表这块豆腐最开始是长宽高均为n厘米的正方体，而小美总共切了m刀。

第二行有m个以空格隔开的小写字母。每个字母都是x,y,z中的一个。第i个代表小美切的第i刀垂直于哪个坐标轴。

第三行有m个大于0且小于n的正整数，数字间有空格隔开。第 i 个代表小美切的第 i 刀所在平面到豆腐的右上角（或者你可以任选一个角并固定，不难证明无论选哪个角答案均相同）的距离。



为了切出美观的豆腐，小美提前把豆腐塞进了冷冻室，所以在切的时候豆腐不会产生形变且切出来的豆腐块不会产生位移。小美每次下刀都会把整块豆腐切开，不存在切到一半收刀这种情况，所以切出来的每块小豆腐都是边长为正整数的长方体。

输出描述
输出m行，每行一个整数，代表在小美切下第 i 刀后形成的豆腐块中体积最大的那块的体积。


样例输入
2 3
x y z
1 1 1
样例输出
4
2
1
*/

/*
区间操作
时间限制： 1000MS
内存限制： 65536KB
题目描述：
小团在努力地刷题。在刷题的过程中小团碰到了一道经典的数据结构题，即给出一个长度为n的数组，你需要进行m次数组上的区间操作，操作包含将区间内所有数加上一个值和查询一个区间内所有数的和。现在他想知道，如果允许重新排列初始数组中的元素并依次进行操作，则操作中所有查询区间和的答案之和能够达到多大？



输入描述
第一行有两个数n,m(1<=n<=5000,1<=m<=500)，代表数组长度和操作次数。

第二行有n个数，代表初始数组中的元素。

接下来m行每行形如1 l r或2 l r k，分别代表查询下标属于[l,r]的元素之和这一操作和将下标属于[l,r]的元素全部加上一个定值k。其中l,r,k满足1<=l<=r<=n，1<=k<=5000。

数字间两两均有空格隔开。

输出描述
输出一个整数，即若允许你重新排列初始数组，则进行m次操作后产生的所有输出之和最大能够达到多少？

如样例中将数组3 4 2 1 5重排为1 3 5 4 2，则操作如下：



最终输出之和为9+16+17=42。


样例输入
5 5
3 4 2 1 5
1 1 3
2 3 4 2
1 2 4
2 2 3 2
1 3 5
样例输出
42
*/

/*
XaYb
时间限制： 1000MS
内存限制： 65536KB
题目描述：
小团在上课时发现了他手机内置的一个小游戏，名为XaYb。游戏程序首先会随机一个不包含重复数字的长度为n的数字串s，而玩家需要通过询问来推理出s的内容。玩家可以进行任意轮询问，每轮询问时玩家需要输入一个长度为n且不包含重复数字的数字串t，然后游戏程序会给出两个数字作为答案，第一个是s和t有多少个位置上的数字相同（记为a），第二个是t中有多少个数字在s中出现了但位置是错的（记为b）。

比如s=7926时，若玩家询问串t=7246，则游戏会返回a=2,b=1，因为s和t的第一位和第四位相同，t的第二位在s中出现但不在第二位。又比如s=1532,t=4521，则游戏会返回a=1,b=2，因为s和t的第二位相同，t的第三位和第四位在s中出现但分别在s的第四位和第一位。

长期睡眠不足的小团无法进行有效的推理，于是他决定先随机进行m次猜测，收集结果并找出字典序最小（本题中等价于其对应的数值最小）的满足这m次询问所得答案的串（记为r）。

现在你的任务是写一个程序帮助小团从m个询问及答案中找到r这个串并将其输出。如果对应的串不可能存在，请输出"?"号



输入描述
第一行有两个空格隔开的整数n, m(1<=n<=8,1<=m<=100)，代表游戏中数字串的长度和小团进行的猜测次数。

接下来m行每行开头有一个长度为n的数字串t，然后是两个以空格隔开的整数a和b(0<=a,b<=n+1)，代表小团进行的一次猜测和对应的结果。  数字间两两有空格隔开。

输出描述
输出字典序最小的满足所有询问答案的串，若不存在输出一个半角问号。


样例输入
4 5
1234 3 0
1204 3 0
5678 0 1
5679 0 0
5670 0 0
样例输出
1284
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void test1() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    if (nums.empty()) {
        cout << 0 << endl;
        return;
    }

    sort(nums.begin(), nums.end());

    int maxLength = 1;

    /*
    for (int i = 0; i < n; ++i) {
        int tmpLength = 1;
        int tail = i;
        int curr = i + 1;

        while (curr < n) {
            if (nums[tail] != nums[curr] - 1) {
                ++tmpLength;
                tail = curr;
            }
            ++curr;
        }

        maxLength = max(maxLength, tmpLength);
    }
    */

    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = i - 1; 0 <= j; --j) {
            if (nums[j] + 1 != nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                maxLength = max(maxLength, dp[i]);
            }
        }
    }

    cout << maxLength << endl;
}

void test2() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    if (nums.empty()) {
        cout << 0 << endl;
        return;
    }

//    -1 3 -5 2 -1 3
//    reverse(nums.begin(), nums.begin() + 3);

    int maxSum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<int> tmpNums = nums;
            reverse(tmpNums.begin() + i, tmpNums.begin() + j + 1);

            for (int k = 0; k < n; ++k) {
                int tmpSum = 0;
                for (int l = k; l < n; ++l) {
                    tmpSum += tmpNums[l];
                    maxSum = max(maxSum, tmpSum);
                }
            }
        }
    }

    cout << maxSum << endl;
}

void test3() {
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<pair<char, int>> cuts;
    for (int i = 0; i < m; ++i) {
        char tmp;
        cin >> tmp;
        cuts.push_back({tmp, 0});
    }

    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        cuts[i].second = tmp;
    }

    int x = n;
    int y = n;
    int z = n;

    for (int i = 0; i < m; ++i) {
        char direction = cuts[i].first;
        int distance = cuts[i].second;

        if (direction == 'x') {
            int tmp = max(distance, x - distance);
            x = min(x, tmp);
        }
        else if (direction == 'y') {
            int tmp = max(distance, y - distance);
            y = min(x, tmp);
        }
        else {
            int tmp = max(distance, z - distance);
            z = min(x, tmp);
        }

        cout << x * y * z << endl;
    }
}

void test4() {
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<int> nums;
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<vector<int>> inputs;
    for (int i = 0; i < m; ++i) {
        int operation;
        cin >> operation;

        vector<int> tmp = {operation};

        if (operation == 1) {
            for (int j = 0; j < 2; ++j) {
                int num;
                cin >> num;
                tmp.push_back(num);
            }
        }
        else {
            for (int j = 0; j < 3; ++j) {
                int num;
                cin >> num;
                tmp.push_back(num);
            }
        }

        inputs.push_back(tmp);
    }

    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += nums[i];
            mp[{i, j}] = sum;
        }
    }

    nums = {1, 3, 5, 4, 2};

    int sum = 0;

    for (int i = 0; i < m; ++i) {
        int operation = inputs[i][0];
        int head = inputs[i][1] - 1;
        int tail = inputs[i][2] - 1;

        if (operation == 1) {
            sum += mp[{head, tail}];
        }
        else {
            int add = inputs[i][3];

            for (int j = head; j <= tail; ++j) {
                nums[j] += add;
            }

            for (int j = 0; j < n; ++j) {
                int tmpSum = 0;
                for (int k = 0; k < n; ++k) {
                    tmpSum += nums[k];
                    mp[{j, k}] = tmpSum;
                }
            }
        }
    }

    cout << sum << endl;
}

void test5() {

}

int main() {
    cout << "--------------------" << endl;
    test1();
    cout << "--------------------" << endl;
    test2();
    cout << "--------------------" << endl;
    test3();
    cout << "--------------------" << endl;
    test4();
    cout << "--------------------" << endl;
    test5();
    cout << "--------------------" << endl;
    return 0;
}
