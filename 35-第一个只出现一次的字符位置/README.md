# 35-第一个只出现一次的字符位置

## 题目

牛客OJ：[35-第一个只出现一次的字符位置](https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P186`

## 思路

1. 遍历字符串，记录每个字符出现的次数。
2. 遍历字符串，查找第一个只出现一次的字符，并返回其位置。

## 使用map记录字符出现次数

步骤1的时间复杂度为**O(n)**。步骤2中，遍历字符串的时间复杂度为**O(n)**，map底层是用红黑树实现的，查找字符的时间复杂度为**O(logn)**，步骤1的时间复杂度为**O(nlogn)**。

该方法的时间复杂度为**O(nlogn)**。

```c++
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty()) {
            return -1;
        }

        map<char, int> cmap;

        for (int i = 0; i < str.length(); ++i) {
            if (cmap.count(str[i])) {
                ++cmap[str[i]];
            } else {
                cmap[str[i]] = 1;
            }
        }

        for (int i = 0; i < str.length(); ++i) {
            if (cmap[str[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
```

## 使用哈希表记录字符出现的次数

哈希表查找字符的时间复杂度为**O(1)**，所以该方法的时间复杂度为**O(n)**。

### 使用数组构建简单的哈希表

```c++
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty()) {
            return -1;
        }

        // 简单的哈希表
        const int tableSize = 256;
        int count[tableSize] = {0};

        for (int i = 0; i < str.length(); ++i) {
            ++count[str[i]];
        }

        for (int i = 0; i < str.length(); ++i) {
            if (count[str[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
```

### 使用底层实现是哈希表的unordered_map

```c++
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty()) {
            return -1;
        }

        unordered_map<char, int> cmap;

        for (int i = 0; i < str.length(); ++i) {
            if (cmap.count(str[i])) {
                ++cmap[str[i]];
            } else {
                cmap[str[i]] = 1;
            }
        }

        for (int i = 0; i < str.length(); ++i) {
            if (cmap[str[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
```

