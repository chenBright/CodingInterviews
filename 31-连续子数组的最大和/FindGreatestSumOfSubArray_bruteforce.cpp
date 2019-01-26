#include <vector>
using namespace std;

// 暴力破解
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty()) {
            return 0;
        }
        
        int max = array[0]; // 最大和

        int arrayLen = array.size();
        for (int i = 0; i < arrayLen; ++i) {
            int sum = 0;
            for (int j = i; j < arrayLen; ++j) {
                sum += array[j];

                if (sum > max) {
                    max = sum;
                }
            }
        }

        return max;
    }
};