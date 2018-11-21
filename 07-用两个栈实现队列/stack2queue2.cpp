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