# 49-把字符串转换成整数

## 题目

牛客OJ：[49-把字符串转换成整数](https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)


《剑指offer》：`P244`

## 思路
需要考虑的问题：

- 字符串以空格开始
- 数字前的正负号
- 溢出
- 非法输入

```c++
class Solution {
public:
    int StrToInt(string str) {
        int strLength = str.length();
        int i = 0;
        while (str[i] == ' ' && i < strLength) {
            ++i;
        }

        bool isMinus = false;
        if (str[i] == '+') {
            ++i;
        } else if (str[i] == '-') {
            isMinus = true;
            ++i;
        }

        long long int value = 0;
        while (str[i] >= '0' && str[i] <= '9' && i < strLength) {
            value = value * 10 + (str[i++] - '0');

            /**
             * 解决OVER_FLOW的问题
             * INT_MAX     2147483647
             * INT_MIN     -2147483648  isMinus = true
             */
            if((isMinus == true  && value > (unsigned long)(INT_MAX) + 1)     //  负数绝对值最大为INT_MAX + 1
            || (isMinus == false && value > INT_MAX)) {                       //  正数最大值为INT_MAX
                break;
            }
        }

        // 非法输入
        if (i < strLength) {
            return 0;
        } else {

            if (isMinus == true) {
                value = -value;
            }

            // 溢出
            if (value >= INT_MAX) {
                value = INT_MAX;
            }
            else if (value <= INT_MIN) {
                value = INT_MIN;
            }

            return (int)value;
        }
    }
};
```

