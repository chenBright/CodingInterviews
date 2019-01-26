#include <vector>
using namespace std;

// 动态规划
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty()) {
            return 0;
        }

        int max = array[0]; // 最大和

        int arrayLen = array.size();
        for (int i = 0, j; i < arrayLen; i = j + 1) {
            int sum = 0;
            for (j = i; j < arrayLen; ++j) {
                sum += array[j];

                if (sum > max) {
                    max = sum;
                }

                // sum是负数的话，就不需要累加，子段从头开始
                if (sum < 0) {
                    break;
                }
            }
        }

        return max;
    }
};