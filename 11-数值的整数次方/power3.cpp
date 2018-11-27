class Solution {
public:
    double Power(double base, int exponent) {
        if (base == 0.0) {
            return 0.0;
        }

        if (base == 1.0 || exponent == 0) {
            return 1.0;
        }

        bool isNegative = false; // 指数是否为负数
        if (exponent < 0) {
            isNegative = true;
            exponent = -exponent;
        } 

        double result = powerNormal(base, exponent);

        // 如果指数为负数，则结果去倒数
        if (isNegative) {
            result = 1 / result;
        }

        return result;
    }

private:
    double powerNormal(double base, int exponent) {
        if (exponent == 0) {
            return 1;
        }
        if (exponent == 1) {
            return base;
        }

        double result = powerNormal(base, exponent / 2);
        result *= result;
        // 指数为奇数
        if (exponent % 2) {
            result *= base;
        }

        return result;
    }
};