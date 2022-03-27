#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getMaxPoint(const vector<int>& nums) {
        maxPoint = 0;

        int n = nums.size();
        vector<vector<int>> sections;
        int prev = 0;
        int next = 0;
        while (next < n) {
            while (next < n && nums[prev] == nums[next])
                ++next;

            sections.push_back({next - prev, nums[prev]});
            prev = next;
        }

        int m = sections.size();
        for (int i = 0; i < m; ++i)
            myGetMaxPoint(sections, i, 0);

        return maxPoint;
    }

private:
    void myGetMaxPoint(vector<vector<int>>& sections, int index, int tmpPoint) {
        if (sections.empty())
            return;

        tmpPoint += sections[index][0] * sections[index][0];
        maxPoint = max(maxPoint, tmpPoint);

        vector<vector<int>> nextSections = sections;
        nextSections.erase(nextSections.begin() + index);
        if (nextSections.empty())
            return;

        nextSections = mergeSections(nextSections);

        int m = nextSections.size();
        for (int i = 0; i < m; ++i)
            myGetMaxPoint(nextSections, i, tmpPoint);
    }

    vector<vector<int>> mergeSections(const vector<vector<int>>& sections) {
        if (sections.empty())
            return {};

        int n = sections.size();
        vector<vector<int>> out;

        for (int i = 1; i < n; ++i) {
            int color1 = sections[i - 1][1];
            int color2 = sections[i][1];

            if (color1 == color2)
                out.push_back({sections[i - 1][0] + sections[i][0], color1});
            else {
                out.push_back(sections[i - 1]);
                if (i == n - 1)
                    out.push_back(sections[i]);
            }
        }

        return out;
    }

private:
    int maxPoint;

// -----------------------------------------------------------------------------------------------

public:
    long long maxGapPresent(vector<long long>& nums, long long k) {
        if (nums.empty())
            return 0;

        maxGap = 0;
        sort(nums.begin(), nums.end());
        vector<long long> tmp;
        myMaxGapPresent(nums, k, 0, tmp);
        return maxGap;
    }

private:
    void myMaxGapPresent(const vector<long long>& nums, const long long& k, const long long& index, vector<long long>& tmp) {
        long long m = tmp.size();
        if (m == k) {
            long long tmpGap = INT_MAX;
            for (long long i = 1; i < m; ++i)
                tmpGap = min(tmpGap, tmp[i] - tmp[i - 1]);
            maxGap = max(maxGap, tmpGap);
            return;
        }

        long long n = nums.size();
        if (n <= index)
            return;

        for (long long i = index; i < n; ++i) {
            tmp.push_back(nums[i]);
            myMaxGapPresent(nums, k, i + 1, tmp);
            tmp.pop_back();
        }
    }

private:
    long long maxGap;

// -----------------------------------------------------------------------------------------------

public:
    int pathSum(vector<vector<int>> array) {
        int tmpSum = 0;
        maxSum = 0;
        directions = {{1, 1}, {1, 0}, {1, -1}};
        for (int i = 0; i < array[0].size(); ++i)
            myPathSum(array, 0, i, tmpSum);
        return maxSum;
    }

private:
    void myPathSum(const vector<vector<int>>& array, int x, int y, int tmpSum) {
        int m = array.size();
        int n = array[0].size();

        if (x < 0 || m <= x || y < 0 || n <= y)
            return;

        tmpSum += array[x][y];
        maxSum = max(maxSum, tmpSum);

        for (int i = 0; i < directions.size(); ++i) {
            int nextX = x + directions[i][0];
            int nextY = y + directions[i][1];
            myPathSum(array, nextX, nextY, tmpSum);
        }
    }

private:
    int maxSum;
    vector<vector<int>> directions;
};

void test1() {
    int m = 0;
    int n = 0;
    cin >> m >> n;

    vector<vector<int>> nums(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cin >> nums[i][j];
    }

    Solution s;
    cout << s.pathSum(nums) << endl;
}

void test2() {
    long long m = 0;
    long long k = 0;
    cin >> m >> k;

    vector<long long> nums(m);
    for (long long i = 0; i < m; ++i)
        cin >> nums[i];

    Solution s;
    cout << s.maxGapPresent(nums, k) << endl;
}

void test3() {
    int n = 0;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

//    vector<int> nums = {1, 3, 5, 7, 9, 100, 300};

    Solution s;
    cout << s.getMaxPoint(nums) << endl;
}

int main() {
//    test1();
    test2();
//    test3();
    return 0;
}