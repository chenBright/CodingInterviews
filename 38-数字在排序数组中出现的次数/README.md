# 38-数字在排序数组中出现的次数

## 题目

牛客OJ：[38-数字在排序数组中出现的次数](https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)


《剑指offer》：`P182`

## 暴力破解
遍历数组，找出第一个和最后一个等于k的元素，根据它们的索引号即可求出数字的个数。

该方法的时间复杂度为**O(n)**。

```c++
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int dataLength = data.size();
        if (dataLength == 0) {
            return 0;
        }

        int i;
        for (i = 0; i < dataLength && data[i] != k; ++i); // 找到第一个等于k的元素

        int j;
        for (j = i; j < dataLength && data[j] == k; ++j); // 找到第一个右边第一个不等于k的元素

        return j - i;
    }
};
```

## 二分查找

使用二分查找找出第一个和最后一个等于k的元素。

该方法的时间复杂度为**O(logn)**。

```c++
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int count = 0;
        if (!data.empty()) {
            int first = binarySearch_firstK(data, 0, data.size() - 1, k);
            int last = binarySearch_firstK(data, 0, data.size() - 1, k);

            if (first != -1 && last != -1) {
                count = last - first + 1;
            }
        }

        return count;
    }

private:
    // 二分查找第一个等于k的元素
    int binarySearch_firstK(vector<int> &data, int low, int high, int k) {
        if (low > high) {
            return -1;
        }        

        int mid = (low + high) / 2;
        if (data[mid] == k) {
            if ((mid > 0 && data[mid - 1] != k) || mid == 0) {
                return mid;
            } else {
                high = mid - 1;
            }
        } else if (data[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }

        return binarySearch_firstK(data, low, high, k);
    }

    // 二分查找最后一个等于k的元素
    int binarySearch_lastK(vector<int> &data, int low, int high, int k) {
        if (low > high) {
            return -1;
        }        

        int mid = (low + high) / 2;
        if (data[mid] == k) {
            if ((mid < data.size() - 1 && data[mid + 1] != k) || mid == data.size() - 1) {
                return mid;
            } else {
                low = mid + 1;
            }
        } else if (data[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }

        return binarySearch_lastK(data, low, high, k);
    }
};
```

## stl中的二分查找

该方法的时间复杂度为**O(logn)**。

```c++
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int count = 0;
        if (!data.empty()) {
            auto first = lower_bound(data.begin(), data.end(), k); // 返回一个非递减序列[first, last]中的第一个大于等于值val的指针
            auto upper = upper_bound(data.begin(),data.end(),k); // 返回一个非递减序列[first, last]中第一个大于val的指针

            count = upper - first;
        }

        return count;
    }
};
```

