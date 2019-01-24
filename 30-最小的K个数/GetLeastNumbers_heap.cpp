#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 使用最小堆找出前k小的数字
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        } else if (k == input.size()) {
            return input;
        }

        make_heap(input.begin(), input.end(), greater<int>()); // 构造最小堆

        for (int i = 0; i < k; ++i) {
            res.push_back(input[0]);

            pop_heap(input.begin(), input.end(), greater<int>());
            input.pop_back();
        }

        return res;
    }
};