#include <iostream>

class Solution {
public:
    bool isNumeric(char* str) {
        if (str == NULL) {
            return false;
        }

        // 正负号
        if (*str == '+' || *str == '-') {
            ++str;
        }

        if (*str == '\0') {
            return false;
        }

        bool isNum = true;
        ScanDigits(&str);
        
        if (*str != '\0') {
            if (*str == '.') {
                ++str;
                ScanDigits(&str);

                if (*str == 'e' || *str == 'E') {
                    isNum = IsExponential(&str);
                }
            } else if (*str == 'e' || *str == 'E') {
                isNum = IsExponential(&str);
            } else {
                isNum = false;
            }
        }

        return isNum && *str == '\0';
    }

private:
    void ScanDigits(char **str) {
        while (**str != '\0' && (**str >= '0' && **str <= '9')) {
            ++(*str);
        }
    }

    bool IsExponential(char **str) {
        if (**str != 'e' && **str != 'E') {
            return false;
        }

        ++(*str);

        if (**str == '+' || **str == '-') {
            ++(*str);
        }

        if (**str == '\0') {
            return false;
        }

        ScanDigits(str);

        return **str == '\0' ? true : false;
    }

};