# 21-包含min函数的栈

## 题目

牛客OJ：[21-包含min函数的栈](https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P132`

## 思路

题目的难点在于**调用min的时间复杂度是O(1)**。

首先想到的方法就是用一个变量保存当前栈中的最小值，但这种方法的问题是如果当前最小元素出栈后，如何得到下一个最小元素？

改进：一个变量不能保存足够的信息，则用一个栈来保存每一次元素入栈现场的最小值，相当于数据栈中每个元素对应着一个最小值，并且随着数据栈的更新而更新。该方法调用min的时间复杂度是**O(1)**。

## 实现

```c++
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    void push(int value) {
        if (mData.empty() || value < mMin.top()) {
            mMin.push(value);
        } else {
            mMin.push(mMin.top());
        }
        mData.push(value);
    }
    void pop() {
        assert(!mData.empty() && !mMin.empty());

        mData.pop();
        mMin.pop();
    }
    int top() {
        assert(!mData.empty() && !mMin.empty());

        return mData.top();        
    }
    int min() {
        if (mMin.empty()) {
            return 0;
        }

        return mMin.top();
    }

private:
    stack<int> mData; // 数据栈
    stack<int> mMin; // 存储每次入栈现场最小值的栈
};
```

