#include <vector>
using namespace std;

// 使用冒泡排序法, k趟找出前k小数字
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        } else if (k == input.size()) {
            return input;
        }

        for (int i = 0; i < k; ++i) {
            for (int j = input.size() - 1; j > i; --j) {
                if (input[j] < input[j - 1]) {
                    swap(&input[j], &input[j - 1]);
                }
            }
            res.push_back(input[i]);
        }

        return res;
    }

private:
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};