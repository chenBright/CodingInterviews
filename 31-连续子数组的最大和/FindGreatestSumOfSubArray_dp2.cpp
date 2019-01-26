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
        int sum = 0;

        int arrayLen = array.size();
        for (int i = 0; i < arrayLen; ++i) {
            sum += array[i];
            if (sum > max) {
                max = sum;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        return max;
    }
};