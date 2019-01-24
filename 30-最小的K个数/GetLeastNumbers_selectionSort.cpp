#include <vector>
using namespace std;

// 使用选择排序法, k趟找出前k小数字
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
            int min = i;
            for (int j = i + 1; j < input.size(); ++j) {
                if (input[j] < input[min]) {
                    min = j;
                }
            }
            if (min != i) {
                swap(&input[i], &input[min]);
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