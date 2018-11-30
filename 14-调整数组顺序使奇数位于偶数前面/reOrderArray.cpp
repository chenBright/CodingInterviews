#include <vector>
using namespace std;

// 暴力解法：每遇见一个偶数时，就拿出这个数字，并把位于这个数字之后的所有数字往前挪动一位,然后把当前这个偶数放到最后。
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int length = array.size();
        int maxIndex = length - 1;

        if (length <= 1) {
            return;
        }

        for (int i = 0; i <= maxIndex;) {
            int temp = array[i];
            if (temp % 2 == 0) {
                moveForward(array, i, 1);
                array[length - 1] = temp;
                --maxIndex; // 最大索引减1，因为数组最后面多了一个偶数，不需要检查了
            } else {
                ++i; // 只有当前元素为奇数，才递增索引i
            }
        }
    }

private:
    // 将索引为startIndex及其后面的元素向前移动step个单位
    void moveForward(vector<int> &array, int startIndex, int step) {
        int length = array.size();

        if (step > length - 1) {
            return;
        }

        for (int i = startIndex; i < length - step; ++i) {
            array[i]= array[i + step]; 
        }
    }
};