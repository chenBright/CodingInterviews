#include <vector>
#include <stack>
using namespace std;

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