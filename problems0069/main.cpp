#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt1(int x) {
        int left = 0;
        int right = x;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long tmp = mid * mid;

            if (tmp == x)
                return mid;
            else if (tmp < x)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return right;
    }

    // 二分
    double mySqrt2(int x) {
        double left = 0;
        double right = x;

        while (left <= right) {
            double mid = left + (right - left) / 2;
            double tmp = mid * mid;

            if (tmp == x)
                return mid;
            else if (tmp < x)
                left = mid + 0.0000000001;
            else
                right = mid - 0.0000000001;
        }

        return right;
    }

    // 牛顿
    double mySqrt3(int x) {
        if (x == 0)
            return 0;

        double prev = x;
        while (true) {
            double next = (prev + x / prev) / 2;
            if (next * next - x < 1e-10)
                return next;
            prev = next;
        }

        return -1;
    }

    double mySqrt(int x) {
        double left = 0;
        double right = x;

        while (left <= right) {
            double mid = left + (right - left) / 2;
            double pow = mid * mid;

            if (pow == x)
                return mid;
            else if (pow < x)
                left = mid + 0.0000000001;
            else
                right = mid - 0.0000000001;
        }

        return right;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    double out = s.mySqrt(2);
    printf("%.10f\n", out);
    cout << "---------------------" << endl;
    return 0;
}