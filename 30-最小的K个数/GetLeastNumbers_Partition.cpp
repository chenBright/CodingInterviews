#include <vector>
using namespace std;

// 基于Partition函数的O(n)的查找第K小的数
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        } else if (k >= input.size()) {
            return input;
        }

        findKth(input, 0, input.size() - 1, k - 1);
        res.assign(input.begin(), input.begin() + k);

        return res;
    }

private:
    // 在数组中找索引为k的元素
    void findKth(vector<int> &input, int low, int high, int k) {
        int index = Partition(input, low, high);

        if (index == k) {
            return;
        } else if (index < k) {
            findKth(input, index + 1, high, k);
        } else {
            findKth(input, low, index - 1, k);
        }
    }
    int Partition(vector<int> &input, int low, int high) {
        int i = low, j = high;
        int pivotNum = input[low]; // 基准元素

        while (i < j) {
            // 从后面开始找，找到第一个不大于基准元素的元素
            while (i < j && input[j] > pivotNum) {
                --j;
            }
            input[i] = input[j];

            // 从前面开始找，找到第一个大于基准元素的元素
            while (i < j && input[i] <= pivotNum) {
                ++i;
            }
            input[j] = input[i];
        }
        input[i] = pivotNum;
        return i; // 最后的位置 i == j 就是基准元素的最终位置
    }
};