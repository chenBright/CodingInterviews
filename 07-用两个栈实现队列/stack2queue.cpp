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