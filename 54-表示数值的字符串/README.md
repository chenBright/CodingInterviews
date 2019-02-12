# 54-表示数值的字符串

## 题目

牛客OJ：[54-表示数值的字符串](https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2?tpId=13&tqId=11206&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

## 思路

需要考虑的问题：

1. 首先看第一个字符是不是正负号。
2. 如果是，在字符串上移动一个字符，继续扫描剩余的字符串中0到9的数位。
3. 如果是一个小数，则将遇到小数点。
4. 另外，如果是用科学计数法表示的数值，在整数或者小数的后面还有可能遇到’e’或者’E’。

```c++
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
```

