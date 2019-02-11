# 52-构建乘积数组

## 题目

牛客OJ：[52-构建乘积数组](https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

## 思路

将球***b[i]***分成两部分：

1. ***A[0]A[1]...A[i-1]***，从头开始遍历，可以***累乘***，减少重复的乘法操作。
2. ***A[i+1]...A[n-1]***，从尾开始遍历，可以***累乘***，减少重复的乘法操作。

```c++
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> res(len);
        for (int i = 0, temp = 1; i < len; ++i) {
            res[i] = temp;
            temp *= A[i];
        }

        for (int j = len - 1, temp = 1; j >= 0; --j) {
            res[j]]] *= temp;
            temp *= A[j];
        }

        return res;
    }
};
```

