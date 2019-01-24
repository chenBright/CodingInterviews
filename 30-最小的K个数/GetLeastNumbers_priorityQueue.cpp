#include <vector>
#include <queue>
#include <functional>
using namespace std;

// 使用优先队列找出前k小的数字
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        } else if (k == input.size()) {
            return input;
        }

        priority_queue<int, vector<int>, greater<int> > pq(input.begin(), input.end()); // 构造最小值优先队列


        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};