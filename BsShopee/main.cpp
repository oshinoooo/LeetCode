/*
用户账单逾期扣分
详细描述
给定一个字符串来表示一个用户的账单逾期记录，这个记录仅包含以下两个字符：

'N': 没有逾期，正常

'Y'：有逾期

如“YNN”表示用户逾期一次，“NNN”表示用户没有逾期，“NNYYYYYNNYY”表示用户最大连续逾期5次；

用户逾期扣分规则如下：

 0< 最大连续逾期 <= 3	 3 < 最大连续逾期 <= 7	7 < 最大连续逾期
-10	-15	-25
请根据用户逾期纪录计算返回用户最终逾期扣分数

其他
时间限制: 1000ms

内存限制:256.0MB

输入输出示例
示例1
输入
复制
"NNN"
输出
复制
0
说明
没有逾期，扣0分
示例2
输入
复制
"YYN"
输出
复制
-10
说明
最大连续逾期数2，扣10分
示例3
输入
复制
"NNYYYYYNNYY"
输出
复制
-15
说明
最大连续逾期数5，扣15分
*/

/*
乘积最大子数组
详细描述
给你一个整数数组 nums ，请在时间复杂度为O(n) 下找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积

其他
时间限制: 1000ms

内存限制:256.0MB

输入输出示例
示例1
输入
复制
[2,3,-2,4,-1]
输出
复制
48
*/

/*
最少计算次数
详细描述
给定两个数字 (x, y)，允许以下两种计算：

1.同时对两个数加1， 即 (x, y) -> (x+1, y+1)

2.同时对两个数乘2，即 (x, y) -> (x*2, y*2)

求要将 (x, y) 转换成 (X,Y)，至少需要多次计算，如果不能转换，返回-1



注：x,y,X,Y > 0

其他
时间限制: 1000ms

内存限制:256.0MB

输入输出示例
示例1
输入
复制
10,100,22,202
输出
复制
2
说明
1. (10, 100)  +1 -> (11, 101)
2. (11, 101) *2 -> (22, 202)
示例2
输入
复制
1,2,4,6
输出
复制
2
说明
1. (1, 2)  +1 -> (2, 3)
1. (2, 3) *2 -> (4, 6)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calDPDScore(string dpdInfo) {
        if (dpdInfo.empty())
            return 0;

        int length = dpdInfo.size();

        int maxTime = 0;
        int tmpTime = 0;
        for (int i = 0; i < length; ++i) {
            if (dpdInfo[i] == 'Y') {
                maxTime = max(maxTime, ++tmpTime);
            }
            else {
                tmpTime = 0;
            }
        }

        if (maxTime == 0)
            return 0;

        if (maxTime <= 3)
            return -10;

        if (maxTime <= 7)
            return -15;

        return -25;
    }

    long long GetSubArrayMaxProduct(vector<long>& nums) {
        int n = nums.size();

        long long maxMul = 0;
        vector<long long> dpMax(n, nums[0]);
        vector<long long> dpMin(n, nums[0]);

        for (int i = 1; i < n; ++i) {
            long long tmp = nums[i];
            dpMax[i] = max(tmp, max(tmp * dpMax[i - 1], tmp * dpMin[i - 1]));
            dpMin[i] = min(tmp, min(tmp * dpMax[i - 1], tmp * dpMin[i - 1]));
            maxMul = max(maxMul, dpMax[i]);
        }

        return maxMul;
    }

    long long GetMinCalculateCount(long long sourceX,
                                   long long sourceY,
                                   long long targetX,
                                   long long targetY) {
        long long minOperation = LONG_LONG_MAX;
        myGetMinCalculateCount(sourceX, sourceY, targetX, targetY, 0, minOperation);
        return minOperation == LONG_LONG_MAX ? -1 : minOperation;
    }

private:
    void myGetMinCalculateCount(long long sourceX,
                                long long sourceY,
                                const long long& targetX,
                                const long long& targetY,
                                long long operation,
                                long long& minOperation) {
        if ((sourceX == targetX && sourceY == targetY)) {
            minOperation = min(minOperation, operation);
            return;
        }

        if (targetX < sourceX || targetY < sourceY)
            return;

        if (LONG_LONG_MAX == sourceX || LONG_LONG_MAX == sourceY)
            return;
        myGetMinCalculateCount(sourceX + 1, sourceY + 1, targetX, targetY, operation + 1, minOperation);

        if (LONG_LONG_MAX / 2 < sourceX || LONG_LONG_MAX / 2 < sourceY)
            return;
        myGetMinCalculateCount(sourceX * 2, sourceY * 2, targetX, targetY, operation + 1, minOperation);
    }
};

int main() {
    Solution s;
    cout << "--------------------" << endl;
    char dpdInfo[] = "YNYYNYYYNYYYYNYYYYY";
    cout << s.calDPDScore(dpdInfo) << endl;
    cout << "--------------------" << endl;
    vector<long> nums = {2,3,-2,4,-1};
    cout << s.GetSubArrayMaxProduct(nums) << endl;
    cout << "--------------------" << endl;
    cout << s.GetMinCalculateCount(LONG_LONG_MAX - 1, LONG_LONG_MAX - 2, LONG_LONG_MAX, LONG_LONG_MAX) << endl;
    cout << "--------------------" << endl;
    return 0;
}
