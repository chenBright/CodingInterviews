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

        bool isOdd = false;
        if (exponent % 2) {
            isOdd = true;
        }

        double result = base;
        for (int i = 0; i < exponent / 2; ++i) {
            result *= result;
        }

        if (isOdd) {
            result *= base;
        }

        if (isNegative) {
            result = 1 / result;
        }

        return result;
    }
};