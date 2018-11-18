# 04-替换空格

## 题目

牛客OJ：[04-替换空格](https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P44`

## O(n^2) 方法

最容易想到，而且非常暴力的方法，就是遍历字符串，每遇到一个空格，将空格后面所有的字符后移`两位`，预留出位置将空格替换成`%20`（空格+后移的两位，一个三位）。

```c++
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int indexLen = length - 1;
        // 从后往前遍历
        for (int i = length - 1; i >= 0; --i) {
            if (str[i] == ' ') {
                indexLen += 2; // 从空格变成%20长度增加了2

                int j;
                for (j = indexLen; j > i + 2; --j) {
                    str[j] = str[j - 2];
                }
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
        }
        str[indexLen + 1] = '\0';
	}
};
```

遍历字符串的时间复杂度为O(n)，对于每个空格，移位的时间复杂度为O(n)，所以总的时间复杂度为O(n^2)。

## O(n) 方法

前面的方法太暴力了，效率不高。时间主要消耗在，字符串的移动上，如果有多个空格，前面替换空格的字符串需要多次移位，从而导致了复杂度的上升。

现在知道了问题所在了，那么有没有办法解决呢？如果能确定每次替换空格时，能确定后面字符串的最终位置，每个字符最多只需要移一次位，则可以将复杂度降下来。

因此，我们**先遍历一次字符串，统计空格的总数，从而确定替换后字符串的长度。然后从后向前遍历字符串，遍历到空格，则移位；不是空格，则直接复制**。

```c++
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int len = length;

        // 先统计空格的总数 => 确定替换后的字符串的长度
        for (int i = 0; i < length; ++i) {
            if (str[i] == ' ') {
                len += 2; // 从空格变成%20长度增加了2
            }
        }

        // 从后向前遍历替换
        for (int i = length - 1, j = len - 1; i >= 0 && j>= 0; --i) {
            if (str[i] != ' ') { // 不是空格，直接复制
                str[j--] = str[i];
            } else { // 空格，移位
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
        }
        str[len] = '\0';
	}
};
```

先对问题预处理，简化问题。后面每个字符只需要复制一次，所以时间复杂度为O(n)。