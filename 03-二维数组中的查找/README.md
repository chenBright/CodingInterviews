# 03-二维数组中的查找

## 题目

牛客OJ：[03-二维数组中的查找](http://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

《剑指offer》：`P38`

## 暴力解法

暴力解法，就是遍历每个元素，看是否存在需要查找的数字。

```c++
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool isFind = false;
        for (int i = 0; i < array.size(); ++i) {
            for (int j = 0; j < array[i].size(); ++j) {
                if (array[i][j] == target) {
                    isFind = true;
                }
            }
        }
        return isFind;
    }
};
```

## 二分查找解法（分治）

根据二分查找的思想，我们选择矩阵的“中心“元素，和需要查找的数字比较。比较的结果有三种：

1. 两个数字相等，则查找成功。
2. 矩阵”中心“元素比需要查找的数字小，则需要查找的数字可能在当前位置的右边或者下边。
3. 矩阵”中心“元素比需要查找的数字大，则需要查找的数字可能在当前位置的左边或者上边。

但是这个方法存在区域重叠的问题，比如右边或下边会在右下角有重叠部分。

解决方法：约定好，继续查找时，一边包含重叠部分，另一边则不包含即可。比如，右边或下边会在右下角有重叠部分，右边包含重叠部分，下边则不包含。

```c++
// 使用二分查找的思想查找
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool isFind = false;
        int rows = array.size();
        int cols = array[0].size();
        isFind = Find(target, array, 0, rows - 1, 0, cols - 1);

        return isFind;
    }
private:
    bool Find(int target, vector<vector<int> > array, int lowRow, int highRow, int lowCol, int highCol) {
        if (lowCol > highCol || lowRow > highRow) {
            return false;
        }

        int i = lowRow + (highRow - lowRow) / 2;
        int j = lowCol + (highCol - lowCol) / 2;
        if (target == array[i][j]) {
            return true;
        } else if (target < array[i][j]) {
            // 查找左边和上边
            return Find(target, array, lowRow, highRow, lowCol, j - 1) || Find(target, array, lowRow, i - 1, j, highCol);
        } else {
            // 查找右边和下边
            return Find(target, array, lowRow, highRow, j + 1, highRow) || Find(target, array, i + 1, highRow, lowCol, j);
        }
    }
};
```

## 从右上角（左下角）的元素出发查找（分治）

《剑指offer》中有一句话说得很好：”当我们需要解决一个复杂的问题时，一个有效的办法就是从一个具体的问题入手，通过分析简单具体的例子，视图寻找普遍的规律“。这是一个很好的解决问题的方法。《剑指offer》解析的非常详细，详细解析可以看书`P39`。

### 从右上角的元素出发查

```c++
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool isFind = false;
        int rows = array.size();
        int cols = array[0].size();
        
        /**
         * 从右上角开始查找
         * 如果查找的元素比当前位置的元素小，则向左查找
         * 如果查找的元素比当前位置的元素大，则向下查找
         */
        int curRow = 0;
        int curCol = cols - 1;
        while ((curRow >= 0 && curRow < rows) && (curCol >= 0 && curCol < cols)) {
            if(target == array[curRow][curCol]) {
                isFind = true;
                break;
            } else if (target < array[curRow][curCol]) {
                --curCol;
            } else {
                ++curRow;
            }
        }

        return isFind;
    }
};
```

### 从左下角的元素出发查

```c++
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool isFind = false;
        int rows = array.size();
        int cols = array[0].size();
        
        /**
         * 从左下角开始查找
         * 如果查找的元素比当前位置的元素小，则向上查找
         * 如果查找的元素比当前位置的元素大，则向右查找
         */
        int curRow = rows - 1;
        int curCol = 0;
        while ((curRow >= 0 && curRow < rows) && (curCol >= 0 && curCol < cols)) {
            if(array[curRow][curCol] == target) {
                isFind = true;
                break;
            } else if (array[curRow][curCol] > target) {
                --curRow;
            } else {
                ++curCol;
            }
        }

        return isFind;
    }
};
```

