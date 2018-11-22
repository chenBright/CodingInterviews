# 08-旋转数组的最小数字

## 题目

牛客OJ：[08-旋转数组的最小数字](https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P66`

## 遍历

遍历每个元素，记录当前遍历过的元素中最小的元素。当遍历完数组中所有元素之后，就能找到最小的元素。

```c++
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
```



另一种方法就是利用旋转数组的规律，除了最小元素位于两端，否则最小元素位于数组中间，则最小元素比它两边的元素都要小。

```c++
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int isFindMin = false;
        int minIndex = 0; // 默认第一个元素为最小元素
        size_t length = rotateArray.size();
        for (size_t i = 1; i < length - 1; ++i) {
            if (rotateArray[i] < rotateArray[i - 1] && rotateArray[i] <= rotateArray[i + 1]) {
                minIndex = i;
                break;
            }
        }
        // 检查最后一个元素是否为最小元素
        return rotateArray[rotateArray.size()] < rotateArray[minIndex] ? rotateArray[rotateArray.size()] : rotateArray[minIndex];
    }
};
```

以上两种方法的时间复杂度都为**O(n)**。

## 二分查找

既然是查找的问题，当然不能忘记**二分查找**啊。详细见《剑指offer》。我的方法有一点跟书上的不一样：当rotateArray[low]、rotateArray[mid]、rotateArray[high]三者相等时，由于无法确定中间元素是属于前面还是后面的递增子数组，则将数组两端都“往里”移动一个位置，即**++low、--high**。这样就可以继续使用二分查找，而不需要使用顺序查找了。

```c++
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
};
```

