# 22-栈的压入弹出序列

## 题目

牛客OJ：[22-栈的压入弹出序列](https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P134`

## 辅助栈模拟
使用一个辅助栈，模拟入栈出栈的过程。

pushV中的元素一次压入辅助栈中。

如果新压入的元素与弹出序列的栈顶相同，则辅助栈弹出元素，popV中的指针向后移动一个单位。

如果不相同，pushV中的元素继续压入辅助栈。

- 如果下一个弹出的数字刚好是栈顶数字，则直接弹出。
- 若下一个弹出的数字不在栈顶，则把压栈序列中还没有入栈的数字压入辅助栈，直到把下一个需要弹出的数字压入栈顶为止。
- 若所有的数字都压入栈了仍没有找到下一个弹出的数字，则表明该序列不可能的一个弹出序列。

```c++
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size()) {
            return false;
        }

        bool isPopOrder = true;
        vector<int>::iterator pushIt = pushV.begin();
        vector<int>::iterator popIt = popV.begin();
        stack<int> s;
        while (pushIt != pushV.end() || popIt != popV.end()) {
            if (*pushIt == *popIt) { // 元素先进栈后出栈，即可跳过该元素
                ++pushIt;
                ++popIt;
            } else if (pushIt != pushV.end()) { // 进栈
                s.push(*pushIt);
                ++pushIt;
            } else if (*popIt == s.top()) { // 栈顶元素等于将要出栈的元素，则直接出栈
                s.pop();
                ++popIt;
            } else { // 否则，不是出栈顺序
                isPopOrder = false;
                break;
            }
        }

        return isPopOrder;
    }
};
```

## 将入栈序列pushV作为辅助栈

```c++
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size()) {
            return false;
        }

        vector<int>::iterator top = pushV.begin();
        vector<int>::iterator popIt = popV.begin();

        while (top != pushV.end() && popIt != popV.end()) {
            if (*top == *popIt) {
                pushV.erase(top);
                --top;
                ++popIt;
            } else {
                ++top;
            }
        }

        return pushV.empty();
    }
};
```

