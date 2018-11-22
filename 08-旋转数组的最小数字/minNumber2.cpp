#include <vector>
using namespace std;

// 遍历所有元素，找到第一个小于前一个数以及小于等于后一个数的数，此数即为最小值
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int isFindMin = false;
        int minIndex = 0;
        size_t length = rotateArray.size();
        for (size_t i = 1; i < length - 1; ++i) {
            if (rotateArray[i] < rotateArray[i - 1] && rotateArray[i] <= rotateArray[i + 1]) {
                minIndex = i;
                break;
            }
        }
        return rotateArray[rotateArray.size()] < rotateArray[minIndex] ? rotateArray[rotateArray.size()] : rotateArray[minIndex];
    }
};