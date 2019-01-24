#include <vector>
#include <algorithm>
using namespace std;

// 先排序，再找出前k小的数字
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        } else if (k == input.size()) {
            return input;
        }

        sort(input.begin(), input.end()); // 排序
        res.assign(input.begin(), input.begin() + k); // 复制

        return res;
    }
};