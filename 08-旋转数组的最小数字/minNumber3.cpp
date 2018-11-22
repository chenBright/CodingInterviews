#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int low = 0, high = rotateArray.size() - 1, mid = 0;
        bool isFind = false;
        // 如果旋转数组就是排序数组本身，则直接返回第一个元素，即令 mid = 0
        while (rotateArray[low] >= rotateArray[high]) {
            if (high - low == 1) {
                mid = high;
                break;
            }

           mid = low + (high - low) / 2;
           // rotateArray[low] rotateArray[mid] rotateArray[high]三者相等
           // 无法确定中间元素是属于前面还是后面的递增子数组
           // 则将数组两端都“往里”移动一个位置
           if (rotateArray[low] == rotateArray[mid] && rotateArray[mid] == rotateArray[high]) {
               ++low;
               --high;
           }
           // 如果该中间元素位于前面的递增子数组，那么它应该大于或者等于第一个指针指向的元素
           if (rotateArray[mid] >= rotateArray[high]) {
               low = mid; // 此时最小的元素位于中间元素的后面
           } 
           // 如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二个指针指向的元素
           else if (rotateArray[mid] <= rotateArray[low]) {
               high = mid; // 此时最小的元素位于中间元素的前面
           } 
        }

        return rotateArray[mid];
    }

private:
    int findMinInorder() {
        return 0;
    }
};