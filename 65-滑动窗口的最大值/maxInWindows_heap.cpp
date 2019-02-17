#include <vector>
#include <queue>
using namespace std;

class Solution {
    typedef pair<int, int> Pair;

public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        priority_queue<Pair> Q;

        if (num.empty() || size == 0) {
            return res;
        }

        int length = num.size();

        for (int i = 0; i < size - 1; ++i) {
            Q.push(Pair(num[i], i));
        }

        for (int j = size - 1; j < length; ++j) {
            Q.push(Pair(num[j], j));
            Pair p = Q.top();
            // 如果最大堆的堆顶元素不在窗口内，将其弹出，重新去堆顶元素
            while (p.second < j - (size - 1)) {
                Q.pop();
                p = Q.top();
            }
            res.push_back(p.first);
        }

        return res;
    }
};