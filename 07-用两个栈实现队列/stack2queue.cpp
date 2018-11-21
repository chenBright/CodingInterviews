#include <stack>
#include <limits.h>
using namespace std;

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

        int queueHeadNode; // 队头结点
        while (!stack1.empty()) {
            int temp = stack1.top();
            // stack1长度为1，则此节点即为队头结点
            // 否则，不是队头结点，将其push到stack2中
            if (stack1.size() == 1) {
                queueHeadNode = temp;
            } else {
                stack2.push(temp);
            }
            // 在stack1中删除该结点
            stack1.pop();
        }

        // 将结点重新 push 到 stack1 中
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