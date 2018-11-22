#include <vector>
using namespace std;

// 遍历所有元素，最初最小的值
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int min = rotateArray[0];
        size_t length = rotateArray.size();
        for (size_t i = 1; i < length; ++i) {
            if (rotateArray[i] < min) {
                min = rotateArray[i];
            }
        }
        return min;
    }
};