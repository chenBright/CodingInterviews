# 42-翻转单词顺序列

## 题目

牛客OJ：[42-翻转单词顺序列](https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=3)


《剑指offer》：`P218`

## 思路
1. 将整个句子的所有字符翻转。
2. 翻转每个单词。

## 使用翻转函数

```c++
class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty()) {
            return str;
        }

        Reverse(str, 0, str.size() - 1);

        int left = 0;
        int right = 0;
        while ((right <= str.size())) {
            //  当遇见空格的时候说明找到了一个单词
            //  当走到字符串的最后一个位置, 那么前面如果不是空格, 那么最后也会有一个单词
            if((str[right] == ' ') || (right == str.size() && str[right - 1] != ' ')) {
                Reverse(str, left, right - 1);
                left = right + 1;
            }
            right++;
        }

        return str;
    }

private:
    void Reverse(string &str, int left, int right) {
        while (left < right) {
            swap(str[left++], str[right--]);
        }
    }
};
```

## STL翻转函数

```c++
class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty()) {
            return str;
        }

        reverse(str.begin(), str.end());

        size_t left = 0;
        size_t right = 0;
        while(right != string::npos){
            left = str.find_first_not_of(' ', left); // 第一个非空格字符是单词的起始位置
            right = str.find_first_of(' ', left); // 第一个空格位置标识了单词的结束

            //  处理末尾是空格(原字符串开头是空格的情况)
            //  当最后全是空格的时候，此时可以结束循环
            if (left == string::npos) {
                break;
            }
            //  如果查找不到空格, 到了字符串的末尾
            //  此时[degin, str.size( )]是末尾的字符串
            if (right == string::npos) {
                reverse(str.begin( ) + left, str.end( ));
            } else { // 否则[left, end]是一个单词
                reverse(str.begin( ) + left, str.begin() + right);
                left = right + 1;
            }
        }

        return str;
    }
};
```

## 使用栈先进后出的特点实现翻转

```c++
class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty()) {
            return str;
        }

        string res;
        stack<char> stack1;
        stack<char> stack2;

        for (int i = 0; i < str.size(); ++i) {
            stack1.push(str[i]);
        }

        /**
         * 通过将字符串压入栈中, 现在出栈顺序正好是入展顺序的逆序
         * 即我们实现了一次整个字符串的翻转
         * 接下来我们翻转每个单词
         * 只要不是空格就一直入栈(实现翻转)
         * 遇见空格的时候，就读取栈中元素(出栈的顺序正好是每个单词的顺序)
         */
        while (!stack1.empty()) {
            char c = stack1.top();
            if (c != ' ') {
                stack2.push(c);
            } else {
                while (!stack2.empty()) {
                    res += stack2.top();
                    stack2.pop();
                }
                res += ' ';
            }
            stack1.pop();
        }

        // 此时stackk1已经空了 上面的循环进不去了 但是stack2中还有最后一个单词
        while (!stack2.empty()) {
            res += stack2.top();
            stack2.pop();
        }

        return res;
    }
};
```

