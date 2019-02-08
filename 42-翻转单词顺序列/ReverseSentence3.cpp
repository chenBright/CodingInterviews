#include <string>
#include <stack>
using namespace std;

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