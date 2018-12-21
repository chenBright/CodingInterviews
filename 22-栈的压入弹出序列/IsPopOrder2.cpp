#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size()) {
            return false;
        }

        vector<int>::iterator top = pushV.begin();
        vector<int>::iterator popIt = popV.begin();

        while (top != pushV.end() && popIt != popV.end()) { // 将入栈序列pushV作为辅助栈
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