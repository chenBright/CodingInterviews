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