# 07-用两个栈实现队列

## 题目

牛客OJ：[07-用两个栈实现队列](https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P59`

## 版本1

一开始能想到的方法就是，将stack1作为**存储区**，stack2作为**临时缓冲区**。

- 入队时，将元素压入stack1。
- 出队时，将stack1逐个弹出并压入stack2中，将stack2的队头元素弹出作为出队元素，之后再将stack2剩下的元素逐个弹出并压入stack1。

```c++
#include <stack>
#include <limits.h>
using namespace std;
/**
 * 将stack1作为存储区，stack2作为临时缓冲区。
 * 入队时，将元素压入stack1。
 * 出队时，将stack1逐个弹出并压入stack2中，将stack2的队头元素弹出作为出队元素，之后再将stack2剩下的元素逐个弹出并压入stack1。 
 */
class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        // 整个队列为NULL
        if (stack1.empty()) {
            return -INT_MAX;
        }

        int queueHeadNode; // 队头元素
        while (!stack1.empty()) {
            int temp = stack1.top();
            // stack1长度为1，则此元素即为队头结点
            // 否则，不是队头元素，将其压入到stack2中
            if (stack1.size() == 1) {
                queueHeadNode = temp;
            } else {
                stack2.push(temp);
            }
            // 在stack1中弹出该元素
            stack1.pop();
        }

        // 将结点重新压入到stack1中
        while (!stack2.empty()) {
            int temp = stack2.top();
            stack2.pop();
            stack1.push(temp);
        }

        return queueHeadNode;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```

## 优化

版本1中，将stack2中的元素弹出并压回stack1，在下一次做出队操作的时候，又需要将元素从stack1弹出并压入到stack2中，这里做了很多重复工作。如果stack2的元素不需要弹出并压回stack1，就可以做少很多工作。

优化的方法：**将stack1作为输入栈，stack2作为输出栈**，stack2的元素不需要弹出并压回stack1。

- 入队时，将元素压入stack1。
- 出队时，如果stack2为空，则将stack1中的元素弹出并压入stack2，则将stack2栈顶元素作为队头元素弹出；如果stack2不为空，则将stack2栈顶元素作为队头元素弹出。

```c++
#include <stack>
#include <limits.h>
using namespace std;

/**
 * 将stack1作为输入栈，stack2作为输出栈。
 * 调用push时，将元素压入到stack1中；
 * 调用pop时，在stack2中弹出
 */ 
class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        // stack1和stack2都为空，则队列为空
        if (stack1.empty() && stack2.empty()) {
            return INT_MAX;
        }

        int queueHeadNode; // 队头元素
        // stack1、stack2不全为空
        if (stack2.empty()) {
            // stack2为空，则stack1肯定不为空
            while (!stack1.empty()) {
                int temp = stack1.top();
                // stack1长度为1，则此元素即为队头结点
                // 否则，不是队头结点，将其压入到stack2中
                if (stack1.size() == 1) {
                    queueHeadNode = temp;
                } else {
                    stack2.push(temp);
                }
                stack1.pop();
           }
        } else {
            // 输出栈stack2不为空，则直接弹出队头结点
            queueHeadNode = stack2.top();
            stack2.pop();
        }

        return queueHeadNode;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```

