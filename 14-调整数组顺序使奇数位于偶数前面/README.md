# 14-调整数组顺序使奇数位于偶数前面

## 题目

牛客OJ：[14-调整数组顺序使奇数位于偶数前面](https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P103`

## 暴力解法

每遇见一个偶数时，就拿出这个数字，并把位于这个数字之后的所有数字往前挪动一位,然后把当前这个偶数放到最后。这种方法的时间复杂度为**O(n)**。

```c++
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
```

## 冒泡解法

暴力解法太粗暴了，而且需要大量移动元素的工作。下面这种方法是利用**冒泡排序**的思想，但与冒泡排序不同的是，这种方法不是比较大小，而是**前偶后奇就交换**。这种方法的平均时间复杂度也是**O(n^2)**，但最好情况下的时间复杂度是**O(n)**。

```c++
#include <vector>
using namespace std;

// 冒泡解法：每次循环前偶后奇就交换
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int length = array.size();

        if (length <= 1) {
            return;
        }
        
        bool isSwap = false;
        for (int i = 0; i < length; ++i) {
            isSwap = false;
            for (int j = length - 1; j > i; --j) {
                // 前偶后奇交换
                if (!isEven(array[j]) && isEven(array[j - 1])) {
                    swap(array, j, j - 1);
                    isSwap = true;
                }
            }
            // 没有交换过，则表示数组以满足前奇后偶的条件
            if (!isSwap) {
                break;
            }
        }
    }

private:
    // number是否是偶数
    bool isEven(int number) {
        return number % 2 == 0;
    }
    
    // 交换数组元素
    void swap(vector<int> &array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
};
```

## 辅助数组解法

有一种降低时间复杂度的方法，就是**用空间换时间**。可以用一个辅助数组来保存所有偶数，同时在原数组中将偶数删除。最后，将辅助数组中的偶数添加到原数组末尾。这种方法的时间复杂度**O(n)**。

```c++
#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.size() <= 1) {
            return;
        }
        vector<int> arrayTemp;
        vector<int>::iterator ib1, ie1;
        ib1 = array.begin();

        while (ib1 != array.end()) {
            if (*ib1 % 2 == 0) {
                arrayTemp.push_back(*ib1);
                ib1 = array.erase(ib1);
            } else {
                ++ib1;
            }
        }

        vector<int>::iterator ib2, ie2;
        ib2 = arrayTemp.begin();
        ie2 = arrayTemp.end();

        while (ib2 != ie2) {
            array.push_back(*ib2);
            ++ib2;
        }
    }
};
```

## 高效但不稳定的解法

1. 维护两个索引或者指针，一个指向数组的第一个元素，并向后移动，一个指向数组的最后一个元素，并向前移动。

2. 如果第一个指针指向的元素是偶数，而第二个指针指向的元素是奇数，说明偶数在奇数前面，那么就交换这两个数。

3. 直到两个指针相遇为止。

不能保证相同类型数据的相对位置不变，因此不稳定

```c++
#include <vector>
using namespace std;

/**
 * 维护两个索引或者指针，一个指向数组的第一个元素，并向后移动，一个指向数组的最后一个元素，并向前移动。
 * 如果第一个指针指向的元素是偶数，而第二个指针指向的元素是奇数，说明偶数在奇数前面，那么就交换这两个数。
 * 直到两个指针相遇为止 
 * 但不能保证相同类型数据的相对位置不变，因此不稳定
 */
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.size() <= 1) {
            return;
        }

        vector<int>::iterator left = array.begin();
        vector<int>::iterator right = array.end() - 1;

        while (left < right) {
            // left向后移动指向第一个偶数
            while (left < right && *left % 2 == 1) {
                ++left;
            }
            // right向前移动指向第一个奇数
            while (left < right && *right % 2 == 0) {
                --right;
            }

            if (left < right) {
                swap(left, right);
            }
        }        
    }

private:
    // 交换数组元素
    void swap(vector<int>::iterator i, vector<int>::iterator j) {
        int temp = *i;
        *i = *j;
        *j = temp;
    }
};
```