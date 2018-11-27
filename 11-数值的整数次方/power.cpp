class Solution {
public:
    double Power(double base, int exponent) {
        if (base == 0.0) {
            return 0.0;
        }

        if (base == 1.0 || exponent == 0) {
            return 1.0;
        }

        bool isNegative = false;
        if (exponent < 0) {
            isNegative = true;
            exponent = -exponent;
        }

        double result = 1.0;
        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }

        if (isNegative) {
            result = 1 / result;
        }

        return result;
    }
};