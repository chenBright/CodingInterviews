#include <vector>
using namespace std;

// 分治
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty()) {
            return 0;
        }

        return maxSum(array, 0 ,array.size() - 1);
    }

private:
    int maxSum(vector<int> &array, int left, int right) {
        if (left == right) {
            return array[left];
        }

        int center = (left + right) / 2;
        int maxLeftSum = maxSum(array, left, center); // 计算左半部分最大子段和
        int maxRightSum = maxSum(array, center + 1, right); // 计算右半部分最大子段和

        /**
         * 计算包含中间，同时涉及到左右两部分的最大子段和
         */
        int maxLeftBorderSum = array[center], leftBorderSum = 0;
        for (int i = center; i >= left; --i) {
            leftBorderSum += array[i];
            if (leftBorderSum > maxLeftBorderSum) {
                maxLeftBorderSum = leftBorderSum;
            }
        }

        int maxRightBorderSum = array[center + 1], rightBorderSum = 0;
        for (int j = center + 1; j <= right; ++j) {
            rightBorderSum += array[j];
            if (rightBorderSum > maxRightBorderSum) {
                maxRightBorderSum = rightBorderSum;
            }
        }

        return max(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
    }

    int max(int n, int m, int l) {
        int max;
        max = n > m ? n : m;
        if (l > max) {
            max = l;
        }

        return max;
    }
};